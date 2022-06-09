#ifndef Event_h
#define Event_h
class StateMachine;
//#include "StateMachine.h"

class Event{
	private:
		int sm_number;
	public:
		//attributes
		StateMachine *sm_list;
		Event();//name, sm_number
		void attach(StateMachine), dettach(StateMachine), happen(int);
};

#endif
