#include "Arduino.h"
#include "Task.h"

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
	last_time = millis();
	enabled = true;
}
void Task::disable(){
	enabled = false;
}
bool Task::is_enabled(){
	return enabled;
}

void Task::run(){
	current_time = millis() - last_time;
	if(enabled && current_time >= period){
		run_function();
		last_time = millis();
	}
}
