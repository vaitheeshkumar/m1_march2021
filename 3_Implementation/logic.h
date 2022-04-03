#include <stdbool.h>

enum command { UP, DOWN, LEFT, RIGHT };
enum status { SUCCESS, FAILURE };
struct plist {
  int x;
  int y;
  struct plist* next;
};

typedef struct plist plist;

typedef struct {
  plist* snake;
  plist* fruits;
  int xmax;
  int ymax;
} Game;


bool is_moved(plist* point1, plist* point2);
enum status move_snake(Game* game, enum command com);
plist* turn_next(Game* game, enum command com);
plist* create_point(int x, int y);
plist* create_random_point(int xmax, int ymax);
plist* create_snake();
Game* draw(plist* fruits, plist* snake, int xmax, int ymax);
bool curr_list(plist* point, plist* list);
bool delete_element(plist* elt, plist** list);
void add_new_fruit(Game* game);
