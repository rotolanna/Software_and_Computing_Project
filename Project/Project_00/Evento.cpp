#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Evento.h"

using namespace std;

ClassImp(Evento);

/*-----------------------------------------------------------------*/
  
Evento::Evento()
{
  eve.TRn    = 0;
  eve.STCn    = 0;
  eve.VTXn    = 0;
  eve.ITRn    = 0;
  eve.BMNn    = 0;
  eve.MSDn    = 0;
  eve.SCNn    = 0;
  eve.CALn    = 0;
  eve.CROSSn  = 0;

  for(int kk=0;kk<MAXTR;kk++){
    eve.TRpaid[kk]   = 0;
    eve.TRgen[kk]    = 0;
    eve.TRcha[kk]    = -100;
    eve.TRreg[kk]    = 0;
    eve.TRbar[kk]    = 0;
    eve.TRdead[kk]   = 0;
    eve.TRfid[kk]    = -100;
    eve.TRix[kk]     = 0.;
    eve.TRiy[kk]     = 0.;
    eve.TRiz[kk]     = 0.;
    eve.TRfx[kk]     = 0.;
    eve.TRfy[kk]     = 0.;
    eve.TRfz[kk]     = 0.;
    eve.TRipx[kk]    = 0.;
    eve.TRipy[kk]    = 0.;
    eve.TRipz[kk]    = 0.;
    eve.TRfpx[kk]    = 0.;
    eve.TRfpy[kk]    = 0.;
    eve.TRfpz[kk]    = 0.;
    eve.TRmass[kk]   = 0.;
    eve.TRtime[kk]   = 0.;
    eve.TRtof[kk]    = 0.;
    eve.TRtrlen[kk]  = 0.;
  }

  for(int kk=0;kk<MAXSTC;kk++){
    eve.STCid[kk]    = 0;
    eve.STCxin[kk]   = 0.;
    eve.STCyin[kk]   = 0.;
    eve.STCzin[kk]   = 0.;
    eve.STCxout[kk]  = 0.;
    eve.STCyout[kk]  = 0.;
    eve.STCzout[kk]  = 0.;
    eve.STCpxin[kk]  = 0.;
    eve.STCpyin[kk]  = 0.;
    eve.STCpzin[kk]  = 0.;
    eve.STCpxout[kk] = 0.;
    eve.STCpyout[kk] = 0.;
    eve.STCpzout[kk] = 0.;
    eve.STCde[kk]    = 0.;
    eve.STCal[kk]    = 0.;
    eve.STCtim[kk]   = 0.;
  }
  
  for(int kk=0;kk<MAXBMN;kk++){
    eve.BMNid[kk]    = 0;
    eve.BMNilay[kk]  = 0;
    eve.BMNiview[kk] = 0;
    eve.BMNicell[kk] = 0;
    eve.BMNxin[kk]   = 0.;
    eve.BMNyin[kk]   = 0.;
    eve.BMNzin[kk]   = 0.;
    eve.BMNxout[kk]  = 0.;
    eve.BMNyout[kk]  = 0.;
    eve.BMNzout[kk]  = 0.;
    eve.BMNpxin[kk]  = 0.;
    eve.BMNpyin[kk]  = 0.;
    eve.BMNpzin[kk]  = 0.;
    eve.BMNpxout[kk] = 0.;
    eve.BMNpyout[kk] = 0.;
    eve.BMNpzout[kk] = 0.;
    eve.BMNde[kk]    = 0.;
    eve.BMNal[kk]    = 0.;
    eve.BMNtim[kk]   = 0.;
  }
  
  for(int kk=0;kk<MAXVTX;kk++){
    eve.VTXid[kk]    = 0;
    eve.VTXilay[kk]  = 0;
    eve.VTXirow[kk]  = 0;
    eve.VTXicol[kk]  = 0;
    eve.VTXxin[kk]   = 0.;
    eve.VTXyin[kk]   = 0.;
    eve.VTXzin[kk]   = 0.;
    eve.VTXxout[kk]  = 0.;
    eve.VTXyout[kk]  = 0.;
    eve.VTXzout[kk]  = 0.;
    eve.VTXpxin[kk]  = 0.;
    eve.VTXpyin[kk]  = 0.;
    eve.VTXpzin[kk]  = 0.;
    eve.VTXpxout[kk] = 0.;
    eve.VTXpyout[kk] = 0.;
    eve.VTXpzout[kk] = 0.;
    eve.VTXde[kk]    = 0.;
    eve.VTXal[kk]    = 0.;
    eve.VTXtim[kk]   = 0.;
  }

  for(int kk=0;kk<MAXITR;kk++){
    eve.ITRid[kk]    = 0;
    eve.ITRilay[kk]  = 0;
    eve.ITRirow[kk]  = 0;
    eve.ITRicol[kk]  = 0;
    eve.ITRxin[kk]   = 0.;
    eve.ITRyin[kk]   = 0.;
    eve.ITRzin[kk]   = 0.;
    eve.ITRxout[kk]  = 0.;
    eve.ITRyout[kk]  = 0.;
    eve.ITRzout[kk]  = 0.;
    eve.ITRpxin[kk]  = 0.;
    eve.ITRpyin[kk]  = 0.;
    eve.ITRpzin[kk]  = 0.;
    eve.ITRpxout[kk] = 0.;
    eve.ITRpyout[kk] = 0.;
    eve.ITRpzout[kk] = 0.;
    eve.ITRde[kk]    = 0.;
    eve.ITRal[kk]    = 0.;
    eve.ITRtim[kk]   = 0.;
  }

  for(int kk=0;kk<MAXMSD;kk++){
    eve.MSDid[kk]    = 0;
    eve.MSDilay[kk]  = 0;
    eve.MSDiview[kk] = 0;
    //    eve.MSDicell[kk] = 0;
    eve.MSDistrip[kk] = 0;
    eve.MSDxin[kk]   = 0.;
    eve.MSDyin[kk]   = 0.;
    eve.MSDzin[kk]   = 0.;
    eve.MSDxout[kk]  = 0.;
    eve.MSDyout[kk]  = 0.;
    eve.MSDzout[kk]  = 0.;
    eve.MSDpxin[kk]  = 0.;
    eve.MSDpyin[kk]  = 0.;
    eve.MSDpzin[kk]  = 0.;
    eve.MSDpxout[kk] = 0.;
    eve.MSDpyout[kk] = 0.;
    eve.MSDpzout[kk] = 0.;
    eve.MSDde[kk]    = 0.;
    eve.MSDal[kk]    = 0.;
    eve.MSDtim[kk]   = 0.;
  }
  
  for(int kk=0;kk<MAXSCN;kk++){
    eve.SCNid[kk]     = 0;
    eve.SCNistrip[kk] = 0;
    eve.SCNiview[kk]  = 0;
    eve.SCNxin[kk]    = 0.;
    eve.SCNyin[kk]    = 0.;
    eve.SCNzin[kk]    = 0.;
    eve.SCNxout[kk]   = 0.;
    eve.SCNyout[kk]   = 0.;
    eve.SCNzout[kk]   = 0.;
    eve.SCNpxin[kk]   = 0.;
    eve.SCNpyin[kk]   = 0.;
    eve.SCNpzin[kk]   = 0.;
    eve.SCNpxout[kk]  = 0.;
    eve.SCNpyout[kk]  = 0.;
    eve.SCNpzout[kk]  = 0.;
    eve.SCNde[kk]     = 0.;
    eve.SCNal[kk]     = 0.;
    eve.SCNtim[kk]    = 0.;
  }

  for(int kk=0;kk<MAXCAL;kk++){
    eve.CALid[kk]    = 0;
    eve.CALicry[kk]  = 0;
    eve.CALxin[kk]   = 0.;
    eve.CALyin[kk]   = 0.;
    eve.CALzin[kk]   = 0.;
    eve.CALxout[kk]  = 0.;
    eve.CALyout[kk]  = 0.;
    eve.CALzout[kk]  = 0.;
    eve.CALpxin[kk]  = 0.;
    eve.CALpyin[kk]  = 0.;
    eve.CALpzin[kk]  = 0.;
    eve.CALpxout[kk] = 0.;
    eve.CALpyout[kk] = 0.;
    eve.CALpzout[kk] = 0.;
    eve.CALde[kk]    = 0.;
    eve.CALal[kk]    = 0.;
    eve.CALtim[kk]   = 0.;    
  }

  for(int kk=0;kk<MAXCROSS;kk++){
    eve.CROSSid[kk]      = 0;
    eve.CROSSnreg[kk]    = 0;
    eve.CROSSnregold[kk] = 0;
    eve.CROSSx[kk]       = 0.;
    eve.CROSSy[kk]       = 0.;
    eve.CROSSz[kk]       = 0.;
    eve.CROSSpx[kk]      = 0.;
    eve.CROSSpy[kk]      = 0.;
    eve.CROSSpz[kk]      = 0.;
    eve.CROSSm[kk]       = 0.;
    eve.CROSSch[kk]      = 0.;
    eve.CROSSt[kk]       = 0.;
  }

}


