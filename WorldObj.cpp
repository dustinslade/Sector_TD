#include "WorldObj.h"

WorldObj::WorldObj(int posX, int posY){
    objSprite.SetPosition(posX, posY);
}

WorldObj::~WorldObj(){
    //dtor
}

//prevents the player obj from leaving the 600x600 grid
bool WorldObj::MoveBoundary(int posX, int posY){
    return (GetposX()+posX < 600 && GetposY()+posY < 600 && GetposX()+posX >= 0 && GetposY()+posY >= 0);
}

void WorldObj::MoveObj(int posX, int posY){
    //if we aren't out of the boundary, then we can move the player sprite
    if (MoveBoundary(posX, posY)) objSprite.Move(posX, posY);
}

