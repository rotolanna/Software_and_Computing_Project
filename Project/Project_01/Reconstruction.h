#ifndef Reconstruction_H
#define Reconstruction_H

#include <string.h>
#include <vector>
#include <TStyle.h>
#include <TMath.h>
#include <TSystem.h>
#include <TCanvas.h>
#include "TChain.h"
#include "TMatrixD.h"
#include "TDecompLU.h"
#include <TRandom2.h>
#include <TMinuit.h>




#include "Booking.h"


using namespace std;

class Reconstruction {

private:
	 TRandom2                 *casos;
	 EVENTO_STRUCT            *pevstr;
     int      ntracks_per_event =   0;
     int      index_tracks[max_tra_ev];
	 int      current_track;
	 int      current_fragment;//max value = max NUMFRAG
	 int      npti;
	 ALLTRACK_STRUCT tra2[max_tra_ev]; 
	 ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG];
	 int      charge_gen_frag[NUMFRAG] = {1,   2,   3,   4,    5,    6,    7,    8,   1,   1,   2 }; 
     float    A_gen_frag[NUMFRAG]      = {1.,  4.,  7.,  9.,  11.,  12.,  14.,  16.,  2.,  3.,  3.}; 
	 TFile    *f_out;
	 int      flag;
	 double   par[11];
	 
	 
	 

  
  	 
public:
	Reconstruction(){
  }; //constructor

  ~Reconstruction(){
  }; //destructor
  

 
 
	//methods implemented in Reconstruction.cpp :
	
//Total function in main
void       Fill_all_rec(TRandom2  *casos, EVENTO_STRUCT  *pevstr, ALLTRACK_STRUCT tra2[max_tra_ev], int      index_tracks[max_tra_ev], int      ntracks_per_event, TFile  *f_out, double par[11], ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]);
//Fill_tracks_detector
void       Fill_tracks_detector(EVENTO_STRUCT *pevstr, ALLTRACK_STRUCT tra2[max_tra_ev], int      index_tracks[max_tra_ev], int      ntracks_per_event);
//Smearing
void       Smearing(TRandom2  *casos, EVENTO_STRUCT  *pevstr, ALLTRACK_STRUCT tra2[max_tra_ev], int      index_tracks[max_tra_ev], int      ntracks_per_event, double par[11]);
// Z calculation
void Bethebloch(ALLTRACK_STRUCT tra2[max_tra_ev], int      ntracks_per_event);
// A calculation trough 3 methods
void       Measure_A(ALLTRACK_STRUCT tra2[max_tra_ev], int      ntracks_per_event, ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]);
//Fill Histograms
void       Fill_histo_tracks(TFile    *f_out, ALLTRACK_STRUCT tra2[max_tra_ev], int      ntracks_per_event);



};

#endif
