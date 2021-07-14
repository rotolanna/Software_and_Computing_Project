#ifndef Booking_H
#define Booking_H

#include <TH1D.h>
#include <TH2D.h>
#include "Initialization.h"
#include "Init_in_each_event.h"



using namespace std;

class Booking {
	
private:
	
	TFile *f_out;
    TH1D *h, *k, *l, *m, *n, *c, *a, *b, *d, *e, *i,*o,*k1, *k2, *k3, *m1, *m3;
    TH1D *k4, *k5, *k6, *k7, *k8, *k9, *h1, *m2,*h3, *h4, *h5, *h6, *h7, *h8, *h9, *l1, *l2, *l3, *l4, *l5, *l6;
    TH2D *h2;
     
public:

  Booking(){
  }; //constructor

  ~Booking(){
  }; //destructor
 
 //-------------Function Prototypes-----------
  
    int booking_gen(TFile *f_out);
    int booking_rec(TFile *f_out);
   
	
};
#endif
