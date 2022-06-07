#ifndef Event_h
#define Event_h
class StateMachine;
#include "StateMachine.h"

typedef void (*function)();

typedef struct{
	function *function_list;
	int n_functions;
} state_functions;

class Event{
	private:
		int sm_number;
	public:
		//attributes
		StateMachine *sm_list;
		Event();//name, sm_number
		void attach(StateMachine), dettach(StateMachine), happen(int);
};

typedef struct transitions{
	int state;
	int next_state;
	Event event_t;
	function *function_list;
	int n_functions;
} transitions;

#endif
