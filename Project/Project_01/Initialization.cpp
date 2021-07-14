#include "Initialization.h"

using namespace std;

ClassImp(Initialization);

void Initialization::Initialize_all(){

// Initialize

  status                  = 0;
  current_event           = 0;
  number_of_input_files   = 0;

  file_input_dat          = "Analysis_input.dat"; 
  filenameroot_out        = "Out.root";

  pevstr = new EVENTO_STRUCT;   // CREATE EVENT STRUCTURE
  cout<<"status:" <<status<<endl;
  cout<<"current_event:" <<current_event <<endl;
  cout<<"number_of_input_files:" <<number_of_input_files <<endl;
  cout<<"Ho inizializzato "<<endl;

}//end of Initialize_all







//Openfiles

void Initialization::Openfiles(){

  f_out = new TFile(filenameroot_out,"RECREATE");    //output file
  
  pfiles_input_dat=fopen(file_input_dat,"r"); if (!pfiles_input_dat) { cout<<"No file input dat "<<endl; exit(1);} //input file
  char nometmp[200];
  number_of_input_files = 0;
  

  
  int a = 1;
 
  a = fscanf(pfiles_input_dat,"%d",&A_beam); 
  a = fscanf(pfiles_input_dat,"%d",&cha_beam); 
  a = fscanf(pfiles_input_dat,"%f",&kin_nucleon); 


   gamma_beam = 0.;
   beta_beam = 0.;
  if(A_beam != 0){
  gamma_beam = ((kin_nucleon*A_beam) + A_beam)/A_beam;
  beta_beam  = pow(1.0-1.0/pow(gamma_beam,2),0.5);
}

  
  lambda.Boost(0.,0.,-beta_beam);
  

  
  a = 1;
  while( a==1 ){ 
    a = fscanf(pfiles_input_dat,"%s",nometmp); 
    list_of_input_files.push_back(nometmp);   
    number_of_input_files++;
   
  }
  number_of_input_files = number_of_input_files -1;

  
  chain_t = new TChain("EventTree");
  string nametot;  
  char namefile[200];
  for (int i =0; i<number_of_input_files; i++){
    nametot = list_of_input_files[i];
    strcpy(namefile,nametot.c_str());
    TFile* f_input = TFile::Open(namefile);
    if(f_input == 0){ cout <<"Error opening rootuple " << namefile<<endl; exit(-1); }    
    chain_t->Add(namefile);
    nametot = " ";

  }

  cout<<"Ho fatto openfile "<<endl;


} //end of openfile




//Put the initialized detector parameters of the file .txt in a vector
//Add any other parameters in the file .txt, in this case change the vector dimension in Initialization.h
void Initialization::parameter(){

  fstream my_file;
  string c;
	my_file.open("Par_detector.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
	
        for (int i = 0 ; i <= 10; i++){
        	my_file>>c>>par[i];
        //cout<< par[i]<<endl;//to check 
        if (my_file.eof())
				break;
		}

	}
	my_file.close();
	
	 
}// end of parameter function


//---- Get---------------

 EVENTO_STRUCT*  Initialization::getPevstr(){
 	return pevstr;
 }


int Initialization::getCurrent_event(){
	 return current_event;
}

TFile* Initialization::getF_out(){
	return f_out;
}

TChain* Initialization::getTchain(){
	return chain_t;
};



double* Initialization::getPar(){
	return par;
}

//---------Set-------------------

void Initialization::setCurrent_event(int b){
	 current_event=b;
}


void Initialization::setStatus(int a){
	 status=a;
}

