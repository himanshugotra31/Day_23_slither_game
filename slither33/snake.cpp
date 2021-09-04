#include "snake.h"

int x,y;
vector<pair<int,int>> body;
void init_snake()
{
    body.clear();
    body.push_back({5,5});
    body.push_back({5,6});
    body.push_back({5,7});

}
void paint_snake()
{
    for(int i=0; i<body.size();i++)
    {
        // pair<int,int> location=body[i];
        // move(location.first,location.second);
        move(body[i].first,body[i].second);
        addch('#'); 
    }
}
pair<int,int> tail_end;
pair<int,int> move_snake(int direction)
{       
        tail_end=body[body.size()-1];
        body.pop_back();
        pair <int,int> old_head=body[0];
        pair <int,int> new_head=old_head;
        if(direction==UP)
        {
            new_head.first--;
        }
        else if(direction==DOWN)        
        {
            new_head.first++;
        }
        else if(direction==LEFT)
        {
            new_head.second--;
        }
        else if(direction==RIGHT)
        {
            new_head.second++;
        }
        body.insert(body.begin(),new_head);  
        return new_head;
}
void grow_snake()
{
    body.push_back(tail_end);
}   

bool has_collisions()
{
    pair<int,int> head=body[0];
    int x=head.first;
    int y=head.second;
    if(x==0 or x==LINES-1 or y==0 or y==COLS-1)
    {
        return true;
    }
    for(int i=1;i<body.size();i++)
    {
        if(head==body[i])
        {
            return true;
        }
    }
    return false;

}