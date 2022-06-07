#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
//#include "common.h"
#include "Task.h"
#include "StateMachine.h"
#include "Event.h"
//#include "test.h"

void task1_func(){
	time_t now = time(0);
	long now_i = int(now);
	printf("Task1 %ld\n", now_i);
}
Task task1(3, task1_func, true);

// Comment next line if your using arduino IDE
#define NOT_ARDUINO 1u
#define DEBUG 0u

int main(){
	task1_func();
	/*
	Task task1(3, task1_func, true);
	printf("First exemple %d\n", time(0));
	my_delay(2);
	event1.dettach(3);
	printf("second exemple %d\n", time(0));
	for(int i = 0; i < 3; i++)
			function_list[i]();
	*/
	while(1){
		task1.run();
	}
	return 0;
}

