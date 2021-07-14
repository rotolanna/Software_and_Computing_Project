#include "Reconstruction.h"


using namespace std;

ClassImp(Reconstruction);

void Reconstruction::Fill_all_rec(TRandom2  *casos, EVENTO_STRUCT  *pevstr, ALLTRACK_STRUCT tra2[max_tra_ev], int      index_tracks[max_tra_ev],  int      ntracks_per_event, TFile  *f_out, double par[11], ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]){
	
	
	       Fill_tracks_detector(pevstr, tra2, index_tracks, ntracks_per_event);
	       
	       Smearing(casos, pevstr, tra2,index_tracks, ntracks_per_event, par);
	       
	       Bethebloch(tra2, ntracks_per_event);
	       
	       Measure_A(tra2, ntracks_per_event, tra_frag);
	
	       Fill_histo_tracks(f_out, tra2, ntracks_per_event);
	
}

void       Reconstruction::Fill_tracks_detector(EVENTO_STRUCT *pevstr, ALLTRACK_STRUCT tra2[max_tra_ev], int      index_tracks[max_tra_ev], int      ntracks_per_event){
	
  int   pointerstc        = -1;
  int   pointervtx        = -1;
  int   pointerIT         = -1;
  int   pointer2dc        = -1;
  int   pointerscint      = -1;
  int   pointercalo       = -1;
  
  npti = -1;
  current_track = -1; 


  for(int a = 0; a <= ntracks_per_event; a++) {
  
  tra2[a].detect.npoint = -1;
  
    if(a  >= max_tra_ev ) break;
    
    current_track = a;


  tra2[current_track].detect.start_time  = pevstr->TRtime[index_tracks[current_track]]*1E+09;

  for(int isc=0;isc< pevstr->STCn;isc++){               // Start Counter
    pointerstc = pevstr->STCid[isc]-1;;
    if(pointerstc == index_tracks[current_track]) {
      tra2[current_track].detect.start_time_sc = pevstr->STCtim[isc]*1E+09; //in ns
     
    }
  }

  int indvtx = -1;
  for(int i=0;i<pevstr->VTXn;i++){                    //Vertex, 
                                                      // loop on vtxn, # of energy release in vtx, when a track is fixed
    pointervtx = pevstr->VTXid[i]-1;
    if(pointervtx ==index_tracks[current_track] && npti < max_points) {
      npti++;
      indvtx++;
      tra2[current_track].tr.pt[npti].x                       = pevstr->VTXxin[i];    
      tra2[current_track].tr.pt[npti].y                       = pevstr->VTXyin[i];    
      tra2[current_track].tr.pt[npti].z                       = pevstr->VTXzin[i]; 
      tra2[current_track].tr.pt[npti].time                    = pevstr->VTXtim[i]; 
      
      tra2[current_track].detect.vtx_x                        = pevstr->VTXxin[i];    
      tra2[current_track].detect.vtx_y                        = pevstr->VTXyin[i];    
      tra2[current_track].detect.vtx_z                        = pevstr->VTXzin[i];  
      tra2[current_track].detect.E_depo_vtx                  += pevstr->VTXde[i];
      if(indvtx == 0) tra2[current_track].detect.time_vertex    = pevstr->VTXtim[i]*1E+09; //Fixed track, ToF start in the vtx first point of interaction 
    }                                                                                    
  }
  
 
   for(int j=0;j<pevstr->ITRn;j++){                   // Inner Tracker
    pointerIT = pevstr->ITRid[j]-1;
    if(pointerIT ==index_tracks[current_track] && npti < max_points) {
      npti++;
      tra2[current_track].tr.pt[npti].x               = pevstr->ITRxin[j];    
      tra2[current_track].tr.pt[npti].y               = pevstr->ITRyin[j];    
      tra2[current_track].tr.pt[npti].z               = pevstr->ITRzin[j]; 
      tra2[current_track].tr.pt[npti].time            = pevstr->ITRtim[j]; 
      
      tra2[current_track].detect.x_inner_in              = pevstr->ITRxin[j];    
      tra2[current_track].detect.y_inner_in              = pevstr->ITRyin[j];  
	  tra2[current_track].detect.z_inner_in              = pevstr->ITRzin[j];   
      tra2[current_track].detect.E_depo_itr             += pevstr->ITRde[j];
    }
  }
 
 
tra2[current_track].detect.E_depo_msd  = 0.;  // Micro Strip Detector
  for(int k=0;k<pevstr->MSDn;k++){         
    pointer2dc = pevstr->MSDid[k]-1;
    if(pointer2dc ==index_tracks[current_track] && npti < max_points) {
      npti++;
      tra2[current_track].tr.pt[npti].x                = pevstr->MSDxin[k];    
      tra2[current_track].tr.pt[npti].y                = pevstr->MSDyin[k];    
      tra2[current_track].tr.pt[npti].z                = pevstr->MSDzin[k]; 
      tra2[current_track].tr.pt[npti].time             = pevstr->MSDtim[k]; 
      
      tra2[current_track].detect.msd_x_in              = pevstr->MSDxin[k];    
      tra2[current_track].detect.msd_y_in              = pevstr->MSDyin[k];    
      tra2[current_track].detect.msd_z_in              = pevstr->MSDzin[k]; 
      tra2[current_track].detect.E_depo_msd           += pevstr->MSDde[k]; 
    }
  } 
 
 
//Sum of all E_release in vtx, msd and inner tracker
 tra2[current_track].detect.E_depo_tracker            = (tra2[current_track].detect.E_depo_vtx +  tra2[current_track].detect.E_depo_itr + tra2[current_track].detect.E_depo_msd);


int indscn = -1;
  tra2[current_track].detect.E_depo_scint          = 0.;   // scint
  for(int l=0;l<pevstr->SCNn;l++){        
    pointerscint = pevstr->SCNid[l]-1;
    if(pointerscint ==index_tracks[current_track] && npti < max_points) {
      indscn++;
      npti++;
      tra2[current_track].tr.pt[npti].x                          = pevstr->SCNxin[l];    
      tra2[current_track].tr.pt[npti].y                          = pevstr->SCNyin[l];    
      tra2[current_track].tr.pt[npti].z                          = pevstr->SCNzin[l]; 
      tra2[current_track].tr.pt[npti].time                       = pevstr->SCNtim[l]; 
      
      tra2[current_track].detect.sc_x                            = pevstr->SCNxin[l];    
      tra2[current_track].detect.sc_y                            = pevstr->SCNyin[l];    
      tra2[current_track].detect.sc_z                            = pevstr->SCNzin[l]; 
      //if (pevstr->SCNiview[l] == 0) first scintillator layer condition 
	  
	                                                        
	  tra2[current_track].detect.E_depo_scint   += pevstr->SCNde[l]; 
	  
      //if(indscn == 0) first scintillator layer condition
	  tra2[current_track].detect.stop_time_scint                 = pevstr->SCNtim[l]*1E+09; 
    }
  }

tra2[current_track].detect.npoint = npti+1;




  tra2[current_track].detect.E_depo_calo          = 0.;   // calorimeter
  tra2[current_track].detect.E_depo_calo_crystal  = 0.;
  vector <int>   iCAL;   iCAL.clear();
  vector <float> edepo;  edepo.clear();  
  
  int   pointercalo_sec   = -1;
  int   pointercalo_ter   = -1;


  for(int m=0;m<pevstr->CALn;m++){      // Calo
    pointercalo = pevstr->CALid[m]-1; //PRIMARI (particle beam)
    if(pointercalo == index_tracks[current_track] && npti < max_points ) {
      
     
      tra2[current_track].detect.E_depo_calo            += pevstr->CALde[m]; 
	  tra2[current_track].detect.E_depo_calo_crystal    += pevstr->CALicry[m];
	  
	  
	for(int msec=0;msec<pevstr->CALn;msec++){      // SECONDARI (after interaction of primary)
	  pointercalo_sec = pevstr->CALid[msec]-1;
	   if (pevstr->TRpaid[pointercalo_sec] == pointercalo+1 ) {
		tra2[current_track].detect.E_depo_calo       +=pevstr->CALde[msec];
		tra2[current_track].detect.E_depo_calo_crystal    += pevstr->CALde[msec];

		
	   	 for(int mter=0;mter<pevstr->CALn;mter++){      //TERZIARI 
	      		pointercalo_ter = pevstr->CALid[mter]-1;
	     		 if (pevstr->TRpaid[pointercalo_ter] == pointercalo_sec+1) {
			       tra2[current_track].detect.E_depo_calo += pevstr->CALde[mter];
		                    tra2[current_track].detect.E_depo_calo_crystal += pevstr->CALde[mter];

}
} //END terziari
}
} //END secondari
	  
	  
      iCAL.push_back(pevstr->CALicry[m]);
      edepo.push_back( pevstr->CALde[m] );   
	  
	     
    }    
  }//END primari
  
  
  for(int m=0; m<pevstr->CALn; m++){  //background
    pointercalo = pevstr->CALid[m]-1;
    if(pointercalo != index_tracks[current_track]){//if I can't distinguish my fragment deposition from bkg, I add this quantity
      for(unsigned int c=0; c<iCAL.size(); c++){  
	if(pevstr->CALicry[m] == iCAL.at(c)) {tra2[current_track].detect.E_depo_calo += pevstr->CALde[m];} 
      }//ical.at(c) means I have deposition in crystal at position "c"
    }//ical.size is the # of all calo crystals with E_deposition
  }
  
  iCAL.clear();
  edepo.clear();


  

}
}



