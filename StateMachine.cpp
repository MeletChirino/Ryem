#include "Arduino.h"
#include "common.h"
#include "StateMachine.h"
#include "Event.h"
/*
 * Lastimosamente no puedes hacer todo como en python debido a la poca versatilidad
 * de c. Lo que puedes hacer es hacer metodos add para que el programa vaya agregando
 * uno a uno cada elemento y armando las listas (arrays).
 * */

StateMachine::StateMachine(int state_numbers_){
	state_numbers = state_numbers_;
	state_functions_list = (function_list*)malloc(state_numbers*sizeof(function_list));
	_n_transition_list = 0;
	current_state = 0;
}

void StateMachine::add_transition_list(transitions transition){
	//para pasar valores aqui tendras que hacer una transition list en una variable
	//desde antes y luego pasarla aqui.
	int i;
	i = _n_transition_list;
	_n_transition_list += 1;
	transition_list = (transitions*) realloc(transition_list, _n_transition_list);
	(*transition_list + i) = transition;
}

void StateMachine::reset(){
	current_state = 0
}

void Statemachine::transition(Event event){
	transitions = current_transition;
	for(int i = 0; i < _n_transition_list; i++){
		current_transition = transition_list[i]
		if(current_state == current_transition.state &&
				event ==  current_transition.event){
			current_state = current_transition.next_state;
			current_transition.function_list[i].func()
		}
	}

}

void StateMachine::run(){
	state_function_list[current_state].function_list[n].func() 
}
