#include "game.h"

// int x=5, y=5;
int game_state= BEFORE_START;
int direction;
int score;
void start_game()
{
    init_snake();
    init_food();
    direction=UP;
    game_state=STARTED;
    score=0;

}
void end_game()
{
    game_state=ENDED;

}
void paint_status()
{
    move(0,5);
    printw("SCORE = %d",score);
    

}
bool game_logic()
{
   
    // paint_border();
    // move(x,y);
    // addch('#');
    
    paint_border();
    paint_status();
    int key=getch();
    if(game_state==BEFORE_START) 
    {
        move(5,5);
        addstr("Press space to start the game or Q to quit");
        if(key==32)  
        {
            start_game();
        }  
        if(key=='q' or key=='Q')
        {
            end_game();
        }
    }

    else if(game_state==STARTED)
    {
        if(key==UP and direction!=DOWN)
        {
            direction=UP;
        }
        else if(key==DOWN and direction!=UP)
        {
            direction=DOWN;
        }
        else if(key==LEFT and direction!=RIGHT)
        {
            direction=LEFT;
        }
        else if(key==RIGHT and direction!=LEFT)
        {
            direction=RIGHT;
        }
        // move_snake(direction);
        pair<int,int> head=move_snake(direction);
        if(try_eating_food(head))
        {
            score++;
            grow_snake();
        }
        if(has_collisions())
        {
            end_game();
        }
        paint_snake();
        paint_food();
    }
    else
    {
        move(7,7);
        addstr("GAME OVER! PRESS SPACE TO RESTART AND Q TO QUIT");
        if(key==32)  
        {
            start_game();
        }
        if(key=='q' or key=='Q')
        {
            return TRUE;
        }


    }
    return false;
    
    
    
    // move(x,y);
    // addch('#');
   
    
}
