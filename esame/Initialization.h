#ifndef Initialization_H
#define Initialization_H

#include <iostream>
#include <fstream>
#include "TObject.h"
#include <TTree.h>
#include <TFile.h>
#include <TROOT.h>
#include "TLorentzRotation.h" 
#include <TVector3.h>
#include "TVector2.h"
#include "TChain.h"
#include "Evento.h"


using namespace std;

class Initialization {


private:
   
  int status;	
  int current_event;
  int number_of_input_files;
  vector<string> list_of_input_files;

  TString                  filenameroot_out;
  TString                  file_input_dat;
  TFile                    *f_out;
  FILE                     *pfiles_input_dat;  
  TChain                   *chain_t;
  EVENTO_STRUCT            *pevstr; //event
 
  
  int A_beam;
  int cha_beam;
  float kin_nucleon;
  float gamma_beam;
  float beta_beam;
  TLorentzRotation         lambda; 
  
   
   double par[11]; 

public:
  	Initialization(){
  }; //Constructor

  ~Initialization(){
  }; //Destructor
  

 
  //Function prototype implemented in .cpp
  
  void Initialize_all(); 
  void Openfiles();
  void parameter();
  TFile *getF_out();
  EVENTO_STRUCT *getPevstr();
  TChain *getTchain();
  int getCurrent_event();
  double* getPar();
  void setCurrent_event(int b);
  void setStatus(int a);
  


};
#endif
