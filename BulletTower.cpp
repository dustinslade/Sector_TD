#include "BulletTower.h"

sf::Image BulletTower::BulletTowerImg;

BulletTower::BulletTower(int posX, int posY, float t) : ProjectileTower(posX, posY, t){
    tType = 1;
    range = 3;
    Frequency = 0.5;
    BulletTowerImg.SetSmooth(false); //prevents SFML from blurring images
    objSprite.SetImage(BulletTowerImg);
    projVelocity = 8;
}

BulletTower::~BulletTower(){
    //dtor
}

void BulletTower::MakeBullet( Enemy& obj, float time, sf::Sound& BulletSound){
    if (RangeCheck(obj)){
        ProjectileClip.push_back(new Bullet(GetposX(), GetposY(), obj)); //puts Projectile at corner of tower (add 15 to put in center)
        TimeLastShot = time;
        BulletSound.Play();
    }
}
