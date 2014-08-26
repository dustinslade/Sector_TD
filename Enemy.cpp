#include "Enemy.h"

Enemy::Enemy(int posX, int posY) : WorldObj(posX, posY){
    targetX = 300;
    targetY = 0;
}

Enemy::~Enemy(){
    //dtor
}

void Enemy::MoveObj(int posX, int posY){
    //if we aren't out of the boundary, then we can move the player sprite
    objSprite.Move(posX, posY);
}