Int_t Evento::Clean(){
  //  cout <<" Entro in clean"<<endl;

  for(int kk=0;kk<eve.TRn;kk++){
    eve.TRpaid[kk]  = 0;
    eve.TRgen[kk]   = 0;
    eve.TRcha[kk]   = -100;
    eve.TRreg[kk]   = 0;
    eve.TRbar[kk]   = 0;
    eve.TRdead[kk]  = 0;
    eve.TRfid[kk]   = -100;
    eve.TRix[kk]    = 0.;
    eve.TRiy[kk]    = 0.;
    eve.TRiz[kk]    = 0.;
    eve.TRfx[kk]    = 0.;
    eve.TRfy[kk]    = 0.;
    eve.TRfz[kk]    = 0.;
    eve.TRipx[kk]   = 0.;
    eve.TRipy[kk]   = 0.;
    eve.TRipz[kk]   = 0.;
    eve.TRfpx[kk]   = 0.;
    eve.TRfpy[kk]   = 0.;
    eve.TRfpz[kk]   = 0.;
    eve.TRmass[kk]  = 0.;
    eve.TRtime[kk]  = 0.;
    eve.TRtof[kk]   = 0.;
    eve.TRtrlen[kk] = 0.;
  }

  for(int kk=0;kk<eve.STCn;kk++){
    eve.STCid[kk]    = 0;
    eve.STCxin[kk]   = 0.;
    eve.STCyin[kk]   = 0.;
    eve.STCzin[kk]   = 0.;
    eve.STCxout[kk]  = 0.;
    eve.STCyout[kk]  = 0.;
    eve.STCzout[kk]  = 0.;
    eve.STCpxin[kk]  = 0.;
    eve.STCpyin[kk]  = 0.;
    eve.STCpzin[kk]  = 0.;
    eve.STCpxout[kk] = 0.;
    eve.STCpyout[kk] = 0.;
    eve.STCpzout[kk] = 0.;
    eve.STCde[kk]    = 0.;
    eve.STCal[kk]    = 0.;
    eve.STCtim[kk]   = 0.;
  }
  
  for(int kk=0;kk<eve.BMNn;kk++){
    eve.BMNid[kk]    = 0;
    eve.BMNilay[kk]  = 0;
    eve.BMNiview[kk] = 0;
    eve.BMNicell[kk] = 0;
    eve.BMNxin[kk]   = 0.;
    eve.BMNyin[kk]   = 0.;
    eve.BMNzin[kk]   = 0.;
    eve.BMNxout[kk]  = 0.;
    eve.BMNyout[kk]  = 0.;
    eve.BMNzout[kk]  = 0.;
    eve.BMNpxin[kk]  = 0.;
    eve.BMNpyin[kk]  = 0.;
    eve.BMNpzin[kk]  = 0.;
    eve.BMNpxout[kk] = 0.;
    eve.BMNpyout[kk] = 0.;
    eve.BMNpzout[kk] = 0.;
    eve.BMNde[kk]    = 0.;
    eve.BMNal[kk]    = 0.;
    eve.BMNtim[kk]   = 0.;
  }

  for(int kk=0;kk<eve.VTXn;kk++){
    eve.VTXid[kk]    = 0;
    eve.VTXilay[kk]  = 0;
    eve.VTXirow[kk]  = 0;
    eve.VTXicol[kk]  = 0;
    eve.VTXxin[kk]   = 0.;
    eve.VTXyin[kk]   = 0.;
    eve.VTXzin[kk]   = 0.;
    eve.VTXxout[kk]  = 0.;
    eve.VTXyout[kk]  = 0.;
    eve.VTXzout[kk]  = 0.;
    eve.VTXpxin[kk]  = 0.;
    eve.VTXpyin[kk]  = 0.;
    eve.VTXpzin[kk]  = 0.;
    eve.VTXpxout[kk] = 0.;
    eve.VTXpyout[kk] = 0.;
    eve.VTXpzout[kk] = 0.;
    eve.VTXde[kk]    = 0.;
    eve.VTXal[kk]    = 0.;
    eve.VTXtim[kk]   = 0.;
  }

  for(int kk=0;kk<eve.ITRn;kk++){
    eve.ITRid[kk]    = 0;
    eve.ITRilay[kk]  = 0;
    eve.ITRirow[kk]  = 0;
    eve.ITRicol[kk]  = 0;
    eve.ITRxin[kk]   = 0.;
    eve.ITRyin[kk]   = 0.;
    eve.ITRzin[kk]   = 0.;
    eve.ITRxout[kk]  = 0.;
    eve.ITRyout[kk]  = 0.;
    eve.ITRzout[kk]  = 0.;
    eve.ITRpxin[kk]  = 0.;
    eve.ITRpyin[kk]  = 0.;
    eve.ITRpzin[kk]  = 0.;
    eve.ITRpxout[kk] = 0.;
    eve.ITRpyout[kk] = 0.;
    eve.ITRpzout[kk] = 0.;
    eve.ITRde[kk]    = 0.;
    eve.ITRal[kk]    = 0.;
    eve.ITRtim[kk]   = 0.;
  }

  for(int kk=0;kk<eve.MSDn;kk++){
    eve.MSDid[kk]    = 0;
    eve.MSDilay[kk]  = 0;
    eve.MSDiview[kk] = 0;
    //    eve.MSDicell[kk] = 0;
    eve.MSDistrip[kk] = 0;
    eve.MSDxin[kk]   = 0.;
    eve.MSDyin[kk]   = 0.;
    eve.MSDzin[kk]   = 0.;
    eve.MSDxout[kk]  = 0.;
    eve.MSDyout[kk]  = 0.;
    eve.MSDzout[kk]  = 0.;
    eve.MSDpxin[kk]  = 0.;
    eve.MSDpyin[kk]  = 0.;
    eve.MSDpzin[kk]  = 0.;
    eve.MSDpxout[kk] = 0.;
    eve.MSDpyout[kk] = 0.;
    eve.MSDpzout[kk] = 0.;
    eve.MSDde[kk]    = 0.;
    eve.MSDal[kk]    = 0.;
    eve.MSDtim[kk]   = 0.;
  }

  for(int kk=0;kk<eve.SCNn;kk++){
    eve.SCNid[kk]     = 0;
    eve.SCNistrip[kk] = 0;
    eve.SCNiview[kk]  = 0;
    eve.SCNxin[kk]    = 0.;
    eve.SCNyin[kk]    = 0.;
    eve.SCNzin[kk]    = 0.;
    eve.SCNxout[kk]   = 0.;
    eve.SCNyout[kk]   = 0.;
    eve.SCNzout[kk]   = 0.;
    eve.SCNpxin[kk]   = 0.;
    eve.SCNpyin[kk]   = 0.;
    eve.SCNpzin[kk]   = 0.;
    eve.SCNpxout[kk]  = 0.;
    eve.SCNpyout[kk]  = 0.;
    eve.SCNpzout[kk]  = 0.;
    eve.SCNde[kk]     = 0.;
    eve.SCNal[kk]     = 0.;
    eve.SCNtim[kk]    = 0.;
  }
  
  for(int kk=0;kk<eve.CALn;kk++){
    eve.CALid[kk]    = 0;
    eve.CALicry[kk]  = 0;
    eve.CALxin[kk]   = 0.;
    eve.CALyin[kk]   = 0.;
    eve.CALzin[kk]   = 0.;
    eve.CALxout[kk]  = 0.;
    eve.CALyout[kk]  = 0.;
    eve.CALzout[kk]  = 0.;
    eve.CALpxin[kk]  = 0.;
    eve.CALpyin[kk]  = 0.;
    eve.CALpzin[kk]  = 0.;
    eve.CALpxout[kk] = 0.;
    eve.CALpyout[kk] = 0.;
    eve.CALpzout[kk] = 0.;
    eve.CALde[kk]    = 0.;
    eve.CALal[kk]    = 0.;
    eve.CALtim[kk]   = 0.;    
  }
  
  for(int kk=0;kk<eve.CROSSn;kk++){
    eve.CROSSid[kk]      = 0;
    eve.CROSSnreg[kk]    = 0;
    eve.CROSSnregold[kk] = 0;
    eve.CROSSx[kk]       = 0.;
    eve.CROSSy[kk]       = 0.;
    eve.CROSSz[kk]       = 0.;
    eve.CROSSpx[kk]      = 0.;
    eve.CROSSpy[kk]      = 0.;
    eve.CROSSpz[kk]      = 0.;
    eve.CROSSm[kk]       = 0.;
    eve.CROSSch[kk]      = 0.;
    eve.CROSSt[kk]       = 0.;
  }

  eve.EventNumber = 0;
  eve.TRn       = 0;
  eve.STCn      = 0;
  eve.VTXn      = 0;
  eve.BMNn      = 0;
  eve.MSDn      = 0;
  eve.SCNn      = 0;
  eve.CALn      = 0;
  eve.CROSSn    = 0;
  
  return 0;
}


