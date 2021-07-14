#ifndef CONSTANT_H
#define CONSTANT_H

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
 

 const int	              max_tra_ev    =   20;
 const int                NUMCHARGE     =   9;
 const int                ALL_A         =   20;
 const int                NUMFRAG       =   11; 
 const double             massa_e       =   0.5109989461e-3;  // in Gev
 const double             MASSA_U       =   0.93149432;   // in GeV
 const double             CLIGHT        =   29.9792458;    // in cm/ns
 
const double             K              =   0.307075; //4*pi*Na*re^2*me*c^2   [MeV cm2/g]
const double             Iscint         =   64.684e-9;   // in GeV
const double             scint_thick    =   0.3; //in cm
const int                nscint         =   2; // # of layers
const double             scint_density  =   1.023; //g/cm^3
const double             scint_ZsuA     =   0.54157;







 
#endif
