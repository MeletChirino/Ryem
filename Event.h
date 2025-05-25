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
		// void init(int id_) {
		// 	id = id_;
		// };
		// int status() {
		// 	return _sm_list.size();
		// };
		int get_id() {
			return id;
		};
};

#endif
