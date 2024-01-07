#ifndef StateMachine_h
#define StateMachine_h

#include "./Event.h"

class StateMachine {
  public:
    unsigned int state_numbers, id;

    //methods
    void reset(), attach_event(Event *event_), init(int);
    unsigned int get_id();
    virtual void transition(Event *event_) = 0;
    virtual void run() = 0;
};
#endif
