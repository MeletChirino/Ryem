#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "common.h"
#include "Event.h"
#include "StateMachine.h"
#include "Task.h"
#include "test.h"

// Comment next line if your using arduino IDE
#define NOT_ARDUINO 1u
#define DEBUG 0u

int main(){
	//StateMachine sm1(3);
	Task task1(3, task1_func, true);
	printf("First exemple %d\n", time(0));
	my_delay(2);
	event1.dettach(3);
	printf("second exemple %d\n", time(0));
	for(int i = 0; i < 3; i++)
			function_list[i]();
	while(1){
		task1.run();
	}
	return 0;
}

