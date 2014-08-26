#include "Bullet.h"

sf::Image Bullet::BulletImg;

Bullet::Bullet(int posX, int posY,  Enemy& target) : Projectile(posX, posY){
    objSprite.SetImage(BulletImg);
    Target=&target;
    damage = 5;
}

Bullet::~Bullet(){
    //dtor
}