//------------- Smearing of Monte Carlo quantities (Generation class) -------------------------------------

void      Reconstruction::Smearing(TRandom2  *casos, EVENTO_STRUCT  *pevstr, ALLTRACK_STRUCT tra2[max_tra_ev], int      index_tracks[max_tra_ev], int      ntracks_per_event, double par[11]){



current_track = -1; 
  for(int a = 0; a <= ntracks_per_event; a++) {
    
    if(a  >= max_tra_ev) break;
    
    current_track = a;


double sigma_TOF   = 0;
 
sigma_TOF = (par[2] + (par[3]/tra2[current_track].Z))/1000; //ns

tra2[current_track].detect.tof_stc_scint      = casos->Gaus(tra2[current_track].detect.stop_time_scint -  tra2[current_track].detect.start_time_sc,     sigma_TOF);//primari
tra2[current_track].detect.tof_vtx_scint_frag = casos->Gaus(tra2[current_track].detect.stop_time_scint -  tra2[current_track].detect.time_vertex,       sigma_TOF); //fragments+primari


  
double sigma_DE_DE = 0;
sigma_DE_DE = (par[4] + (par[5]/(tra2[current_track].detect.E_depo_scint * 1000)))/100;  //not in %
  if (sigma_DE_DE > par[6] ) sigma_DE_DE = par[6];
  if (sigma_DE_DE < par[7] ) sigma_DE_DE = par[7];
tra2[current_track].detect.E_depo_scintillator    = casos->Gaus((tra2[current_track].detect.E_depo_scint*1000), (tra2[current_track].detect.E_depo_scint*1000) * sigma_DE_DE );   
     //E depo scintillator in MeV

//smearing momentum, for A calculation, in GeV/c
double sigmaP_P  = 0.;
sigmaP_P         = par[0]; // =  delta p/p
tra2[current_track].kin_rec.momentum      = (pow(pevstr->TRipx[index_tracks[current_track]]*pevstr->TRipx[index_tracks[current_track]] +  
					    pevstr->TRipy[index_tracks[current_track]]*pevstr->TRipy[index_tracks[current_track]] + 
					    pevstr->TRipz[index_tracks[current_track]]*pevstr->TRipz[index_tracks[current_track]], 0.5)); //GeV/c

tra2[current_track].kin_rec.momentum_sm   = casos->Gaus(tra2[current_track].kin_rec.momentum, tra2[current_track].kin_rec.momentum * sigmaP_P); 

  
//smearing E_calo, for A calculation, in GeV 
double sigmaE_E = 0.;
sigmaE_E        = par[1];// = delta E/E
tra2[current_track].kin_rec.E_depo_calorimeter = casos->Gaus(tra2[current_track].detect.E_depo_calo, tra2[current_track].detect.E_depo_calo * sigmaE_E);
  
}
      
}
  
  
  
   
//-------------------- Z reconstructed from BetheBloch formula ------------------------------

