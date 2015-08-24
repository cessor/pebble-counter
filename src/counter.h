#include <pebble.h>
#ifndef __COUNTER_LIB__
#define __COUNTER_LIB__ 
void create_counter(); 
void decrement_counter(); 
void destroy_counter(); 
void increment_counter(); 
int get_count();
void reset_counter();
#endif