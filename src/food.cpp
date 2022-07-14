#include "food.h"

void food::gen_food(){
  pos.X = rand() % W-3+1;
  pos.Y = rand() % H-3+1;
}
COORD food::get_pos(){
    return pos;
}