//smearing values are used

void Reconstruction::Bethebloch(ALLTRACK_STRUCT tra2[max_tra_ev], int      ntracks_per_event){
	
 
	
  for(int a = 0; a <= ntracks_per_event; a++) { //  Current_track = a
    
    if(a  >= max_tra_ev ) break; 
    
   
    //---------  lenght_ToF -> npti_till_scintillator = tra2[a].detect.npoint ----------------
    float L_ToF = 0.;
    TVector3 Pt1; 
	Pt1.SetXYZ( tra2[a].tr.pt[0].x, tra2[a].tr.pt[0].y, tra2[a].tr.pt[0].z );
    TVector3 Pt2; 
	Pt2.SetXYZ( 0., 0., 0. );
	
	
	for(int gj = 1; gj < tra2[a].detect.npoint; gj++) {
    Pt2.SetXYZ( tra2[a].tr.pt[gj].x, tra2[a].tr.pt[gj].y, tra2[a].tr.pt[gj].z);
    L_ToF += pow( pow(Pt2.X() - Pt1.X(), 2) + pow(Pt2.Y() - Pt1.Y(), 2) + pow(Pt2.Z() - Pt1.Z(), 2) , 0.5);

    Pt1 = Pt2;

} 

  tra2[a].detect.distance = L_ToF;
  //cout<< "distanza   " << tra2[a].detect.distance<< endl;
  
   //-----------  v = L_ToF / ToF ------------------------
  float v[a] = {0.};
  v [a]             = tra2[a].detect.distance/tra2[a].detect.tof_vtx_scint_frag;
  
  
  // ----- beta = v/c ----------
  tra2[a].kin_rec.beta         = v[a]/ CLIGHT;
  //cout << "  beta   "<<tra2[a].kin_rec.beta << endl; 
  
  if(tra2[a].kin_rec.beta > 1) { //to check
  cout << "beta   " << tra2[a].kin_rec.beta<< endl;

}
  //------- gamma --------------
  tra2[a].kin_rec.gamma        =  1/pow((1 - pow( tra2[a].kin_rec.beta, 2)), 0.5);
  
  //----------- log-beta^2 of BetheBloch formula --------------
  float logaritmo_beta[a] = {0.};
  logaritmo_beta[a]               = log((2*massa_e*1000 * pow(tra2[a].kin_rec.beta, 2) * pow(tra2[a].kin_rec.gamma, 2))/ (Iscint*1000)) - pow(tra2[a].kin_rec.beta, 2);
  
  //------ dE/dx ----------------------
  tra2[a].kin_rec.E_depo_scintillator = tra2[a].detect.E_depo_scintillator;                    
  

  //Z_reco of fragments -->  bethebloch
  tra2[a].kin_rec.Z = pow((tra2[a].kin_rec.E_depo_scintillator * pow(tra2[a].kin_rec.beta,2))/(K* scint_ZsuA * scint_thick *scint_density * nscint* logaritmo_beta[a]), 0.5);
 // cout << " Z   " << tra2[a].kin_rec.Z<< endl;
  
  	
	
}
}

 


