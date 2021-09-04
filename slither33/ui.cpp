#include "ui.h"
char border_character=(char)219;
void init_ui()
{
    initscr();
    nodelay(stdscr, TRUE);
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
        if(i==0 || i==LINES - 1)
        {
        for(int j=0;j<COLS;j++)
        {
            move(i,j);
            addch(border_character);
        }
        }
        else
        {
            move(i,0);
            addch(border_character);
            move(i,COLS - 1);
            addch(border_character);
        }
    }
    // getch();
}