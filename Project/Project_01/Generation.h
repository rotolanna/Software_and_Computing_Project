#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include <TStyle.h>
#include <TMath.h>
#include <TSystem.h>
#include <TCanvas.h>
#include "TChain.h"
#include "TMatrixD.h"
#include "TDecompLU.h"


#include "Booking.h"



using namespace std;

class Generation  {

private:
	 int      ntracks_per_event =   0;
     int      index_tracks[max_tra_ev];
	 int      current_track;
	 int      current_fragment;//max value = max NUMFRAG
     
	 
	 TFile    *f_out;
	 TH1D *h;
	 TH2D *h2;
	 ALLTRACK_STRUCT tra2[max_tra_ev]; 
	
    
    
//NUMFRAG                                             0    1    2    3     4     5     6     7    8    9     10 
//                                                    H   He   Li   Be     B     C     N     O    D    T    He3
int                      charge_gen_frag[NUMFRAG] = {1,   2,   3,   4,    5,    6,    7,    8,   1,   1,   2 }; 
float                    A_gen_frag[NUMFRAG]      = {1.,  4.,  7.,  9.,  11.,  12.,  14.,  16.,  2.,  3.,  3.}; 
int                      fluka_gen[NUMFRAG]       = {1,  -6,  -2,  -2,   -2,   -2,   -2,   -2,  -3,  -4,  -5};
                         //N.B. FLUKA ---> Energy  in GeV, Lenght in cm and Time in ns 
    
    
public:
  
  
  ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]; 
  
  Generation(){
  }; //constructor

  ~Generation(){
  }; //destructor
  
	
	//Methods implemented in Generation:
	
	void Fill_all_gen(EVENTO_STRUCT *pevstr, TFile    *f_out, ALLTRACK_STRUCT tra2[max_tra_ev], ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]);
	void Find_index_tracks_all_detectors(EVENTO_STRUCT *pevstr);
    void Fill_tracks(EVENTO_STRUCT *pevstr, ALLTRACK_STRUCT tra2[max_tra_ev]);
	void Fill_tracks_frag( ALLTRACK_STRUCT tra2[max_tra_ev],  ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]);
    void Fill_histo_tracks(TFile *f_out, ALLTRACK_STRUCT tra2[max_tra_ev], ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]);
    int* getindex();
    int  getntrack();
    
    ALLTRACK_STRUCT* getTra2();
   
};






#endif
