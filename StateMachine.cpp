#ifdef NOT_ARDUINO
#include <Arduino.h>
#endif
#include <cstdlib>
#include <cstdio>
#include "common.h"
#include "StateMachine.h"
#include "Event.h"

StateMachine::StateMachine(){}

void StateMachine::attach_event(Event event_){
		event_.attach(*this);
}

void StateMachine::reset(){
	current_state = 0;
	}

void StateMachine::transition(Event event_){}
