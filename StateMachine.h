#ifndef STATE_MACHINE_h
#define STATE_MACHINE_h

class Event;
#include <vector>
#include "Event.h"

class StateMachine {
  public:
    StateMachine();
    // ~StateMachine(){};
    unsigned int state_numbers, id;
    void reset();
    void attach_event(Event *event);
    // void init(int);
    // unsigned int get_id();
    virtual void transition(Event *event) = 0;
    virtual void run() = 0;
  protected:
    unsigned int _current_state;
};
#endif
