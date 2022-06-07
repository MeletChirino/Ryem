#ifdef NOT_ARDUINO
#include <Arduino.h>
#endif
#include <cstdlib>
#include <cstdio>
#include "Event.h"
#include "StateMachine.h"

Event::Event(){
	StateMachine *sm_list;
	sm_list = (StateMachine *) malloc(sizeof(StateMachine));
	sm_number = 0; 
}
//void attach(StateMachine sm){
void Event::attach(StateMachine sm){
	//append value to sm_list
	//printf("attaching element = %d\n", sm);
	sm_number += 1;
	sm_list = (StateMachine *) realloc( sm_list, sm_number * sizeof(StateMachine));
	*(sm_list + (sm_number - 1)) = sm;
}
//void dettach(StateMachine sm){
void Event::dettach(StateMachine sm){
	int dettach_element;
	//printf("dettaching element = %d\n", sm);
	for(int i = 0; i < sm_number; i++){
		if (&sm_list[i] == &sm){
			dettach_element = i;
			//printf("found element inside [%d] = %d\n", i, sm);
			break;
			}
		}
	for(int i = dettach_element; i < sm_number-1; i++){
		sm_list[i] = sm_list[i+1];
		}
	sm_number -= 1;
	sm_list = (StateMachine *) realloc( sm_list, sm_number * sizeof(StateMachine));
}
void Event::happen(int value){
		/*
	for(int i = 0; i < sm_number; i++){
		//sm_list[i].transition(this);
		printf("sm_list[%d] = %d\n", i, sm_list[i]);
	}
	*/
		printf("Event happen\n");
	for(int i = 0; i < sm_number; i++){
		sm_list[i].transition(this);
		//sm_list[i] += 1;
		//printf("Event %d\n", sm_list[i]);
	}
}
