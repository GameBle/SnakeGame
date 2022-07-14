#include "snake.h"
#define H 25
#define W 50
snake::snake(COORD pos,int vel)
{
    this->pos = pos;//this is used because variable name is same
    this->vel = vel;
    len = 1;
    direction = 'n';
    body.push_back(pos);
}
void snake::changeDir(char dir){direction = dir;}
COORD snake::get_pos(){return pos;}
void snake::grow(){
    len++;
}
vector<COORD> snake::get_body(){return body;}
void snake::moveSnake(){
    switch(direction){
        case 'u' : pos.Y-=vel;break;
        case 'd' : pos.Y+=vel;break;
        case 'l' : pos.X-=vel;break;
        case 'r' : pos.X+=vel;break;
    }
    body.push_back(pos);
    if(body.size()> len) body.erase(body.begin());
}

bool snake::eaten(COORD food_pos){
    if(food_pos.X==pos.X && food_pos.Y==pos.Y){
        return true;
    }else{
        return false;
    }
}
bool snake::collided(){
    if(pos.X<1 || pos.X>W){
        return true;
    }else if(pos.Y<1 || pos.Y>H){
        return true;
    }
    for(int i=0;i<len-1;i++){
        if(pos.X==body[i].X && pos.Y==body[i].Y) {
            return true;
        }
    }
    return false;
}
