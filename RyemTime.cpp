#include <Arduino.h>
#include "RyemTime.h"

void sec_tick(unsigned int *var){
  *var++;
  /* if (GET_SECONDS(*time_var) > 86400){ */
  /*   //day change */
  /*   unsigned int day = GET_DAY(*time_var); */
  /*   day++; */
  /*   day = day << 17; */
  /*   *time_var &= 0xFE01FFFF; */
  /*   *time_var |= day; */
  /*   *time_var &= 0xFFFE0000;//seconds field cleared */
  /* } */
  /* if (GET_DAY(*time_var) > 365){ */
  /*   //year change */
  /*   unsigned int year = GET_YEAR(*time_var); */
  /*   year++; */
  /*   year = year << 26; */
  /*   *time_var &= 0xC3FFFFFF; */
  /*   *time_var |= year; */
  /*   *time_var &= 0xFC01FFFF;//day field cleared */
  /* } */
}
