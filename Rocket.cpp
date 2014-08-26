#include "Rocket.h"

sf::Image Rocket::RocketImg;

Rocket::Rocket(int posX, int posY, Enemy& target) : Projectile(posX, posY){
    objSprite.SetImage(RocketImg);
    Target=&target;
    damage = 10;
}

Rocket::~Rocket(){
    //dtor
}
