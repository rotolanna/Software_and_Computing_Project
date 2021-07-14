#ifndef Init_in_each_event_H
#define Init_in_each_event_H

#include "Initialization.h"
#include "constant.h"
#include "STRUCT.h"


class Init_in_each_event {
	
	private:
   
  ALLTRACK_STRUCT tra2[max_tra_ev]; 
   
 
  
  public:
  	
  ALLTRACK_STRUCT tra_frag[max_tra_ev][NUMFRAG]; //N.B. Get_function doesn't work with matrix
 
  Init_in_each_event(){}; //constructor

  ~Init_in_each_event(){}; //destructor	

  	//Function Prototypes
  	
  	void        Initialize_in_each_event();
  	void        Initialize_zero(ALLTRACK_STRUCT &allt);
  	void        Initialize_zero_kine(kinetic &kin_gen);
  	void        Initialize_zero_detect(info_detect &detect);
  	void        Initialize_zero_track(track &tr);
	ALLTRACK_STRUCT* getTra2();

};




#endif
