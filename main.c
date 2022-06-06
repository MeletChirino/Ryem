#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
//#include "common.h"
#include "Task.cpp"
#include "Event.cpp"

// Comment next line if your using arduino IDE
#define NOT_ARDUINO 1u
#define DEBUG 0u

void my_delay(int i)    /*Pause l'application pour i seconds*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}
void task1_func();

Event event1;

int main(){
	event1.attach(1);
	event1.attach(2);
	event1.attach(3);
	event1.attach(4);
	event1.attach(5);
	event1.attach(3);
	event1.attach(8);
	Task task1(3, task1_func, true);
	printf("First exemple %d\n", time(0));
	my_delay(2);
	event1.dettach(3);
	printf("second exemple %d\n", time(0));
	while(1){
		task1.run();
	}
	return 0;
}

void task1_func(){
	printf("Task1 %d\n", time(0));
	event1.happen(2);
}
