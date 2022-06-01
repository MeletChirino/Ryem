#include "Arduino.h"
#include "StateMachine.h"
#include "Event.h"

Event::Event(char* name_){
	name = name_;
	StateMachine *sm_list;
	sm_number = 0; 
}
void attach(StateMachine sm){
	//append value to sm_list
	*(sm_list+1) = sm;
	sm_number += 1;
}
void dettach(StateMachine sm){
	int dettach_element;
	for(int i = 0; i < sm_number; i++){
		if sm_list[i] == sm{
			dettach_element = i
		}
	
	for(int i = dettach_element; i < sm_number-1; i++){
		sm_list[i] = sm_list[i+1]
	}
	sm_number -= 1;
}
void happen(int value){
	for(int i = 0; i < sm_list; i++){
		sm_list[i].transition(this);
	}
}