void  Reconstruction::Measure_A(ALLTRACK_STRUCT tra2[max_tra_ev], int      ntracks_per_event, ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]){
	
	current_fragment = 0;
	
	for(int a = 0; a <= ntracks_per_event; a++) {
    
    if(a  >= max_tra_ev ) break; //current_track = a
	
//---------- 1 formula of A, c=1 ----------------

tra2[a].kin_rec.A_1  = tra2[a].kin_rec.momentum_sm / (tra2[a].kin_rec.beta * tra2[a].kin_rec.gamma * MASSA_U);


//----------- 2 Formula of A, c=1 ---------------

tra2[a].kin_rec.A_2  = tra2[a].kin_rec.E_depo_calorimeter/((tra2[a].kin_rec.gamma - 1.0) * MASSA_U);	


//------------ 3 formula of A, c=1 --------------

tra2[a].kin_rec.A_3  = (pow(tra2[a].kin_rec.momentum_sm, 2) - pow(tra2[a].kin_rec.E_depo_calorimeter, 2))/(2 * MASSA_U * tra2[a].kin_rec.E_depo_calorimeter);
 	





//------------------- for each fragments ---> tra_frag[current_track][current_fragment]  ------------------

 

    
    for(int ii = 0; ii<NUMFRAG; ii++){
      current_fragment = ii; 
    
      if(tra2[a].kin_gen.Z == charge_gen_frag[ii] && int(tra2[a].kin_gen.A + 0.5) == A_gen_frag[ii] ){ 
	tra2[a].is_fragment = current_fragment; 
	tra_frag[a][current_fragment] = tra2[a];  
      }
    } 
    
}//end for on a = current_track

}//end A_measure function



//---------------------- Fill Histograms of Reconstruction --------------------------------------


