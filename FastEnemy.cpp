#include "FastEnemy.h"

sf::Image FastEnemy::FastEnemyImg;

FastEnemy::FastEnemy(int posX, int posY, int lev) : Enemy(posX, posY){
    FastEnemyImg.SetSmooth(false); //prevents SFML from blurring images
    objSprite.SetImage(FastEnemyImg);
    Velocity=5;
    health=55 * lev;
}

FastEnemy::~FastEnemy(){
    //dtor
}

