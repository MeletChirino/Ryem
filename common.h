typedef void (*function)();

typedef struct{
	int state;
	int next_state;
	Event event;
	function *function_list;
	int n_functions;
} transitions;

typedef struct{
	function *function_list;
	int n_functions;
} state_functions;
