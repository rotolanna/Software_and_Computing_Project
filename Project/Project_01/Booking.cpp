#include "Booking.h"


using namespace std;

ClassImp(Booking);

//---------- PLOT GENERATION --------------------------------------

int Booking::booking_gen(TFile *f_out){ 

  char nam[200], tit[200];  
 
  f_out->mkdir("GENERATION");
  f_out->cd("GENERATION");
  
    snprintf(nam, 200, "hP_gen"); 
	snprintf(tit, 200, "momento traccia"); 
	k1  = new TH1D(nam, tit,500, 0.,20.); 
  
  
    snprintf(nam, 200, "hZ_gen");
    snprintf(tit, 200, "Z_gen");
    h = new TH1D(nam, tit, 500, 0., 10.);
    
    snprintf(nam, 200, "hA_gen vs Z_gen"); 
    snprintf(tit, 200, "A_gen vs Z_gen");
    h2 = new TH2D(nam, tit, 500, 0., 10., 500, 0., 20.);
    h2->GetXaxis()->SetTitle("Z_gen"); h2->GetYaxis()->SetTitle("A_gen");
    
    
    
for(int ii = 0; ii<NUMFRAG; ii++){ 
    snprintf(nam, 200, "hA_gen_frag_%d", ii); //A_generated for each fragments
	snprintf(tit, 200, "A_gen_frag_%d",  ii); 
	k = new TH1D(nam, tit, 500, 0., 20.);
	
	snprintf(nam, 200, "hkine_energy_gen_%d", ii); 
	snprintf(tit, 200, "kine_energy_gen_per_nucleon_frag_%d",  ii);
    h = new TH1D(nam, tit, 500, 0., 500.);
   
   
   
}

  

  f_out->cd("..");
  
  return 0;
}


//---------- PLOT RECONSTRUCTION --------------------------------------

