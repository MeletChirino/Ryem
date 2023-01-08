// This is implementation for RyemMux
#include <Arduino.h>
#include "RyemMux.h"

#define LAST_BIT(i, mux_pin) ((mux_pin >> i) & 0x1)

RyemMux::RyemMux(){}
//empty construtor

RyemMux::RyemMux(std::vector<uint8_t> pin_list_, uint8_t out){
  //constructor that takes the pin list and save basic data
  pin_list = pin_list_;
  _out_pin = out;
}

void RyemMux::set_input_n(uint8_t n){
    _in_pins = n;
}

void RyemMux::init(){
  pinMode(_out_pin, INPUT);
  for(int i = 0; i < _in_pins; i++)
    pinMode(i, OUTPUT);
}

void inline RyemMux::set_selector(unsigned int mux_pin){
  for(int i = 0; i < _in_pins; i++)
    digitalWrite(pin_list[i], LAST_BIT(i, mux_pin));
}

unsigned char RyemMux::get_bit(unsigned int mux_pin){
  // This method gets a single bit of the mux
  unsigned char bit_val;
  set_selector(mux_pin);
  return digitalRead(_out_pin);
}

unsigned int RyemMux::get_word(){
  // This gets word of the whole RyemMux
  unsigned int mux_word = 0;
  for(int i = 0; i < _in_pins; i++)
    mux_word |= (get_bit(i) << i);
  
  return mux_word;
}