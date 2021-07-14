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
#include <cstdlib> 


 double    pigreco = TMath::Pi();

 int       less_entries  =   2000;

//Pointer to Class Objects 
TRandom2 *casos = new TRandom2();
Evento           *Ev; 
Initialization   *init; 
Booking          *b;
Init_in_each_event  *init_each_event;
Generation       *gene;
Reconstruction   *reco;





#endif
