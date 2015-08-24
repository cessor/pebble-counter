#include <pebble.h>
#include "counter.h"
  
int* count;
int MAX_COUNTER = 10000;

void create_counter(){
  count = malloc(sizeof(int));
  *count = 0;
}

void destroy_counter(){
  free((int*)count);
}
  
void increment_counter() { 
  *count = (*count + 1) % MAX_COUNTER; 
}

void decrement_counter(){
  if((*count - 1) < 0) {
    *count = 0;
    return;
  }
  *count = (*count - 1) % MAX_COUNTER; 
}

int get_count() {
  return *count;
}

void reset_counter(){
  *count = 0;
}