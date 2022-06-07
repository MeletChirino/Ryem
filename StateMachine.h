#ifndef StateMachine_h
#define StateMachine_h

class Event;

#include "Event.h"
//class Event;

class StateMachine{
	private:
		int _n_transition_list;
	public:
		StateMachine(int);
		int current_state, state_numbers;
		transitions *transition_list;
		state_functions *state_function_list;
		//methods
		void set_transition_list(transitions*, int);
		void set_state_funcs(state_functions*, int);
		void reset(), transition(Event);
		void run();

};
#endif
