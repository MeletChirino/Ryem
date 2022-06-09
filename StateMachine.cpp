#ifdef NOT_ARDUINO
#include <Arduino.h>
#endif
#include <cstdlib>
#include <cstdio>
#include "common.h"
#include "StateMachine.h"
#include "Event.h"

StateMachine::StateMachine(int state_numbers_){
	state_numbers = state_numbers_;
	_n_transition_list = 0;
	current_state = 0;
	}

void StateMachine::set_state_funcs(state_functions *funcs, int n){
	state_function_list = (state_functions *) malloc(n* sizeof(state_functions));
	for(int i = 0; i < n; i++)
		state_function_list[i] = funcs[i];
	}

void StateMachine::set_transition_list(transitions *transition_list_, int n){
	transition_list = (transitions*) malloc(n * sizeof(transitions));
	_n_transition_list = n;
	for(int i = 0; i < n; i++)
		transition_list[i] = transition_list_[i];
	}

void StateMachine::attach_event(Event event){
		printf("\n\nAttaching in SM");
		event.attach(*this);
}

void StateMachine::reset(){
	current_state = 0;
	}

void StateMachine::transition(Event event_){
	transitions current_transition;
	printf("transition %d", current_state);
	for(int i = 0; i < _n_transition_list; i++){
		current_transition = transition_list[i];
		printf("transition %d -> %d", current_transition.state, current_transition.next_state);
		if(current_state == current_transition.state &&
			&current_transition.event == &event_){
			current_state = current_transition.next_state;
			current_transition.function_list[i]();
			}
		}
	}

void StateMachine::run(){
		int n_funcs = state_function_list[current_state].n_functions;
	for(int i = 0; i < n_funcs; i++){
			state_function_list[current_state].function_list[i]();
	}
}
