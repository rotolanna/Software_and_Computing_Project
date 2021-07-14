#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>
#include "TBrowser.h"
#include <TDirectory.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TRandom.h>
#include <TRandom2.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include "TGraphAsymmErrors.h"
#include "TProfile.h"
#include <TLorentzVector.h>
#include "TLorentzRotation.h" 
#include <TVector3.h>
#include "TVector2.h"
#include <TRotation.h>
#include <TMinuit.h>
#include <TF1.h>
#include <string>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>
#include <TStyle.h>
#include <TMath.h>
#include <TSystem.h>
#include <TCanvas.h>
#include "TChain.h" 
#include "TMatrixD.h"
#include "TDecompLU.h"


//Initialization of variables in Init_in_each_event.cpp

const int    max_points = 100;


struct point{
  float x;
  float y;
  float z;
  float time;
};

struct track{
  point pt[max_points]; 
};


struct info_detect{
  int     npoint;
  float   start_time;
  float   start_time_sc;//star time start counter
  float   stop_time_scint;
  float   vtx_x;//vertex_x
  float   vtx_y;
  float   vtx_z;
  float   time_vertex;
  float   x_inner_in; //inner tracker_x
  float   y_inner_in;
  float   z_inner_in;
  float   msd_x_in;//MicroStrip Detector_x
  float   msd_y_in;
  float   msd_z_in;
  float   sc_x;//scintillator_x
  float   sc_y;
  float   sc_z;
  float   E_depo_tracker;//sum of all E_deposition in VTX + MSD + INNER_TRACKER
  float   E_depo_vtx;
  float   E_depo_itr;
  float   E_depo_msd;
  float   E_depo_scint;
  float   E_depo_calo;  //E_deposition in calorimeter
  float   E_depo_calo_crystal; //E_depo in crystals of calorimeter
  
  float   distance; //L_ToF
  
  //Smearing 
  float   tof_stc_scint;
  float   tof_vtx_scint_frag;
  float   E_depo_scintillator;
  float   E_depo_calorimeter;
  
};

struct kinetic{
  int            index;
  float             A;
  float             A_1;
  float             A_2;
  float             A_3;
  double            Z;
  int            paid;
 //int            fluka_code;
  float          mass;
  float          momentum;
  float          momentum_sm; //smearing momentum
  float          theta;
  float          phi;
  float          total_energy;
  float          kine_energy;
  float          kine_energy_per_nucleon;
  float          gamma;
  float          beta;
  TLorentzVector fourv_direct;
  TLorentzVector fourv_inverse;
  float          kine_energy_inverse;
  float          kine_energy_direct; 
  float          E_depo_scintillator; 
  float          E_depo_calorimeter;//smearing E_depo
  
  info_detect    detect;
  track          tr; 
};

typedef struct {
  int         track_number;
  int         fluka_code;
  int         Z;
  int         is_fragment;
  kinetic       kin_gen;
  kinetic       kin_rec;
  info_detect   detect;
  track         tr; 
} ALLTRACK_STRUCT;








#endif
