#include "Position.h"

Position::Position(){
    X = 0;
    Y = 0;
}

Position::Position(int x, int y)
{
        X = x;
        Y = y;
}

Position::~Position()
{
    //dtor
}

void Position::setPosition(int x, int y){
        X = x; //This is in pixels
        Y = y; //Also in pixel
}
int Position::getX(){
    return X;
}

int Position::getY(){
    return Y;
}
