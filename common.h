#ifndef common_h
#define common_h
#ifndef Event_h
class Event;
#endif
#include "Event.h"

typedef void (*function)();

typedef struct transitions{
	int state;
	int next_state;
	Event event;
	function *function_list;
	int n_functions;
} transitions;

typedef struct state_functions{
	function *function_list;
	int n_functions;
} state_functions;

#endif
