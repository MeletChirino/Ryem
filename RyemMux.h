//Header for RyemMux
#ifndef RyemMux_h
#define RyemMux_h

class RyemMux {
  public:
    RyemMux();
    RyemMux(std::vector<uint8_t>, uint8_t);
    void init();
    void set_input_n(uint8_t);
    inline void set_selector(unsigned int mux_pin);
    unsigned int get_word();
    unsigned char get_bit(unsigned int mux_bit);
  private:
    std::vector<uint8_t> pin_list;
    uint8_t _in_pins, _out_pin;
};
#endif