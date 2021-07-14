#include "Init_in_each_event.h"


using namespace std;

ClassImp(Init_in_each_event);

//---------------KIN_GEN AND KIN_REC INITIALIZE---------------------

void       Init_in_each_event:: Initialize_zero_kine(kinetic &kin){
	
		
	
  kin.index                 =   0;
  kin.A                     =   0; 
  kin.A_1                   =   0;
  kin.A_2                   =   0;
  kin.A_3                   =   0;
  kin.Z                     =   0;  
  kin.paid                  =   0;
  kin.mass                  =   0.;     
  kin.momentum              =   0.;  
  kin.momentum_sm           =   0.;
  kin.theta                 =   0.;      
  kin.total_energy          =   0.;     
  kin.kine_energy           =   0.;  
  kin.kine_energy_per_nucleon  =   0.;      
  kin.gamma                    =   0.;    
  kin.beta                     =   0.;  
  kin.phi                      =   0.;
  kin.fourv_direct.SetPxPyPzE( 0., 0., 0., 0.);                      
  kin.fourv_inverse.SetPxPyPzE(0., 0., 0., 0.);  
  kin.kine_energy_inverse   =   0.;     
  kin.kine_energy_direct    =   0.;
  kin.E_depo_scintillator   =   0.;//smearing
  kin.E_depo_calorimeter    =   0.;//smearing
 
  Initialize_zero_detect(kin.detect);
  Initialize_zero_track(kin.tr); 
    

	
}


//---------------TRACK INITIALIZE------------------------------
void      Init_in_each_event::Initialize_zero_track(track &tr){

 for(int i=0; i<max_points; i++){
 	tr.pt[i].x = 0.;
 	tr.pt[i].y = 0.;
 	tr.pt[i].z = 0.;
 	tr.pt[i].time = 0.;
 }

  
}


//--------------DETECT INITIALIZE-------------------------------
void      Init_in_each_event::Initialize_zero_detect(info_detect &detect){

detect.npoint        = 0;

//start sul tempo
detect.start_time    = 0.;
detect.start_time_sc = 0.; 


//vertex
detect.vtx_x         = 0.;
detect.vtx_y         = 0.;
detect.vtx_z         = 0.;
detect.time_vertex   = 0.;
detect.E_depo_vtx    = 0.;

//inner tracker
detect.x_inner_in      = 0.;
detect.y_inner_in      = 0.;
detect.z_inner_in      = 0.;
detect.E_depo_itr      = 0.;


//msd
detect.msd_x_in      = 0.;
detect.msd_y_in      = 0.;
detect.msd_z_in      = 0.;
detect.E_depo_msd    = 0.;

//sum of E_depo in vtx + Inner + msd
detect.E_depo_tracker = 0.; 


//scintillator
detect.sc_x         = 0.;
detect.sc_y         = 0.;
detect.sc_z         = 0.;
detect.stop_time_scint         = 0.; //STOP time
detect.E_depo_scint            = 0.;

//calorimeter
detect.E_depo_calo          = 0.;
detect.E_depo_calo_crystal  = 0.;

//Smearing
detect.tof_stc_scint        = 0.;
detect.tof_vtx_scint_frag   = 0.;
detect.E_depo_scintillator  = 0.;
detect.E_depo_calorimeter   = 0.;


//L_ToF
detect.distance             = 0.;
}

//--------------ALLTRACK STRUCT Initialize-------------------
void      Init_in_each_event:: Initialize_zero(ALLTRACK_STRUCT &allt){



  allt.fluka_code              = -777; 
  allt.track_number            = 0;
  allt.Z                       = 0;
  allt.is_fragment             = 0;
  Initialize_zero_kine(allt.kin_gen);
  Initialize_zero_kine(allt.kin_rec);
  Initialize_zero_detect(allt.detect);
  Initialize_zero_track(allt.tr);


}

//-------------Initialize ALLTRACK STRUCT in each event--------------
void   Init_in_each_event::Initialize_in_each_event(){ 


  for(int f=0; f<max_tra_ev; f++) { 
    Initialize_zero(tra2[f]);        
    for (int ii=0; ii<NUMFRAG;ii++){
      Initialize_zero(tra_frag[f][ii]);        
    }
  }   

 
} 

//-------------- Get_function ------------------------
ALLTRACK_STRUCT* Init_in_each_event::getTra2(){
	 return tra2;                             
}



