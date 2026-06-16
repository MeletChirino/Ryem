#ifndef EVENT_H
#define EVENT_H

class StateMachine;
#include "StateMachine.h"
#include <vector>

class Event {
  	private:
		std::vector<StateMachine*> _sm_list;
	public:
		//attributes
		int id;
		Event(); // Constructor
		// ~Event(){}; // Destructor
		void attach(StateMachine* sm);
		void dettach(StateMachine* sm);
		void happen();
		int get_id() {
			return id;
		};
};

#endif