//int Evento::FindBranches(TTree *RootTree, EVENTO_STRUCT *eve){
int Evento::FindBranches(TChain *RootTree, EVENTO_STRUCT *eve){

  RootTree->SetBranchAddress("EventNumber",&(eve->EventNumber));
  RootTree->SetBranchAddress("TRn",&(eve->TRn));
  RootTree->SetBranchAddress("TRpaid",&(eve->TRpaid));
  RootTree->SetBranchAddress("TRgen",&(eve->TRgen));
  RootTree->SetBranchAddress("TRcha",&(eve->TRcha));
  RootTree->SetBranchAddress("TRreg",&(eve->TRreg));
  RootTree->SetBranchAddress("TRbar",&(eve->TRbar));
  RootTree->SetBranchAddress("TRdead",&(eve->TRdead));
  RootTree->SetBranchAddress("TRfid",&(eve->TRfid));
  RootTree->SetBranchAddress("TRix",&(eve->TRix));
  RootTree->SetBranchAddress("TRiy",&(eve->TRiy));
  RootTree->SetBranchAddress("TRiz",&(eve->TRiz));
  RootTree->SetBranchAddress("TRfx",&(eve->TRfx));
  RootTree->SetBranchAddress("TRfy",&(eve->TRfy));
  RootTree->SetBranchAddress("TRfz",&(eve->TRfz));
  RootTree->SetBranchAddress("TRipx",&(eve->TRipx));
  RootTree->SetBranchAddress("TRipy",&(eve->TRipy));
  RootTree->SetBranchAddress("TRipz",&(eve->TRipz));
  RootTree->SetBranchAddress("TRfpx",&(eve->TRfpx));
  RootTree->SetBranchAddress("TRfpy",&(eve->TRfpy));
  RootTree->SetBranchAddress("TRfpz",&(eve->TRfpz));
  RootTree->SetBranchAddress("TRmass",&(eve->TRmass));
  RootTree->SetBranchAddress("TRtime",&(eve->TRtime));
  RootTree->SetBranchAddress("TRtof",&(eve->TRtof));
  RootTree->SetBranchAddress("TRtrlen",&(eve->TRtrlen));

  RootTree->SetBranchAddress("STCn",&(eve->STCn));
  RootTree->SetBranchAddress("STCid",&(eve->STCid));
  RootTree->SetBranchAddress("STCxin",&(eve->STCxin));
  RootTree->SetBranchAddress("STCyin",&(eve->STCyin));
  RootTree->SetBranchAddress("STCzin",&(eve->STCzin));
  RootTree->SetBranchAddress("STCpxin",&(eve->STCpxin));
  RootTree->SetBranchAddress("STCpyin",&(eve->STCpyin));
  RootTree->SetBranchAddress("STCpzin",&(eve->STCpzin));
  RootTree->SetBranchAddress("STCxout",&(eve->STCxout));
  RootTree->SetBranchAddress("STCyout",&(eve->STCyout));
  RootTree->SetBranchAddress("STCzout",&(eve->STCzout));
  RootTree->SetBranchAddress("STCpxout",&(eve->STCpxout));
  RootTree->SetBranchAddress("STCpyout",&(eve->STCpyout));
  RootTree->SetBranchAddress("STCpzout",&(eve->STCpzout));
  RootTree->SetBranchAddress("STCde",&(eve->STCde));
  RootTree->SetBranchAddress("STCal",&(eve->STCal));
  RootTree->SetBranchAddress("STCtim",&(eve->STCtim));

  RootTree->SetBranchAddress("BMNn",&(eve->BMNn));
  RootTree->SetBranchAddress("BMNid",&(eve->BMNid));
  RootTree->SetBranchAddress("BMNilay",&(eve->BMNilay));
  RootTree->SetBranchAddress("BMNiview",&(eve->BMNiview));
  RootTree->SetBranchAddress("BMNicell",&(eve->BMNicell));
  RootTree->SetBranchAddress("BMNxin",&(eve->BMNxin));
  RootTree->SetBranchAddress("BMNyin",&(eve->BMNyin));
  RootTree->SetBranchAddress("BMNzin",&(eve->BMNzin));
  RootTree->SetBranchAddress("BMNpxin",&(eve->BMNpxin));
  RootTree->SetBranchAddress("BMNpyin",&(eve->BMNpyin));
  RootTree->SetBranchAddress("BMNpzin",&(eve->BMNpzin));
  RootTree->SetBranchAddress("BMNxout",&(eve->BMNxout));
  RootTree->SetBranchAddress("BMNyout",&(eve->BMNyout));
  RootTree->SetBranchAddress("BMNzout",&(eve->BMNzout));
  RootTree->SetBranchAddress("BMNpxout",&(eve->BMNpxout));
  RootTree->SetBranchAddress("BMNpyout",&(eve->BMNpyout));
  RootTree->SetBranchAddress("BMNpzout",&(eve->BMNpzout));
  RootTree->SetBranchAddress("BMNde",&(eve->BMNde));
  RootTree->SetBranchAddress("BMNal",&(eve->BMNal));
  RootTree->SetBranchAddress("BMNtim",&(eve->BMNtim));
  
  RootTree->SetBranchAddress("VTXn",&(eve->VTXn));
  RootTree->SetBranchAddress("VTXid",&(eve->VTXid));
  RootTree->SetBranchAddress("VTXilay",&(eve->VTXilay));
  RootTree->SetBranchAddress("VTXirow",&(eve->VTXirow));
  RootTree->SetBranchAddress("VTXicol",&(eve->VTXicol));
  RootTree->SetBranchAddress("VTXxin",&(eve->VTXxin));
  RootTree->SetBranchAddress("VTXyin",&(eve->VTXyin));
  RootTree->SetBranchAddress("VTXzin",&(eve->VTXzin));
  RootTree->SetBranchAddress("VTXpxin",&(eve->VTXpxin));
  RootTree->SetBranchAddress("VTXpyin",&(eve->VTXpyin));
  RootTree->SetBranchAddress("VTXpzin",&(eve->VTXpzin));
  RootTree->SetBranchAddress("VTXxout",&(eve->VTXxout));
  RootTree->SetBranchAddress("VTXyout",&(eve->VTXyout));
  RootTree->SetBranchAddress("VTXzout",&(eve->VTXzout));
  RootTree->SetBranchAddress("VTXpxout",&(eve->VTXpxout));
  RootTree->SetBranchAddress("VTXpyout",&(eve->VTXpyout));
  RootTree->SetBranchAddress("VTXpzout",&(eve->VTXpzout));
  RootTree->SetBranchAddress("VTXde",&(eve->VTXde));
  RootTree->SetBranchAddress("VTXal",&(eve->VTXal));
  RootTree->SetBranchAddress("VTXtim",&(eve->VTXtim));
  
  RootTree->SetBranchAddress("ITRn",&(eve->ITRn));
  RootTree->SetBranchAddress("ITRid",&(eve->ITRid));
  RootTree->SetBranchAddress("ITRilay",&(eve->ITRilay));
  RootTree->SetBranchAddress("ITRirow",&(eve->ITRirow));
  RootTree->SetBranchAddress("ITRicol",&(eve->ITRicol));
  RootTree->SetBranchAddress("ITRxin",&(eve->ITRxin));
  RootTree->SetBranchAddress("ITRyin",&(eve->ITRyin));
  RootTree->SetBranchAddress("ITRzin",&(eve->ITRzin));
  RootTree->SetBranchAddress("ITRpxin",&(eve->ITRpxin));
  RootTree->SetBranchAddress("ITRpyin",&(eve->ITRpyin));
  RootTree->SetBranchAddress("ITRpzin",&(eve->ITRpzin));
  RootTree->SetBranchAddress("ITRxout",&(eve->ITRxout));
  RootTree->SetBranchAddress("ITRyout",&(eve->ITRyout));
  RootTree->SetBranchAddress("ITRzout",&(eve->ITRzout));
  RootTree->SetBranchAddress("ITRpxout",&(eve->ITRpxout));
  RootTree->SetBranchAddress("ITRpyout",&(eve->ITRpyout));
  RootTree->SetBranchAddress("ITRpzout",&(eve->ITRpzout));
  RootTree->SetBranchAddress("ITRde",&(eve->ITRde));
  RootTree->SetBranchAddress("ITRal",&(eve->ITRal));
  RootTree->SetBranchAddress("ITRtim",&(eve->ITRtim));

  RootTree->SetBranchAddress("MSDn",&(eve->MSDn));
  RootTree->SetBranchAddress("MSDid",&(eve->MSDid));

  RootTree->SetBranchAddress("MSDilay",&(eve->MSDilay));
  RootTree->SetBranchAddress("MSDiview",&(eve->MSDiview));
  RootTree->SetBranchAddress("MSDistrip",&(eve->MSDistrip)); 
  //  RootTree->SetBranchAddress("MSDicell",&(eve->MSDicell)); 
  RootTree->SetBranchAddress("MSDxin",&(eve->MSDxin));
  RootTree->SetBranchAddress("MSDyin",&(eve->MSDyin));
  RootTree->SetBranchAddress("MSDzin",&(eve->MSDzin));
  RootTree->SetBranchAddress("MSDpxin",&(eve->MSDpxin));
  RootTree->SetBranchAddress("MSDpyin",&(eve->MSDpyin));
  RootTree->SetBranchAddress("MSDpzin",&(eve->MSDpzin));
  RootTree->SetBranchAddress("MSDxout",&(eve->MSDxout));
  RootTree->SetBranchAddress("MSDyout",&(eve->MSDyout));
  RootTree->SetBranchAddress("MSDzout",&(eve->MSDzout));
  RootTree->SetBranchAddress("MSDpxout",&(eve->MSDpxout));
  RootTree->SetBranchAddress("MSDpyout",&(eve->MSDpyout));
  RootTree->SetBranchAddress("MSDpzout",&(eve->MSDpzout));
  RootTree->SetBranchAddress("MSDde",&(eve->MSDde));
  RootTree->SetBranchAddress("MSDal",&(eve->MSDal));
  RootTree->SetBranchAddress("MSDtim",&(eve->MSDtim));
  
  RootTree->SetBranchAddress("SCNn",&(eve->SCNn));
  RootTree->SetBranchAddress("SCNid",&(eve->SCNid));
  RootTree->SetBranchAddress("SCNistrip",&(eve->SCNistrip));
  RootTree->SetBranchAddress("SCNiview",&(eve->SCNiview));
  RootTree->SetBranchAddress("SCNxin",&(eve->SCNxin));
  RootTree->SetBranchAddress("SCNyin",&(eve->SCNyin));
  RootTree->SetBranchAddress("SCNzin",&(eve->SCNzin));
  RootTree->SetBranchAddress("SCNpxin",&(eve->SCNpxin));
  RootTree->SetBranchAddress("SCNpyin",&(eve->SCNpyin));
  RootTree->SetBranchAddress("SCNpzin",&(eve->SCNpzin));
  RootTree->SetBranchAddress("SCNxout",&(eve->SCNxout));
  RootTree->SetBranchAddress("SCNyout",&(eve->SCNyout));
  RootTree->SetBranchAddress("SCNzout",&(eve->SCNzout));
  RootTree->SetBranchAddress("SCNpxout",&(eve->SCNpxout));
  RootTree->SetBranchAddress("SCNpyout",&(eve->SCNpyout));
  RootTree->SetBranchAddress("SCNpzout",&(eve->SCNpzout));
  RootTree->SetBranchAddress("SCNde",&(eve->SCNde));
  RootTree->SetBranchAddress("SCNal",&(eve->SCNal));
  RootTree->SetBranchAddress("SCNtim",&(eve->SCNtim));

  RootTree->SetBranchAddress("CALn",&(eve->CALn));
  RootTree->SetBranchAddress("CALid",&(eve->CALid));
  RootTree->SetBranchAddress("CALicry",&(eve->CALicry));
  RootTree->SetBranchAddress("CALxin",&(eve->CALxin));
  RootTree->SetBranchAddress("CALyin",&(eve->CALyin));
  RootTree->SetBranchAddress("CALzin",&(eve->CALzin));
  RootTree->SetBranchAddress("CALpxin",&(eve->CALpxin));
  RootTree->SetBranchAddress("CALpyin",&(eve->CALpyin));
  RootTree->SetBranchAddress("CALpzin",&(eve->CALpzin));
  RootTree->SetBranchAddress("CALxout",&(eve->CALxout));
  RootTree->SetBranchAddress("CALyout",&(eve->CALyout));
  RootTree->SetBranchAddress("CALzout",&(eve->CALzout));
  RootTree->SetBranchAddress("CALpxout",&(eve->CALpxout));
  RootTree->SetBranchAddress("CALpyout",&(eve->CALpyout));
  RootTree->SetBranchAddress("CALpzout",&(eve->CALpzout));
  RootTree->SetBranchAddress("CALde",&(eve->CALde));
  RootTree->SetBranchAddress("CALal",&(eve->CALal));
  RootTree->SetBranchAddress("CALtim",&(eve->CALtim));

  RootTree->SetBranchAddress("CROSSn",&(eve->CROSSn));
  RootTree->SetBranchAddress("CROSSid",&(eve->CROSSid));
  RootTree->SetBranchAddress("CROSSnreg",&(eve->CROSSnreg));
  RootTree->SetBranchAddress("CROSSnregold",&(eve->CROSSnregold));
  RootTree->SetBranchAddress("CROSSx",&(eve->CROSSx));
  RootTree->SetBranchAddress("CROSSy",&(eve->CROSSy));
  RootTree->SetBranchAddress("CROSSz",&(eve->CROSSz));
  RootTree->SetBranchAddress("CROSSpx",&(eve->CROSSpx));
  RootTree->SetBranchAddress("CROSSpy",&(eve->CROSSpy));
  RootTree->SetBranchAddress("CROSSpz",&(eve->CROSSpz));
  RootTree->SetBranchAddress("CROSSm",&(eve->CROSSm));
  RootTree->SetBranchAddress("CROSSch",&(eve->CROSSch));
  RootTree->SetBranchAddress("CROSSt",&(eve->CROSSt));
  return 0;

}


//EVENTO_STRUCT Evento::Output(){  return eve;}


Evento::~Evento()
{
}


