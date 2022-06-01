#ifndef StateMachine_h
#define StateMachine_h
#include "Event.h"
#include "common.h"

class StateMachine{
	private:
		int _n_transition_list;
	public:
		StateMachine(int);
		int current_state;
		transitions *transtion_list;
		state_functions *state_functions_list;
		//methods
		void add_transition(transitions transition);
		void reset(), transition(Event);
		void attach_events(int n, Event* events);
		void set_state_function_list(int n, function_list functions);
		void run();

}
