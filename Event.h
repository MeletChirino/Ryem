#ifndef Event_h
#define Event_h
class StateMachine;
//#include "StateMachine.h"

class Event{
	public:
		//attributes
		StateMachine *sm_list;
		int sm_number;
		//methods
		Event();//constructor
		void attach(StateMachine), dettach(StateMachine), happen(int);
		void status();
};

#endif
