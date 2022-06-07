#ifdef NOT_ARDUINO
#include <Arduino.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include "Task.h"


#ifndef NOT_ARDUINO
#include <time.h>
int millis(){
		return time(0);
}
#endif


Task::Task(int period_, void (*function_)()){
	//constructor
	enabled = false;
	run_function = function_;
	period = period_;
	_last_time = millis();
}

Task::Task(int period_, void (*function_)(), bool enabled_){
	//constructor
	enabled = enabled_;
	run_function = function_;
	period = period_;
	_last_time = millis();
}
void Task::enable(){
	_last_time = millis();
	enabled = true;
}
void Task::disable(){
	enabled = false;
}
bool Task::is_enabled(){
	return enabled;
}

void Task::run(){
	int current_time;
	current_time = millis() - _last_time;
	if(enabled && current_time >= period){
		run_function();
		_last_time = millis();
	}
}
