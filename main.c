#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <time.h>
#include "common.h"
#include "Event.h"
#include "StateMachine.h"
#include "Task.h"
#include "test.h"

using namespace std;

// Comment next line if your using arduino IDE
#define NOT_ARDUINO 1u
#define DEBUG 0u

void task1_func(){
	printf("Task1 %ld\n", time(0));
	event1.happen(2);
}

int main(){
	//Task task1(3, task1_func, true);
	printf("First exemple %ld\n", time(0));
	my_delay(2);
	//event1.dettach(3);
	printf("second exemple %ld\n", time(0));
	for(int i = 0; i < 3; i++)
			function_list[i]();
	while(1){
		task1.run();
	}
	return 0;
}

