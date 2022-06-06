#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "Task.cpp"
#include "Event.cpp"
#include "common.h"

// Comment next line if your using arduino IDE
#define NOT_ARDUINO 1u
#define DEBUG 0u

void print3();
void print2();
void print1();

void my_delay(int i)    /*Pause l'application pour i seconds*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}
void task1_func();

Event event1;

int main(){
	function function_list[3] = {print3, print2, print1};
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
	for(int i = 0; i < 3; i++)
			function_list[i]();
	while(1){
		task1.run();
	}
	return 0;
}

void task1_func(){
	printf("Task1 %d\n", time(0));
	event1.happen(2);
}
void print3(){
	printf("Print 3!\n");
}
void print2(){
	printf("Print 2!\n");
}
void print1(){
	printf("Print 1!\n");
}
