#ifndef FOOD_H
#define FOOD_H
#include <windows.h>
#include <cstdlib>
#define H 25
#define W 50
class food
{
private:
    COORD pos;

public:
    void gen_food();
    COORD get_pos();

};

#endif // FOOD_H
