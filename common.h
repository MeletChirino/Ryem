
typedef struct{
	void (*func)();
} function;

typedef struct{
	int state;
	int next_state;
	Event event;
	function *function_list;
	int n_functions;
} transitions;

typedef struct{
	int state;
	fucntion *function_list;
	int n_functions
} state_functions;
