#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <time.h>
#include "common.h"
#include "Event.h"
#include "StateMachine.h"
#include "Task.h"

using namespace std;

// Comment next line if your using arduino IDE
#define NOT_ARDUINO 1u
#define DEBUG 0u

void print3();
void print2();
void print1();
void task1_func();
void my_delay(int);

Task task1(3, task1_func, true);

Event event1;
function function_list[3] = {print3, print2, print1};
StateMachine sm1;

transitions sm1_tr[3] = {
	{0, 1, event1, function_list, 3},
	{0, 1, event1, function_list, 3},
	{0, 1, event1, function_list, 3}
};

state_functions sm1_funcs[3] = {
	{function_list, 1},
	{function_list, 1},
	{function_list, 1}
};

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

void task1_func(){
	printf("Task1 %ld\n", time(0));
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

void my_delay(int i)    /*Pause l'application pour i seconds*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}
