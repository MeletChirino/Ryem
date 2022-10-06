#include <Arduino.h>
#include <malloc.h>
#include "Event.h"
#include "StateMachine.h"
#include <vector>

Event::Event() {
}

void Event::init(int id_) {
  id = id_;
}

int Event::get_id() {
  return id;
}

void Event::attach(StateMachine sm) {
  Serial.print("Attaching ev->");
  Serial.print(id);
  Serial.print(" to sm->");
  Serial.println(sm.get_id());
  this->_sm_list.push_back(sm);
}

void Event::dettach(StateMachine sm) {
}

int Event::status() {
  return _sm_list.size();
}

void Event::happen() {
  Serial.println("\n\nEVENT HAPENED!!\n\n");
  Serial.print("\nsm_number = ");
  Serial.println(_sm_list.size());
  for (int i = 0; i < this->_sm_list.size(); i++) {
    //printf("i = %d", i);
    Serial.print("i = ");
    Serial.println(i);
    _sm_list[i].transition(this);
  }
  Serial.print("Transitions Done\n");
}
