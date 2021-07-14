#ifndef Analysis_H
#define Analysis_H

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


TRandom2 *casos = new TRandom2();
double    pigreco = TMath::Pi();


//output type histogram
TH1D *h; 
TH2D *h2;
TH3D *h3;
TProfile *hprof;

const double             massa_e       =   0.5109989461e-3;  // in Gev
const double             CLIGHT        =   29.9792458;    // in cm/ns
const double             MASSA_U       =   0.93149432;   // in GeV
const int                NUMFRAG       =   11;            // 8

const double             Iscint        = 64.684e-9;   // in GeV
const double             scint_thick   = 0.3; //in cm
const int                nscint        = 2;
const double             scint_density = 1.023; //g/cm^3
const double             scint_ZsuA    = 0.54157;
const double             de_cost       = 0.000307075;  // GeV cm^2/g 


int                      charge_gen_frag[NUMFRAG] = {1,   2,   3,   4,    5,    6,    7,    8,   1,   1,   2 };
float                    A_gen_frag[NUMFRAG]      = {1.,  4.,  7.,  9.,  11.,  12.,  14.,  16.,  2.,  3.,  3.}; 
int                      fluka_gen[NUMFRAG]       = {1,  -6,  -2,  -2,   -2,   -2,   -2,   -2,  -3,  -4,  -5};


int                      A_beam;
int                      cha_beam;
float                    kin_nucleon;
float                    gamma_beam;
float                    beta_beam;
TLorentzRotation         lambda;     

const int                max_points        =  100;
const int                max_tra_ev        =   20;
const int                max_alltra        =   50;
int                      current_event;
int                      status;
int                      ntracks_per_event =   0;
int                      event_number      =   0;
int                      index_tracks[max_tra_ev];

int                      npti              =  -1;

TString                  filenameroot_out;
TString                  file_input_dat;

TFile                    *f_out;
FILE                     *pfiles_input_dat;  
std::vector<std::string> list_of_input_files;
TChain                   *chain_t;
int                      number_of_input_files;

EVENTO_STRUCT            *pevstr;
Evento                   *Ev;
int                      current_track;
int                      current_fragment;

TVector3                 b;

const int  NPARFITCHI2    = 4; 
const int  NMEASCHI2      = 3; 
const int  NMISURE_MASS   = 3;
char       nameparchi2[NPARFITCHI2][20];
double     ParReschi2[NPARFITCHI2];
double     EParReschi2[NPARFITCHI2];
double     parstartchi2[NPARFITCHI2];
double     stepchi2[NPARFITCHI2];
double     boundlowchi2[NPARFITCHI2];
double     boundupchi2[NPARFITCHI2];
double     arglist[10];
double     MeasParchi2[NMEASCHI2];
double     EMeasParchi2[NMEASCHI2];

double     cut_chi2;


double sigma_E ;
double sigma_P;
double theta_res;
double phi_res;
double sigma_res ;

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
  float   start_time_sc;
  float   sc_x;
  float   sc_y;
  float   sc_z;
  float   time_vertex;
  float   E_depo_msd;
  float   E_depo_scint;
  float   stop_time_scint;
  float   E_depo_calo;   
};


struct kinetic{
  float          A;
  int            Z;
  int            paid;
  int            fluka_code;
  float          mass;
  float          momentum;
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
  info_detect    detect;
  track          tr; 
};


kinetic tra2[max_tra_ev]; 
kinetic tra_frag[max_tra_ev][NUMFRAG]; 

void       Initialize();
void       Openfiles();
void       Initialize_in_each_event();
void       Initialize_zero(kinetic     &  kin);
int        Booking(TFile *f_out); 
int        Tracks_in_the_event2(EVENTO_STRUCT *pevstr);
void       Find_index_tracks_all_detectors(EVENTO_STRUCT *pevstr);
void       Fill_tracks(EVENTO_STRUCT *pevstr);
void       Fill_tracks_detector(EVENTO_STRUCT *pevstr);
void       Fill_tracks_frag();
void       Fill_histo_tracks();

#endif
