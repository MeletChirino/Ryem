#ifndef Event_h
#define Event_h
#include "StateMachine.h"

class Event{
	private:
		int sm_number;
	public:
		//attributes
		StateMachine *sm_list;
		char* name;
		Event(char*, int);//name, sm_number
		void attach(), dettach(), happen();
};
#endif
