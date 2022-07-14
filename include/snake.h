#ifndef SNAKE_H
#define SNAKE_H
#include <windows.h>
#include <vector>
#define H 25
#define W 50
using namespace std;
class snake
{
    private:
        COORD pos;
        int len;
        int vel;
        char direction;
        vector<COORD> body;
    public:
        snake(COORD pos,int vel);
        void changeDir(char dir); //change direction
        void moveSnake();//move the snake
        COORD get_pos();
        vector<COORD> get_body();
        bool eaten(COORD food_pos);
        void grow();
        bool collided();
};

#endif // SNAKE_H
