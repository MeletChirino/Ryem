#ifndef Event_h
#define Event_h
class StateMachine;
//#include "StateMachine.h"

class Event{
	public:
		//attributes
		StateMachine *sm_list;
		int *sm_number, id;
		//methods
		Event();//constructor
		void attach(StateMachine), dettach(StateMachine), happen();
		void init(int);
		int status(), get_id();
};

#endif
