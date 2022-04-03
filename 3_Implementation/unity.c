/**
 * @file main.c
 * @author Sarthak Naithani
 * @brief 
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "inc/logic.h"
#include "inc/displayscore.h"
#include <ncurses.h>

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE); // make keys work
  curs_set(0); // hide cursor
  timeout(100);

  int xmax;
  int ymax;
  getmaxyx(stdscr, ymax, xmax);
  enum command com = RIGHT;

  Game* game = draw(create_snake(), NULL, xmax, ymax);
  int i;
  for (i = 0; i < 6; i++) {
    add_new_fruit(game);
  }

  while(true) {
    clear();
    display_points(game->snake, ACS_BLOCK);
    display_points(game->fruits, ACS_DIAMOND);
    refresh();
    com = get_turn_next(com);
    enum status status = move_snake(game, com);
    if (status == FAILURE) break;
  }
  endwin();

  return 0;
}