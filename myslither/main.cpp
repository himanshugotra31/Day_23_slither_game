#include <iostream>
#include <chrono>
#include <vector>
#include <curses.h>
#include "game1.h"
#include "food1.h"
#include "ui1.h"
#include "snake1.h"
#include "setting_constants.h"

using namespace std;

void run_game()
{
    while(true)
    {
        int dt;
        auto last_time = chrono::system_clock::now();
        erase();
        refresh();
        game_logic();
        do
        {
            auto current_time= chrono::system_clock::now();
            dt= chrono::duration_cast<std::chrono::microseconds>(current_time-last_time).count();
        } while (dt<time_lapse_between_frames);
        
        


    }
    
}
int main()
{
    init_ui();
    run_game();
    // paint_border();
    tear_down_ui();
    return 0;

}


