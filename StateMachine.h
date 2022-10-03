#ifndef StateMachine_h
#define StateMachine_h
class Event;

#define P2TRANS(function) void (*function)(Event*, int*)
#define P2RUN(function) void (*function)(int*)

class StateMachine {
  public:
    StateMachine(P2TRANS(function), P2RUN(run_func));
    int current_state, state_numbers, id;

    void (*transition_method)(Event *event, int *current_state);

    void (*run_method)(int *current_state);
    //methods
    void reset(), transition(Event event_), attach_event(Event *event_), init(int);
    unsigned int get_id();
    void transition(Event *);
    void run();

    //void (*function)()
};
#endif
