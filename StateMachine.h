#ifndef StateMachine_h
#define StateMachine_h
class Event;

class StateMachine {
  public:
    unsigned int current_state = 0, state_numbers, id;

    //methods
    void reset(), attach_event(Event *event_), init(int);
    unsigned int get_id();
    virtual void transition(Event *event_) = 0;
    virtual void run() = 0;
};
#endif
