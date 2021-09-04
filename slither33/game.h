#ifndef DEF_GAME

#define DEF_GAME
#include "settings_constants.h"
#include <curses.h>
#include "ui.h"
#include "snake.h"
#include "food.h"
bool game_logic();
void end_game();
void paint_status();

#endif