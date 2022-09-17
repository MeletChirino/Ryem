#ifndef StateMachine_h
#define StateMachine_h
class Event;
#include "common.h"

class StateMachine{
	public:
		StateMachine();
		int current_state, state_numbers;
		//methods
		void reset(), transition(Event event_), attach_event(Event event_);

};
#endif
