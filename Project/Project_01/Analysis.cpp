#include "Evento.h"
#include "Initialization.h"
#include "Booking.h"
#include "Init_in_each_event.h"
#include "Generation.h"  
#include "Reconstruction.h"   
#include "Analysis.h"

using namespace std;
using namespace TMath;
extern TStyle*  gStyle;  


int main(int argc, char *argv[]){
	
  gStyle->SetPalette(1);
  gROOT->SetStyle("Plain");
  gStyle->SetMarkerStyle(6);
  gStyle->SetOptFit(11111111);
  gStyle->SetOptStat(11111111);
 
  casos->SetSeed(1234); //random generation
 
  //Initialization
  init = new Initialization();
  init->Initialize_all();
  init->Openfiles(); //Open rootFile inputData and create output file
  init->parameter();//parameter detector initialization
  
  //Booking -> Canvas Plot
  b = new Booking();
  b->booking_gen(init->getF_out()); // plot of generation class
  b->booking_rec(init->getF_out());// plot of reconstruction class
 
  //Event 
  Ev = new Evento();  
  init->setStatus(Ev->FindBranches(init->getTchain(),init->getPevstr())); 
  
  
  for (int kk = 0; kk<init->getTchain()->GetEntries(); kk++){    
    //for (int kk = 0; kk<less_entries; kk++){  //just to test the code on few entries
    init->setCurrent_event(init->getCurrent_event()+1); 
    if(kk%100000==0){ cout<<"Processed event = "<<kk<<endl;} //to follow each step at runtime

    init->setStatus(Ev->Clean());    
    init->getTchain()->GetEntry(kk);
    
    //Initialization of all parameters in each event
	init_each_event= new Init_in_each_event();    
    init_each_event->Initialize_in_each_event();                      
    
	//Generation Analysis - MonteCarlo
	gene = new Generation();
	gene->Fill_all_gen(init->getPevstr(), init->getF_out(), init_each_event->getTra2(), init_each_event->tra_frag);
	
	//Reconstruction Analysis - real case
   reco = new Reconstruction();
   reco->Fill_all_rec(casos, init->getPevstr(), init_each_event->getTra2(), gene->getindex(), gene->getntrack(), init->getF_out(), init->getPar(), init_each_event->tra_frag);
   
   
   
   //Deallocate a block of memory associated with each class at the end of the process
	delete init_each_event;
	delete gene;
	delete reco;
	}  
  
  
  
   init->getF_out()->Write(); //write on the output file
   init->getF_out()->Close(); // close the output file
  
  
  
  
   //Deallocate a block of memory
   delete init; 
   delete b;
   delete casos;
  
   
  return 0;
  
}//end of main




