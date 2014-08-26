#include "RocketTower.h"

sf::Image RocketTower::RocketTowerImg;

RocketTower::RocketTower(int posX, int posY, float t) : ProjectileTower(posX, posY, t){
    tType = 2;
    range = 4;
    Frequency = 1;
    RocketTowerImg.SetSmooth(false); //prevents SFML from blurring images
    objSprite.SetImage(RocketTowerImg);
    projVelocity = 4;
}

RocketTower::~RocketTower(){
    //dtor
}

void RocketTower::MakeRocket(Enemy& obj, float time, sf::Sound& RocketSound){
    if (RangeCheck(obj)){
        ProjectileClip.push_back(new Rocket(GetposX(), GetposY(), obj)); //puts Projectile at corner of tower (add 15 to put in center)
        TimeLastShot = time;
        RocketSound.Play();
    }
}

