#include "Event.h"
#include "StateMachine.h"

Event::Event(){};

void Event::attach(StateMachine *sm) {
    this->_sm_list.push_back(sm);
}

void Event::dettach(StateMachine *sm) {
    // TODO: Implement method
}

void Event::happen() {
    for (size_t i = 0; i < this->_sm_list.size(); i++) {
        _sm_list[i]->transition(this);
    }
}