void Reconstruction::Fill_histo_tracks(TFile    *f_out, ALLTRACK_STRUCT tra2[max_tra_ev], int      ntracks_per_event)  {

  f_out->cd();
  char nam[200];  
     
   
     
 for(int a = 0; a <= ntracks_per_event; a++) { //same order of plot as in Booking.cpp ---> otherwise: segmentation problem

	snprintf(nam, 200, "RECONSTRUCTION/hTOF_Smearing_reco"); 

	  ((TH1D*)gDirectory->Get(nam))->Fill(tra2[a].detect.tof_vtx_scint_frag);
	  
	snprintf(nam, 200, "RECONSTRUCTION/hTOF_reco"); 

	  ((TH1D*)gDirectory->Get(nam))->Fill(tra2[a].detect.stop_time_scint -  tra2[a].detect.time_vertex);  
	  
	  
	  
	  
	snprintf(nam, 200, "RECONSTRUCTION/hE_depo_scint_reco"); 

	  ((TH1D*)gDirectory->Get(nam))->Fill(tra2[a].detect.E_depo_scint*1000);
	  
    snprintf(nam, 200, "RECONSTRUCTION/hE_depo_smearing_reco"); 

	  ((TH1D*)gDirectory->Get(nam))->Fill(tra2[a].detect.E_depo_scintillator);
	  
	  
	  
	  
	  
		snprintf(nam, 200, "RECONSTRUCTION/hMomentum"); 

	  ((TH1D*)gDirectory->Get(nam))->Fill(tra2[a].kin_rec.momentum);  
	  
	  	snprintf(nam, 200, "RECONSTRUCTION/hMomentum_sm"); 

	  ((TH1D*)gDirectory->Get(nam))->Fill(tra2[a].kin_rec.momentum_sm);
	  
	  
	  
	snprintf(nam, 200, "RECONSTRUCTION/hZ_reco"); 

	  ((TH1D*)gDirectory->Get(nam))->Fill(tra2[a].kin_rec.Z);
	  
	  
	  
	

 if(tra2[a].Z >=0 && tra2[a].Z < 9){  

      snprintf(nam, 200, "RECONSTRUCTION/hZrec %d", tra2[a].Z); 

      ((TH1D*)gDirectory->Get(nam))->Fill( tra2[a].kin_rec.Z ); 

    }
    
 

//H
if(tra2[a].kin_rec.Z >0 && tra2[a].kin_rec.Z < 2 ){
	if(int(tra2[a].kin_gen.A + 0.5) == 1){
	
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A1_H"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_1  );
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A2_H"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_2  );    
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A3_H"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_3  );           
}
}

//He
if(tra2[a].kin_rec.Z >1 && tra2[a].kin_rec.Z < 3 ){
	if(int(tra2[a].kin_gen.A + 0.5) == 4){
	
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A1_He"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_1  );
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A2_He"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_2  ); 
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A3_He"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_3  );				               
}
}

//Li
if(tra2[a].kin_rec.Z >2 && tra2[a].kin_rec.Z < 4 ){
	if(int(tra2[a].kin_gen.A + 0.5) == 7){
	
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A1_Li"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_1  );
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A2_Li"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_2  );  
    snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A3_Li"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_3  );					              
}
}

//Be
if(tra2[a].kin_rec.Z >3 && tra2[a].kin_rec.Z <5 ){
	if(int(tra2[a].kin_gen.A + 0.5) == 9){
	
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A1_Be"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_1  );
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A2_Be"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_2  );  
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A3_Be"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_3  );  				              
}
}


//B
if(tra2[a].kin_rec.Z >4 && tra2[a].kin_rec.Z < 6 ){
	if(int(tra2[a].kin_gen.A + 0.5) == 11){
	
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A1_B"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_1  );
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A2_B"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_2  );
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A3_B"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_3  );				                
}
}

//C
if(tra2[a].kin_rec.Z >5 && tra2[a].kin_rec.Z <7  ){
	if(int(tra2[a].kin_gen.A + 0.5) == 12){
	
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A1_C"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_1  );
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A2_C"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_2  );  
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A3_C"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_3  );				              
}
}

//N
if(tra2[a].kin_rec.Z >6 && tra2[a].kin_rec.Z <8  ){
	if(int(tra2[a].kin_gen.A + 0.5) == 14){
	
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A1_N"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_1  );
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A2_N"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_2  ); 
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A3_N"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_3  );				               
}
}

//O
if(tra2[a].kin_rec.Z >7 && tra2[a].kin_rec.Z <9  ){
	if(int(tra2[a].kin_gen.A + 0.5) == 16){
	
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A1_O"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_1  );
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A2_O"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_2  );
	snprintf(nam, 200, "RECONSTRUCTION/hA_rec_mass_A3_O"); //directory Reconstruction
	                ((TH1D*)gDirectory->Get(nam))->Fill(  tra2[a].kin_rec.A_3  );                
					                
}
}




}     
     
}
   



      
      
      
