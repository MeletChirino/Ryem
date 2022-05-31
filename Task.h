#ifndef Task_h
#define Task_h

class Task{
	private:
		int _last_time;
	public:
		// Attributes
		int period;
		bool enabled;
		Task(int period_, void (*function)());// period in milliseconds
		Task(int period_, void (*function)(), bool enabled_);
		// methods
		void enable(), disable();
		bool is_enabled();
		void (*run_function)();
		void run();
};
#endif
