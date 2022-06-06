#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
//#include "common.h"
#include "Task.cpp"

// Comment next line if your using arduino IDE
#define NOT_ARDUINO 1u

void my_delay(int i)    /*Pause l'application pour i seconds*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}
void task1_func();


int main(){
	Task task1(3, task1_func, true);
	printf("First exemple %d\n", time(0));
	my_delay(5);
	printf("second exemple %d\n", time(0));
	while(1){
		task1.run();
	}
	return 0;
}
void task1_func(){
	printf("Task1 %d\n", time(0));
}
