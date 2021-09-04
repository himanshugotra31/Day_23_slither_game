#ifndef DEF_SNAKE

#define DEF_SNAKE
#include "settings_constants.h"
#include <curses.h>
#include <vector>
using namespace std;
void init_snake();
void paint_snake();
pair<int,int> move_snake(int direction);
void grow_snake();
bool has_collisions();
#endif