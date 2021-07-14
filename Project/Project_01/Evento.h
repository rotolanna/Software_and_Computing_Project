#ifndef ROOT_Evento
#define ROOT_Evento

#include <iostream>
#include <fstream>
#include "TObject.h"
#include "TTree.h"
#include "TChain.h" 

#include "EventStruct.h"

using namespace std;

class Evento : public TObject {

 public:

  Evento();
  virtual ~Evento();

  Int_t Clean();

  //  int FindBranches(TTree *RootTree,EVENTO_STRUCT *eve);
  int FindBranches(TChain *RootTree,EVENTO_STRUCT *eve);

  //  EVENTO_STRUCT Output();

 private:

  EVENTO_STRUCT eve;

 protected:

  ClassDef(Evento,1);

};

#endif
