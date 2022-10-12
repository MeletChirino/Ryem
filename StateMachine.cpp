#include <Arduino.h>
#include "StateMachine.h"
#include "Event.h"

StateMachine::StateMachine(P2TRANS(trans_func), P2RUN(run_func)) {
  transition_method = trans_func;
  run_method = run_func;
}

void StateMachine::init(int id_) {
  current_state = 0;
  id = id_;
}

unsigned int StateMachine::get_id() {
  return id;
}

void StateMachine::attach_event(Event *event_) {
  event_->attach(*this);
}

void StateMachine::reset() {
  current_state = 0;
}

void StateMachine::transition(Event *event_) {
  Serial.println(" --------------- \nTransition Happened\n---------------");
  Serial.print("Event "); Serial.println(event_->id);
  Serial.print(current_state);
  Serial.print("->");
  transition_method(event_, &current_state);
  Serial.print(current_state);
  Serial.print("\nFinish transition\n\n");
}

void StateMachine::run() {
  Serial.print("---------- SM current State => ");
  Serial.print(current_state);
  Serial.println(" ----------");
  run_method(&current_state);
}
