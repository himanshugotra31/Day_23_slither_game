#include <iostream>
#include <curses.h>
#include "ui.h"
#include "game.h"
#include <chrono>
#include "settings_constants.h"


using namespace std;


void event_loop()
{
    int dt;
    while(true)
    {
        auto last_time=chrono::system_clock::now();
        erase();
        bool game_over=game_logic();
        if(game_over)
        {
            break;
        }
        refresh();
        
        do
        {
            auto current_time=chrono::system_clock::now();
            dt=chrono::duration_cast<std::chrono::microseconds>(current_time-last_time).count();

        }
        while(dt<time_delay_between_frames);
    }
    
}

int main()
{
    init_ui();
    event_loop();
    tear_down_ui();
    cout<<"Thanks for playing this Snake game! But don't be snake in real world.";
    
    return 0;
}