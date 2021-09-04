#include "game1.h"
int game_state=start;
int direction;

void play_game()
{
    init_snake();
    init_food();
    direction=RIGHT;
    game_state=play;
}
void end_game()
{
    game_state=ended;
}
void game_logic()
{       
    paint_border();
    int key=getch();
    if(game_state==start)
    {
        move(5,5);
        addstr("Press space to start");
        if(key==32)
        {
           play_game(); 
        }
    }
    else if(game_state==play)
    {
        if((key==UP || key==UP2) and direction!=DOWN and direction!=UP)
        {
            direction++;
        }
        else if((key==DOWN || key==DOWN2) and direction!=UP and direction!=DOWN)
        {
            direction++;
        }
        else if((key==RIGHT || key==RIGHT2) and direction!=LEFT and direction!=RIGHT)
        {
            direction++;
        }
        else if((key==LEFT || key==LEFT2) and direction!=LEFT and direction!=RIGHT)
        {
            direction++;
        }
    }
    else
    {
        move(5,5);
        addstr("GAME OVER!!! Press space to restart and q to quit the game");
        if(key==32)
        {
            play_game();
        }
        else if(key==char('q') || key==char('Q'))
        {
            
        }
    }
    if(has_collision)
    {

    }

    


}