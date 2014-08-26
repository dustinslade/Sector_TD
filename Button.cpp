#include "Button.h"

//Button Default Constructor. Everything set to zero
Button::Button()
{
    pos = Position(0, 0);
    width = 0;
    height = 0;
}

//Button constructor with params. Pass in an int value for width and height.
//Position object is the top left corner of the button
Button::Button(int w, int h, Position p){
    pos = p;
    height = h;
    width = w;
}

//Button destructor
Button::~Button()
{

}
//setter
void Button::setPosition(Position p){
    pos = p;
}
//setter
void Button::setHeight(int h){
    height = h;
}
//setter
void Button::setWidth(int w){
    width = w;
}


bool Button::clickedOn(Position p){
    if((p.getX() > pos.getX() && p.getX() < (pos.getX() + width)) && (p.getY() > pos.getY() && p.getY() < (pos.getY() + height))){
        return true;
}
    return false;

}
