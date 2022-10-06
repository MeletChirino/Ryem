#ifndef RyemTime_h
#define RyemTime_h

typedef unsigned int time_type;
#define GET_YEAR(frame) (frame >> 26) & 0b1111
#define GET_DAY(frame) (frame >> 17) & 0x1FF
#define GET_MONTH(frame) (int)((frame >> 17) & 0x1FF)/12
#define GET_HOUR(frame) (int)(frame & 0x1FFFF) / 3600
#define GET_MIN(frame) GET_HOUR(frame) % 60
#define GET_SECONDS(frame) frame & 0x1FFFF

#define SET_YEAR(year) (year & 0xF) << 26
#define SET_DAY(day) (day & 0x1FF) << 17

void sec_tick(time_type *time_var);

#endif
