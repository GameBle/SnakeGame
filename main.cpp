#include <iostream>
#include <conio.h>
#include <ctime>
#include "snake.h"
#include "food.h"
using namespace std;
#define H 25
#define W 50

//int x =10,y=10;

snake s({W/2,H/2},1);
food f;
int score = 0;

void board(){
    COORD snake_pos = s.get_pos();
    COORD food_pos = f.get_pos();
    vector<COORD> snake_body = s.get_body();
    cout<<"SCORE : "<<score<<"\n\n";
  for (int i = 0; i < H; ++i)
  {
    cout<<"\t\t#";
    for (int j = 0; j < W-2; ++j)
    {
      if(i==0||i==H-1) cout<<"#";
      else if(i==snake_pos.Y && j+1==snake_pos.X) cout<<'0';
      else if(i==food_pos.Y && j+1==food_pos.X) cout<<'@';
      else{
        bool isBodyPart = false;
        for(int k=0;k<snake_body.size()-1;k++){
            if(i==snake_body[k].Y && j==snake_body[k].X){
                cout<<'o';
                isBodyPart = true;
                break;
            }
        }
        if(!isBodyPart){
            cout<<' ';
        }
      }
    }
    cout<<"#\n";
  }
}

int main(){
    score=0;
    srand(time(NULL));
    f.gen_food();
    bool game_over = false;
  while(!game_over){
    board(); // board is being called here
    if(kbhit()){
        switch(getch()){
            case 'w': s.changeDir('u');break;
            case 'a': s.changeDir('l');break;
            case 's': s.changeDir('d');break;
            case 'd': s.changeDir('r');break;
        }
    }if(s.collided()) game_over = true;

    if(s.eaten(f.get_pos())){
        f.gen_food();
        s.grow();
        score+=10;
    }
    s.moveSnake();
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
  }
  return 0;
}
