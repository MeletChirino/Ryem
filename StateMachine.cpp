#include <Arduino.h>
#include "StateMachine.h"
#include "Event.h"

unsigned int StateMachine::get_id() {
  return id;
}

void StateMachine::attach_event(Event *event_) {
  event_->attach(*this);
}