int Booking::booking_rec(TFile *f_out){ 

  char nam[200], tit[200];  

  f_out->mkdir("RECONSTRUCTION");
  f_out->cd("RECONSTRUCTION");
  
    snprintf(nam, 200, "hTOF_Smearing_reco");
    snprintf(tit, 200, "TOF_Smearing_reco");
    h = new TH1D(nam, tit, 100, 0., 14);
    h->SetLineColor(kRed);
    
    snprintf(nam, 200, "hTOF_reco");
    snprintf(tit, 200, "TOF_reco");
    k = new TH1D(nam, tit, 100, 0., 14);
    
    snprintf(nam, 200, "hE_depo_scint_reco");
    snprintf(tit, 200, "E_depo_scint_reco");
    l = new TH1D(nam, tit, 500, 0., 250);
    
    
    
    snprintf(nam, 200, "hE_depo_smearing_reco");//scintillator
    snprintf(tit, 200, "E_depo_smearing_reco");
    m = new TH1D(nam, tit, 500, 0., 250);
    m->SetLineColor(kRed);
    
    
    
    snprintf(nam, 200, "hMomentum");
    snprintf(tit, 200, "Momentum_reco");
    b = new TH1D(nam, tit, 500, 0., 15);
   
    snprintf(nam, 200, "hMomentum_sm"); //smearing momentum plot
    snprintf(tit, 200, "Momentum_sm_reco");
    d = new TH1D(nam, tit, 500, 0., 15);
    d->SetLineColor(kRed);
    
    
    
    //plot of all charges
    snprintf(nam, 200, "hZ_reco");
    snprintf(tit, 200, " ");
    n = new TH1D(nam, tit, 500, 0., 10);
    
    
    //plot of each charge
    for (int i=1; i<=8; i++) {

    snprintf (nam, 200, "hZrec %d", i); snprintf(tit, 200, " ");

    c = new TH1D (nam, tit, 500, 0.,12.); 
    c->GetXaxis()->SetTitle("Z_reco");
    c->GetYaxis()->SetTitle("Events");
    
 } 
  

 

 //Mass_plot with 3 methodes

	//--------------- Hydrogen--------------------------
        snprintf (nam, 200, "hA_rec_mass_A1_H"); 
		snprintf(tit, 200, " ");
        e = new TH1D (nam, tit, 500, 0.,20.);
        e->GetXaxis()->SetTitle("A_reco");
       
        snprintf (nam, 200, "hA_rec_mass_A2_H"); 
		snprintf(tit, 200, " ");
        l1 = new TH1D (nam, tit, 500, 0.,20.);
        l1->GetXaxis()->SetTitle("A_reco");
        
        snprintf (nam, 200, "hA_rec_mass_A3_H"); 
		snprintf(tit, 200, " ");
        l2 = new TH1D (nam, tit, 500, 0.,20.);
        l2->GetXaxis()->SetTitle("A_reco");
        
    //-------------Helium ------------------------------    
        snprintf (nam, 200, "hA_rec_mass_A1_He"); 
		snprintf(tit, 200, " ");
        k2 = new TH1D (nam, tit, 500, 0.,20.);
        k2->GetXaxis()->SetTitle("A_reco");
        
        snprintf (nam, 200, "hA_rec_mass_A2_He"); 
		snprintf(tit, 200, " ");
        l3 = new TH1D (nam, tit, 500, 0.,20.);
        l3->GetXaxis()->SetTitle("A_reco");
        
        snprintf (nam, 200, "hA_rec_mass_A3_He"); 
		snprintf(tit, 200, " ");
        l4 = new TH1D (nam, tit, 500, 0.,20.);
        l4->GetXaxis()->SetTitle("A_reco");
        
    //----------------Lithium --------------------------    
        snprintf (nam, 200, "hA_rec_mass_A1_Li"); 
		snprintf(tit, 200, " ");
        k3 = new TH1D (nam, tit, 500, 0.,20.);
        k3->GetXaxis()->SetTitle("A_reco");
       
       snprintf (nam, 200, "hA_rec_mass_A2_Li"); 
		snprintf(tit, 200, " ");
        l5 = new TH1D (nam, tit, 500, 0.,20.);
        l5->GetXaxis()->SetTitle("A_reco");
        
        snprintf (nam, 200, "hA_rec_mass_A3_Li"); 
		snprintf(tit, 200, " ");
        l6 = new TH1D (nam, tit, 500, 0.,20.);
        l6->GetXaxis()->SetTitle("A_reco");
        
     //------------------ Berillium -------------------

       snprintf (nam, 200, "hA_rec_mass_A1_Be"); 
	   snprintf(tit, 200, " ");
       k4 = new TH1D (nam, tit, 500, 0.,20.);
       k4->GetXaxis()->SetTitle("A_reco");
       
       snprintf (nam, 200, "hA_rec_mass_A2_Be"); 
	   snprintf(tit, 200, " ");
       h3 = new TH1D (nam, tit, 500, 0.,20.);
       h3->GetXaxis()->SetTitle("A_reco");
       
       snprintf (nam, 200, "hA_rec_mass_A3_Be"); 
	   snprintf(tit, 200, " ");
       h4 = new TH1D (nam, tit, 500, 0.,20.);
       h4->GetXaxis()->SetTitle("A_reco");
       
    //---------------Boron-------------------------
       snprintf (nam, 200, "hA_rec_mass_A1_B"); 
	   snprintf(tit, 200, " ");
       k5 = new TH1D (nam, tit, 500, 0.,20.);
       k5->GetXaxis()->SetTitle("A_reco");
       
       
       snprintf (nam, 200, "hA_rec_mass_A2_B"); 
	   snprintf(tit, 200, " ");
       h5 = new TH1D (nam, tit, 500, 0.,20.);
       h5->GetXaxis()->SetTitle("A_reco");
       
       
       snprintf (nam, 200, "hA_rec_mass_A3_B"); 
	   snprintf(tit, 200, " ");
       h6 = new TH1D (nam, tit, 500, 0.,20.);
       h6->GetXaxis()->SetTitle("A_reco");

    //-------------Carbon---------------------------
       snprintf (nam, 200, "hA_rec_mass_A1_C"); 
	   snprintf(tit, 200, " ");
       k6 = new TH1D (nam, tit, 500, 0.,20.);
       k6->GetXaxis()->SetTitle("A_reco");
       
       snprintf (nam, 200, "hA_rec_mass_A2_C"); 
	   snprintf(tit, 200, " ");
       h7 = new TH1D (nam, tit, 500, 0.,20.);
       h7->GetXaxis()->SetTitle("A_reco");
       
       snprintf (nam, 200, "hA_rec_mass_A3_C"); 
	   snprintf(tit, 200, " ");
       h8 = new TH1D (nam, tit, 500, 0.,20.);
       h8->GetXaxis()->SetTitle("A_reco");
    
    //-------------Nitrogen------------------------
       snprintf (nam, 200, "hA_rec_mass_A1_N"); 
	   snprintf(tit, 200, " ");
       k7 = new TH1D (nam, tit, 500, 0.,20.);
       k7->GetXaxis()->SetTitle("A_reco");
       
       snprintf (nam, 200, "hA_rec_mass_A2_N"); 
	   snprintf(tit, 200, " ");
       h9 = new TH1D (nam, tit, 500, 0.,30.);
       h9->GetXaxis()->SetTitle("A_reco");
      
       snprintf (nam, 200, "hA_rec_mass_A3_N"); 
	   snprintf(tit, 200, " ");
       k9 = new TH1D (nam, tit, 500, 0.,30.);
       k9->GetXaxis()->SetTitle("A_reco");
       
       
    //--------------0xygen------------------------
       snprintf (nam, 200, "hA_rec_mass_A1_O"); 
	   snprintf(tit, 200, " ");
       k8 = new TH1D (nam, tit, 500, 0.,20.);
       k8->GetXaxis()->SetTitle("A_reco");
      
       snprintf (nam, 200, "hA_rec_mass_A2_O"); 
	   snprintf(tit, 200, " ");
       m1 = new TH1D (nam, tit, 500, 0.,30.);
       m1->GetXaxis()->SetTitle("A_reco");
       
       snprintf (nam, 200, "hA_rec_mass_A3_O"); 
	   snprintf(tit, 200, " ");
       m2 = new TH1D (nam, tit, 500, 0.,30.);
       m2->GetXaxis()->SetTitle("A_reco");
       
       

    

  f_out->cd("..");
  
  return 0;
}
