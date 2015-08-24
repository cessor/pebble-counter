#include <pebble.h>
#include <string.h>
#include "counter.h"
  
Window* window;
TextLayer* text;


void create_text() {
  text = text_layer_create(GRect(0, 0, 144, 55));
  text_layer_set_font(text, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(text, GTextAlignmentCenter);
  text_layer_set_text(text, "Hello");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text));
}

void display_counter() {
  static char buffer[] = "     ";
  snprintf(buffer, 5, "%d", get_count());
  text_layer_set_text(text, buffer);
}

void up_clicked(ClickRecognizerRef recognizer, void* context) {
  increment_counter();
  display_counter();
}

void select_clicked(ClickRecognizerRef recognizer, void* context) {
  reset_counter();
  display_counter();
}

void down_clicked(ClickRecognizerRef recognizer, void* context) {
  decrement_counter();   
  display_counter();
}

void window_unload() {
  destroy_counter();
  text_layer_destroy(text);
}

void window_load(){
  create_counter();
  create_text();
  display_counter();
}

void register_handlers (void* context) {
    window_single_click_subscribe(BUTTON_ID_UP, up_clicked);
    window_single_click_subscribe(BUTTON_ID_SELECT, select_clicked);
    window_single_click_subscribe(BUTTON_ID_DOWN, down_clicked);
}

void create_window() {
  window = window_create();
  window_set_fullscreen(window, true);
  window_set_window_handlers(window, (WindowHandlers) {
     .load = window_load,
     .unload = window_unload    
  });
  window_set_click_config_provider(window, (ClickConfigProvider)register_handlers);
}

void init_application(void) {
  create_window();
  window_stack_push(window, true);
}

void exit_application() {
  window_destroy(window);
}

int main(void) {
  init_application();
  app_event_loop();
  exit_application();
}
