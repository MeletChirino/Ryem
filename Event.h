#ifndef Event_h
#define Event_h
class StateMachine;

class Event{
  	private:
		std::vector<StateMachine> _sm_list;
		int sm_number;
	public:
		//attributes
		int id;
		//methods
		Event();//constructor
		void attach(StateMachine), dettach(StateMachine), happen();
		void init(int);
		int status(), get_id();
};

#endif
