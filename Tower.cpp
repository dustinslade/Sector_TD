#include "Tower.h"

Tower::Tower(int posX, int posY) : WorldObj(posX, posY){
    //ctor
}

Tower::~Tower(){
    //dtor
}

bool Tower::RangeCheck(const WorldObj& obj){
    return (((abs(obj.GetposX()-GetposX())/30) <= range) && ((abs(obj.GetposY()-GetposY())/30) <= range));
}

