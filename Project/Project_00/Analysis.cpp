#include "Evento.h"
#include "Analysis.h"

using namespace std;
using namespace TMath;
extern TStyle*  gStyle;  

int main(int argc, char *argv[]){
	
//----plot setting-----

  gStyle->SetPalette(1);
  gROOT->SetStyle("Plain");
  gStyle->SetMarkerStyle(6);
  gStyle->SetOptFit(11111111);
  gStyle->SetOptStat(11111111);

//-----Initialize----------

  casos->SetSeed(1234); 
  Initialize();
  Openfiles();
  status = Booking(f_out);
  Ev = new Evento();  
  status = Ev->FindBranches(chain_t,pevstr);

//-------MC simulation----------
   
  for (int kk = 0; kk<chain_t->GetEntries(); kk++){  
  //  for (int kk = 0; kk<600; kk++){  
    current_event++; 
    if(kk%1000==0){ cout<<"Processed event = "<<kk<<endl;}
    
    status = Ev->Clean();    
    chain_t->GetEntry(kk);    
    Initialize_in_each_event();    
    status = Tracks_in_the_event2(pevstr); // part concerning the tracks    
    Fill_histo_tracks();
   
  }  

  f_out->Write();
  f_out->Close();
  
  return 0;
  
}



void Initialize(){

  status                  = 0;
  current_event           = 0;
  number_of_input_files   = 0;

  file_input_dat          = "Analysis_input.dat";
  filenameroot_out        = "Out.root";

  pevstr = new EVENTO_STRUCT;   // CREATE AND FILL EVENT STRUCTURE

}



void       Openfiles(){

  f_out = new TFile(filenameroot_out,"RECREATE");    // file di histogrammi
  
  pfiles_input_dat=fopen(file_input_dat,"r"); if (!pfiles_input_dat) { cout<<"No file input dat "<<endl; exit(1);} 
  char nometmp[200];
  number_of_input_files = 0;
  
  int a = 1;
  a = fscanf(pfiles_input_dat,"%d",&A_beam); 
  a = fscanf(pfiles_input_dat,"%d",&cha_beam); 
  a = fscanf(pfiles_input_dat,"%f",&kin_nucleon); 
  
  gamma_beam = ((kin_nucleon*A_beam) + A_beam)/A_beam;
  beta_beam  = pow(1.0-1.0/pow(gamma_beam,2),0.5);
  
  lambda.Boost(0.,0.,-beta_beam);
  
  a = 1;
  while( a == 1){
    a = fscanf(pfiles_input_dat,"%s",nometmp); 
    list_of_input_files.push_back(nometmp);   
    number_of_input_files++;
  }
  number_of_input_files = number_of_input_files -1;

  
  chain_t = new TChain("EventTree");
  string nametot;  
  char namefile[200];
  for (int i =0; i<number_of_input_files; i++){
    nametot = list_of_input_files[i];
    strcpy(namefile,nametot.c_str());
    TFile* f_input = TFile::Open(namefile);
    if(f_input == 0){ std::cout <<"Error opening rootuple " << namefile<<std::endl; exit(-1); }    
    chain_t->Add(namefile);
    nametot = " ";

  }
  
  
}


int Booking(TFile *f_out){ //print plots of Generation function

  char nam[200], tit[200];  

  f_out->mkdir("GENERATION");
  f_out->cd("GENERATION");

  snprintf(nam, 200, "hmomentum"); snprintf(tit, 200, "momento traccia"); h  = new TH1D(nam, tit,500, 0.,20.); 

  f_out->cd("..");
  
  return 0;
}


void      Initialize_in_each_event(){ //initialize all the particle parameters in each event

  for(int f=0; f<max_tra_ev; f++) { 
    Initialize_zero(tra2[f]);        
    for (int ii=0; ii<NUMFRAG;ii++){
      Initialize_zero(tra_frag[f][ii]);        
    }
  }   

  for(int f=0; f<max_tra_ev; f++) index_tracks[f] = -1;
  ntracks_per_event        = -1;

}


void       Initialize_zero(kinetic   & kin){

  kin.A                     =   0;    kin.Z                  =   0 ;  kin.fluka_code              = -777;  kin.paid            = 0;
  kin.mass                  =   0.;   kin.momentum           =   0.;  kin.theta                   =  0.;   kin.phi             = 0.;   
  kin.total_energy          =   0.;   kin.kine_energy        =   0.;  kin.kine_energy_per_nucleon =  0.;      
  kin.gamma                 =   0.;   kin.beta               =   0.;  
  kin.fourv_direct.SetPxPyPzE( 0., 0., 0., 0.);                      
  kin.fourv_inverse.SetPxPyPzE(0., 0., 0., 0.);  
  kin.kine_energy_inverse   =   0.;   kin.kine_energy_direct =   0.;

  kin.detect.npoint = 0;            kin.detect.start_time  = 0.;     kin.detect.start_time_sc = 0.;
  kin.detect.sc_x   = 0;            kin.detect.sc_y        = 0.;     kin.detect.sc_z          = 0.;
  kin.detect.time_vertex = 0.;      kin.detect.E_depo_msd  = 0.;     kin.detect.E_depo_scint  = 0.;
  kin.detect.stop_time_scint = 0.;  kin.detect.E_depo_calo = 0.;   

  for(int i = 0; i <max_points; i++) {
    kin.tr.pt[i].x = 0.;    kin.tr.pt[i].y = 0.;  kin.tr.pt[i].z = 0.;  kin.tr.pt[i].time = 0.; 
  }

}

