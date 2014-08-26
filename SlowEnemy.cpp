#include "SlowEnemy.h"

sf::Image SlowEnemy::SlowEnemyImg;

SlowEnemy::SlowEnemy(int posX, int posY, int lev) : Enemy(posX, posY){
    SlowEnemyImg.SetSmooth(false); //prevents SFML from blurring images
    objSprite.SetImage(SlowEnemyImg);
    Velocity=2.5;  //must be a factor of 30
    health=100 * lev;
}

SlowEnemy::~SlowEnemy(){
    //dtor
}
