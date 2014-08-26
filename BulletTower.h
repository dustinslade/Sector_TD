#ifndef BULLETTOWER_H
#define BULLETTOWER_H

#include "ProjectileTower.h"
#include "Bullet.h"

class BulletTower : public ProjectileTower{
    public:
        /*
        Pre-condition: Valid x and y positions are passed
        Post-condition: objSprite's initial position is set
        Parameters: an x and y position
        Return Values: none
        */
        BulletTower(int posX, int posY, float t);
        /*
        Pre-condition: none
        Post-condition: each Bullet in the BulletClip is safely deallocated
        Parameters: none
        Return Values: none
        */
        virtual ~BulletTower();
        /*
        Pre-condition: a ProjClip exists and a WorldObj is in range of the tower
        Post-condition: the end of the ProjClip contains a pointer to a new Proj
        Parameters: none
        Return Values: none
        */
        void MakeBullet(Enemy& obj, float time, sf::Sound& BulletSound);
        /*
        Pre-condition: a valid image file exists
        Post-condition: BulletTowerImg is now set to an image
        Parameters: the working path of an image file
        Return Values: true if the image is sucessfully loaded
        */
        static bool InitImg(const std::string& BulletTowerImgFile){ return BulletTowerImg.LoadFromFile(BulletTowerImgFile); }
    protected:
    private:
        static sf::Image BulletTowerImg;
};

#endif // BULLETTOWER_H
