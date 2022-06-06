#ifndef common_h
#define common_h

typedef struct transitions;

typedef void (*function)();

typedef struct{
	function *function_list;
	int n_functions;
} state_functions;

#include "Event.h"

struct transitions{
	int state;
	int next_state;
	Event event_t;
	function *function_list;
	int n_functions;
} transitions;


#endif
