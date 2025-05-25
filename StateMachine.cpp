#include "StateMachine.h"
#include "Event.h"

StateMachine::StateMachine(){
};

void StateMachine::reset() {
  _current_state = 0;
}

void StateMachine::attach_event(Event *event) {
  event->attach(this);
}