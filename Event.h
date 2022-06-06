#ifndef Event_h
#define Event_h
//#include "StateMachine.h"

class Event{
	private:
		int sm_number;
	public:
		//attributes
		//StateMachine *sm_list;
		int *sm_list;
		Event();//name, sm_number
		void attach(int), dettach(int), happen(int);
};
#endif
