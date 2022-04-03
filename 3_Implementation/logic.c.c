/**
 * @file logic.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../inc/logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * @brief 
 * 
 * @param elt 
 * @param list 
 * @return true 
 * @return false 
 */
bool delete_element(plist* elt, plist** list) {
  plist *currP, *prevP;
  prevP = NULL;

  for (currP = *list;
      currP != NULL;
      prevP = currP, currP = currP->next) {
    if (is_moved(currP, elt)) {
      if (prevP == NULL) {
        *list = currP->next;
      } else {
        prevP->next = currP->next;
      }
      free(currP);
      return true;
    }
  }
  return false;
}
/**
 * @brief 
 * 
 * @param game 
 * @param com 
 * @return enum status 
 */
enum status move_snake(Game* game, enum command com) {
  // Create a new beginning. Check boundaries.
  plist* beginning = turn_next(game, com);
  if (beginning == NULL) {
    return FAILURE;
  }

  // If we've gone backwards, don't do anything
  if (game->snake->next && is_moved(beginning, game->snake->next)) {
    beginning->next = NULL;
    free(beginning);
    return SUCCESS;
  }

  // Check for collisions
  if (curr_list(beginning, game->snake)) {
    return FAILURE;
  }

  // Check for fruit
  if (curr_list(beginning, game->fruits)) {
    // Attach the beginning to the rest of the snake;
    beginning->next = game->snake;
    game->snake = beginning;
    delete_element(beginning, &(game->fruits));
    add_new_fruit(game);

    return SUCCESS;
  }

  // Attach the beginning to the rest of the snake
  beginning->next = game->snake;
  game->snake = beginning;


  // Cut off the end
  plist* end = game->snake;
  while(end->next->next) {
    end = end->next;
  }
  free(end->next);
  end->next = NULL;

  return SUCCESS;
}
/**
 * @brief 
 * 
 * @param point1 
 * @param point2 
 * @return true 
 * @return false 
 */
bool is_moved(plist* point1, plist* point2) {
  return point1->x == point2->x && point1->y == point2->y;
}

/**
 * @brief 
 * 
 * @param game 
 * @param com 
 * @return plist* 
 */
plist* turn_next(Game* game, enum command com) {
  plist* snake = game->snake;
  int new_x = snake->x;
  int new_y = snake->y;
  switch(com) {
    case UP:
      new_y = snake->y - 1;
      break;
    case DOWN:
      new_y = snake->y + 1;
      break;
    case LEFT:
      new_x = snake->x - 1;
      break;
    case RIGHT:
      new_x = snake->x + 1;
      break;
  }
  if (new_x < 0 || new_y < 0 || new_x >= game->xmax || new_y >= game->ymax) {
    return NULL;
  } else {
    return create_point(new_x, new_y);
  }
}
/**
 * @brief Create a random point object
 * 
 * @param xmax 
 * @param ymax 
 * @return plist* 
 */
plist* create_random_point(int xmax, int ymax) {
  return create_point(rand() % xmax, rand() % ymax);
}
/**
 * @brief 
 * 
 * @param game 
 */
void add_new_fruit(Game* game) {
  plist* new_fruit;
  do {
    new_fruit = create_random_point(game->xmax, game->ymax);
  } while(curr_list(new_fruit, game->fruits) || curr_list(new_fruit, game->snake));
  new_fruit->next = game->fruits;
  game->fruits = new_fruit;
}
/**
 * @brief 
 * 
 * @param point 
 * @param list 
 * @return true 
 * @return false 
 */
bool curr_list(plist* point, plist* list) {
  plist* s = list;
  while (s) {
    if (is_moved(s, point)) {
      return true;
    }
    s = s->next;
  }
  return false;
}
/**
 * @brief Create a point object
 * 
 * @param x 
 * @param y 
 * @return plist* 
 */
plist* create_point(int x, int y) {
  plist* point = malloc(sizeof(*point));
  point->x = x;
  point->y = y;
  point->next = NULL;
  return point;
}
/**
 * @brief 
 * 
 * @param snake 
 * @param fruits 
 * @param xmax 
 * @param ymax 
 * @return Game* 
 */
Game* draw(plist* snake, plist* fruits, int xmax, int ymax) {
  Game* game = malloc(sizeof(*game));
  game->fruits = fruits;
  game->snake = snake;
  game->xmax = xmax;
  game->ymax = ymax;
  return game;
}
/**
 * @brief Create a snake object
 * 
 * @return plist* 
 */
plist* create_snake() {
  plist* a = create_point(2,3);
  plist* b = create_point(2,2);
  a->next = b;
  return a;
}
