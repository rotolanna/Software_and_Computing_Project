#include "Generation.h"


using namespace std;

ClassImp(Generation);

void Generation::Fill_all_gen(EVENTO_STRUCT *pevstr, TFile    *f_out, ALLTRACK_STRUCT tra2[max_tra_ev], ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]){
	 

	Find_index_tracks_all_detectors(pevstr);
  
    Fill_tracks(pevstr, tra2);
		
	Fill_tracks_frag(tra2, tra_frag);
	
	Fill_histo_tracks(f_out, tra2, tra_frag);
 	
}





void Generation:: Find_index_tracks_all_detectors(EVENTO_STRUCT *pevstr){ //Find index_tracks of particles passing through all the FOOT detectors

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
		    } //end else
		  }
		}//end calorimeter
	      }
	    }//end scintillator
	  }
	}//end msd
      }
    }//end Inner tracker
    
  }// end vertex 
  
}



void   Generation::  Fill_tracks(EVENTO_STRUCT *pevstr,  ALLTRACK_STRUCT tra2[max_tra_ev]){



  current_track = -1; 
  for(int a = 0; a <= ntracks_per_event; a++) {
   
    if(a  >= max_tra_ev ) break;
    
    current_track = a;
    tra2[current_track].track_number          = index_tracks[current_track];
    tra2[current_track].fluka_code            = pevstr->TRfid[index_tracks[current_track]]; 
    tra2[current_track].Z                     = pevstr->TRcha[index_tracks[current_track]]; 
    
	tra2[current_track].kin_gen.paid          = pevstr->TRpaid[index_tracks[current_track]];
    tra2[current_track].kin_gen.index         = index_tracks[current_track];//for kin_gen in struct.h
    tra2[current_track].kin_gen.Z             = pevstr->TRcha[index_tracks[current_track]];                    
    tra2[current_track].kin_gen.mass          = pevstr->TRmass[index_tracks[current_track]];                                          
    tra2[current_track].kin_gen.A             = tra2[current_track].kin_gen.mass/MASSA_U;
    tra2[current_track].kin_gen.momentum      = pow(pevstr->TRipx[index_tracks[current_track]]*pevstr->TRipx[index_tracks[current_track]] +  
					    pevstr->TRipy[index_tracks[current_track]]*pevstr->TRipy[index_tracks[current_track]] + 
					    pevstr->TRipz[index_tracks[current_track]]*pevstr->TRipz[index_tracks[current_track]],0.5) ;
    tra2[current_track].kin_gen.theta         = acos(pevstr->TRipz[index_tracks[current_track]]/tra2[current_track].kin_gen.momentum)*180/M_PI;   
    tra2[current_track].kin_gen.phi           = atan2(pevstr->TRipy[index_tracks[current_track]], pevstr->TRipx[index_tracks[current_track]])*180/M_PI;
    
    tra2[current_track].kin_gen.total_energy  = pow( pow(tra2[current_track].kin_gen.momentum, 2) + pow(tra2[current_track].kin_gen.mass, 2), 0.5);
    tra2[current_track].kin_gen.kine_energy   = tra2[current_track].kin_gen.total_energy -  tra2[current_track].kin_gen.mass;
    
    tra2[current_track].kin_gen.kine_energy_per_nucleon = (tra2[current_track].kin_gen.total_energy -  tra2[current_track].kin_gen.mass)/tra2[current_track].kin_gen.A;
    
    tra2[current_track].kin_gen.gamma         = tra2[current_track].kin_gen.total_energy/tra2[current_track].kin_gen.mass;
    tra2[current_track].kin_gen.beta          = pow( 1.0 - 1.0/pow(tra2[current_track].kin_gen.gamma, 2), 0.5);
    
    tra2[current_track].kin_gen.fourv_direct.SetPxPyPzE(pevstr->TRipx[index_tracks[current_track]], pevstr->TRipy[index_tracks[current_track]], pevstr->TRipz[index_tracks[current_track]], tra2[current_track].kin_gen.total_energy); 

   
   

   
   
   
  }
  
}


void    Generation::Fill_tracks_frag( ALLTRACK_STRUCT tra2[max_tra_ev], ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]){ //For fragments

  

  for(int a = 0; a <= ntracks_per_event; a++) {
    current_track = a;
    for(int ii = 0; ii<NUMFRAG; ii++){//for ex:  ii=0 means Hydrogen
      current_fragment = ii; 

      if(tra2[a].kin_gen.Z == charge_gen_frag[ii] ) { 
	tra_frag[a][current_fragment] = tra2[a];  

      }
    }
  }


}


//---------------Fill Histograms --------------------------

void Generation::Fill_histo_tracks(TFile    *f_out, ALLTRACK_STRUCT tra2[max_tra_ev], ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG] ){

  f_out->cd();
  char nam[200];
  
  for(int a = 0; a <= ntracks_per_event; a++) {
  	   snprintf(nam, 200, "GENERATION/hP_gen");      ((TH1D*)gDirectory->Get(nam))->Fill(tra2[a].kin_gen.momentum);
   
      snprintf(nam, 200, "GENERATION/hZ_gen");      ((TH1D*)gDirectory->Get(nam))->Fill(tra2[a].kin_gen.Z);
    
      snprintf(nam, 200, "GENERATION/hA_gen vs Z_gen");      ((TH2D*)gDirectory->Get(nam))->Fill(tra2[a].kin_gen.Z, tra2[a].kin_gen.A);   
	                                                         
      for(int ii = 0; ii<NUMFRAG; ii++){
       current_fragment = ii; 
       
	  snprintf(nam, 200, "GENERATION/hA_gen_frag_%d", current_fragment );  
	  if (tra_frag[a][current_fragment].kin_gen.A>0)     ((TH1D*)gDirectory->Get(nam))->Fill(tra_frag[a][current_fragment].kin_gen.A); 	  
	  
	  
     snprintf(nam, 200, "GENERATION/hkine_energy_gen_%d", current_fragment);     
    if (tra_frag[a][current_fragment].kin_gen.kine_energy_per_nucleon>0) ((TH1D*)gDirectory->Get(nam))->Fill((tra_frag[a][current_fragment].kin_gen.kine_energy_per_nucleon)*1000); //MeV
	
           
}

 }  
 
   }

//--------------Get_Function--------------------------------------

ALLTRACK_STRUCT* Generation::getTra2(){
	 return tra2;                             
}



int*  Generation::getindex(){
	return index_tracks;
}

int  Generation::getntrack(){
	return ntracks_per_event;
}

