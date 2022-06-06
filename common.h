typedef void (*function)();

typedef struct{
	int state;
	int next_state;
	Event event;
	function *function_list;
	int n_functions;
} transitions;

typedef struct{
	int state;
	function *function_list;
	int n_functions;
} state_functions;
