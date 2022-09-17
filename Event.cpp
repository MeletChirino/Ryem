#ifdef NOT_ARDUINO
#include <Arduino.h>
#endif
#include <cstdlib>
#include <cstdio>
#include "Event.h"
#include "StateMachine.h"

Event::Event(){
}

void Event::init(){
	sm_list = (StateMachine *) malloc(sizeof(StateMachine));
	sm_number = (int *) malloc(sizeof(int));
	*sm_number = 0; 
}
void Event::attach(StateMachine sm){
	*sm_number += 1;
	sm_list = (StateMachine *) realloc( sm_list, *sm_number * sizeof(StateMachine));
	*(sm_list + (*sm_number - 1)) = sm;
}

void Event::dettach(StateMachine sm){
	int dettach_element;
	for(int i = 0; i < *sm_number; i++){
		if (&sm_list[i] == &sm){
			dettach_element = i;
			break;
			}
		}
	for(int i = dettach_element; i < *sm_number-1; i++){
		sm_list[i] = sm_list[i+1];
		}
	*sm_number -= 1;
	sm_list = (StateMachine *) realloc( sm_list, *sm_number * sizeof(StateMachine));
}

int Event::status(){
	return *sm_number;
}

void Event::happen(){
	//Serial.println("\n\nEVENT HAPENED!!\n\n");
	//printf("Event happen\ntrying %d times", *sm_number);
	for(int i = 0; i < *sm_number; i++){
			//printf("i = %d", i);
			sm_list[i].transition(*this);
	}
}
