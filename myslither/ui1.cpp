#include "ui1.h"

void init_ui()
{
    initscr();
    // nodelay(stdscr,TRUE);
    noecho();
    curs_set(0);
    
}
void tear_down_ui()
{
    endwin();
}
void paint_border()
{
    for(int i=0;i<LINES;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            char border_font=(char)219;
            if(i==0 || i==LINES-1)
            {
                move(i,j);
                addch(border_font);

            }
            else
            {
                if(j==0 || j==COLS-1)
                {
                    move(i,j);
                    addch(border_font);
                }
            }
        }
    }
    
    // getch();
}