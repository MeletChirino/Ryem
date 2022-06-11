// Comment next line if your using arduino IDE
#define NOT_ARDUINO 1u
#define DEBUG 0u

#ifdef NOT_ADRUINO
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <time.h>
#include "common.h"
#include "Event.h"
#include "StateMachine.h"
#include "Task.h"

using namespace std;


void print3();
void print2();
void print1();
void task1_func();
void task2_func();
void task3_func();
void events_func();
void my_delay(int i);

Task task1(3, task1_func, false);
Task events_task(1, events_func, true);

Event event1;
Event event2;
Event event3;

function func_l1[3] = {print3, print2, print1};
function func_l2[2] = {print3, print2};
function func_l3[2] = {print3, print1};

#define N_FUNC_ST1 2
function function_state1[N_FUNC_ST1] = {task1_func, task2_func};
function function_state2[2] = {task2_func, task3_func};
function function_state3[2] = {task1_func, task3_func};

StateMachine sm1(3);

transitions sm1_tr[3] = {
	//init_state, next_state, event, function_list, function_list_size
	{0, 1, event1, func_l1, 3},
	{1, 2, event2, func_l2, 2},
	{2, 0, event3, func_l3, 2}
};

state_functions sm1_funcs[3] = {
	{function_state1, N_FUNC_ST1},
	{function_state2, 2},
	{function_state3, 2}
};

int main(){
	sm1.set_state_funcs(sm1_funcs, 3);
	sm1.set_transition_list(sm1_tr, 3);
	sm1.attach_event(event1);
	sm1.attach_event(event2);
	sm1.attach_event(event3);
	
	printf("First exemple %ld\n", time(0));
	my_delay(2);
	printf("second exemple %ld\n", time(0));
	event1.status();
	event2.status();
	event3.status();
	while(1){
		//task1.run();
		events_task.run();
		//sm1.run();
	}
	return 0;
}
void events_func(){
		event1.happen(1);
		event2.happen(1);
		event3.happen(1);
}

void task1_func(){
	printf("Task1 %ld\n", time(0));
}

void task2_func(){
	printf("Task2 %ld\n", time(0));
}

void task3_func(){
	printf("Task3 %ld\n", time(0));
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
#endif