int Tracks_in_the_event2(EVENTO_STRUCT *pevstr){

  Find_index_tracks_all_detectors(pevstr);
  
  Fill_tracks(pevstr);

  Fill_tracks_frag();

  return 0;

}





void       Find_index_tracks_all_detectors(EVENTO_STRUCT *pevstr){

  int   pointervtx        = -1;
  int   pointerIT         = -1;
  int   pointer2dc        = -1;
  int   pointerscint      = -1;
  int   pointercalo       = -1;
  int   used_track        =  0;

  ntracks_per_event = -1;

  for(int a = 0; a < max_tra_ev; a++)  index_tracks[a]    = 0; 

  for(int i=0;i<pevstr->VTXn;i++){                      // Vertex
    pointervtx = pevstr->VTXid[i]-1;
    for(int j=0;j<pevstr->ITRn;j++){                    // Inner Tracker
      pointerIT = pevstr->ITRid[j]-1;
      if ( pointervtx==pointerIT ) {
	for(int k=0;k<pevstr->MSDn;k++){                // MSD
	  pointer2dc = pevstr->MSDid[k]-1;
	  if ( pointervtx==pointer2dc) {
	    for(int l=0;l<pevstr->SCNn;l++){            // Scint
	      pointerscint = pevstr->SCNid[l]-1;
	      if ( pointervtx==pointerscint ) {
		for(int m=0;m<pevstr->CALn;m++){        // Calo
		  pointercalo = pevstr->CALid[m]-1;
		  if ( pointervtx==pointercalo && ntracks_per_event < max_tra_ev) {
		    if(ntracks_per_event == -1) {
		      ntracks_per_event++;
		      index_tracks[ntracks_per_event] = pointervtx;
		    }
		    else{
		      used_track = 0;
		      for(int hh = 0; hh<=ntracks_per_event; hh++) if(pointervtx == index_tracks[hh] )  used_track = 1;			  
		      if(used_track == 0 ) {
			ntracks_per_event++;
			index_tracks[ntracks_per_event] = pointervtx;
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }  
  
}



void     Fill_tracks(EVENTO_STRUCT *pevstr){

  current_track = -1; 
  for(int a = 0; a <= ntracks_per_event; a++) {
    npti = -1;
    if(a  >= max_tra_ev ) break;
    
    current_track = a;
    tra2[current_track].paid          = pevstr->TRpaid[index_tracks[current_track]];
    tra2[current_track].fluka_code    = pevstr->TRfid[index_tracks[current_track]]; 
    tra2[current_track].Z             = pevstr->TRcha[index_tracks[current_track]];                    
    tra2[current_track].mass          = pevstr->TRmass[index_tracks[current_track]];                                           // generation
    tra2[current_track].A             = tra2[current_track].mass/MASSA_U;
    tra2[current_track].momentum      = pow(pevstr->TRipx[index_tracks[current_track]]*pevstr->TRipx[index_tracks[current_track]] +  
					    pevstr->TRipy[index_tracks[current_track]]*pevstr->TRipy[index_tracks[current_track]] + 
					    pevstr->TRipz[index_tracks[current_track]]*pevstr->TRipz[index_tracks[current_track]],0.5) ;
    tra2[current_track].theta         = acos(pevstr->TRipz[index_tracks[current_track]]/tra2[current_track].momentum)*180/M_PI;   
    tra2[current_track].phi           = atan2(pevstr->TRipy[index_tracks[current_track]], pevstr->TRipx[index_tracks[current_track]])*180/M_PI;
    
    tra2[current_track].total_energy  = pow( pow(tra2[current_track].momentum, 2) + pow(tra2[current_track].mass, 2), 0.5);
    tra2[current_track].kine_energy   = tra2[current_track].total_energy -  tra2[current_track].mass;
    
    tra2[current_track].kine_energy_per_nucleon = (tra2[current_track].total_energy -  tra2[current_track].mass)/tra2[current_track].A;
    
    tra2[current_track].gamma         = tra2[current_track].total_energy/tra2[current_track].mass;
    tra2[current_track].beta          = pow( 1.0 - 1.0/pow(tra2[current_track].gamma, 2), 0.5);
    
    tra2[current_track].fourv_direct.SetPxPyPzE(pevstr->TRipx[index_tracks[current_track]], pevstr->TRipy[index_tracks[current_track]], pevstr->TRipz[index_tracks[current_track]], tra2[current_track].total_energy); 

    Fill_tracks_detector(pevstr); 
    
  }
  
}



void       Fill_tracks_detector(EVENTO_STRUCT *pevstr){

  int   pointerstc        = -1;
  int   pointervtx        = -1;
  int   pointerIT         = -1;
  int   pointer2dc        = -1;
  int   pointerscint      = -1;
  int   pointercalo       = -1;

  tra2[current_track].detect.start_time  = pevstr->TRtime[index_tracks[current_track]]*1E+09;

  for(int isc=0;isc< pevstr->STCn;isc++){               // SC
    pointerstc = pevstr->STCid[isc]-1;;
    if(pointerstc ==index_tracks[current_track] ) {
      tra2[current_track].detect.start_time_sc = pevstr->STCtim[isc]*1E+09;
      tra2[current_track].detect.sc_x          = pevstr->STCxin[isc];
      tra2[current_track].detect.sc_y          = pevstr->STCyin[isc];
      tra2[current_track].detect.sc_z          = pevstr->STCzin[isc];
    }
  }

  int indvtx = -1;
  for(int i=0;i<pevstr->VTXn;i++){                    //Vertex
    pointervtx = pevstr->VTXid[i]-1;
    if(pointervtx ==index_tracks[current_track] && npti < max_points) {
      npti++;
      indvtx++;
      tra2[current_track].tr.pt[npti].x                       = pevstr->VTXxin[i];    
      tra2[current_track].tr.pt[npti].y                       = pevstr->VTXyin[i];    
      tra2[current_track].tr.pt[npti].z                       = pevstr->VTXzin[i]; 
      tra2[current_track].tr.pt[npti].time                    = pevstr->VTXtim[i]; 
      if(indvtx == 0) tra2[current_track].detect.time_vertex  = pevstr->VTXtim[i]*1E+09; 
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
      tra2[current_track].detect.E_depo_msd           += pevstr->MSDde[k]; 
    }
  }

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
      tra2[current_track].detect.E_depo_scint                   += pevstr->SCNde[l];
      if(indscn == 0) tra2[current_track].detect.stop_time_scint = pevstr->SCNtim[l]*1E+09;
    }
  }

  tra2[current_track].detect.E_depo_calo          = 0.;   // calorimeter
  vector <int>   iCAL;   iCAL.clear();
  vector <float> edepo;  edepo.clear();  

  for(int m=0;m<pevstr->CALn;m++){      // Calo
    pointercalo = pevstr->CALid[m]-1;
    if(pointercalo ==index_tracks[current_track] && npti < max_points) {
      npti++;
      tra2[current_track].tr.pt[npti].x                  = pevstr->CALxin[m];    
      tra2[current_track].tr.pt[npti].y                  = pevstr->CALyin[m];    
      tra2[current_track].tr.pt[npti].z                  = pevstr->CALzin[m]; 
      tra2[current_track].tr.pt[npti].time               = pevstr->CALtim[m]; 
      tra2[current_track].detect.E_depo_calo            += pevstr->CALde[m];  
      iCAL.push_back(pevstr->CALicry[m]);
      edepo.push_back( pevstr->CALde[m] );      
    }    
  }
  for(int m=0; m<pevstr->CALn; m++){
    pointercalo = pevstr->CALid[m]-1;
    if(pointercalo != index_tracks[current_track]){
      for(unsigned int c=0; c<iCAL.size(); c++){
	if(pevstr->CALicry[m] == iCAL.at(c)) {tra2[current_track].detect.E_depo_calo += pevstr->CALde[m];}
      }
    }
  }
  
  iCAL.clear();
  edepo.clear();


  tra2[current_track].detect.npoint = npti+1;

}



void     Fill_tracks_frag(){ //fill the matrix tra_frag[current_track] [current_fragment]

  float ainf = 0; float asup = 0.; 

  for(int a = 0; a <= ntracks_per_event; a++) {
    current_track = a;
    for(int ii = 0; ii<NUMFRAG; ii++){
      current_fragment = ii; 
      ainf =  0.95*A_gen_frag[ii]; asup = 1.05*A_gen_frag[ii]; if(ii < 2 || ii > 7) {ainf = 0.; asup = 20.;}
      if(tra2[a].fluka_code == fluka_gen[ii] && tra2[a].Z == charge_gen_frag[ii] && tra2[a].A > ainf && tra2[a].A < asup ) { 
	tra_frag[a][current_fragment] = tra2[a];  
      }
    }
  }


}

void Fill_histo_tracks(){ //fill the histograms

  f_out->cd();
  char nam[200];
  for(int a = 0; a <= ntracks_per_event; a++) {
    snprintf(nam, 200, "GENERATION/hmomentum");      ((TH1D*)gDirectory->Get(nam))->Fill(tra2[a].momentum);
  }

}
