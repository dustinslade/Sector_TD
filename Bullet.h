#ifndef BULLET_H
#define BULLET_H

#include "Projectile.h"
#include "Enemy.h"

class Bullet : public Projectile{
    public:
        /*
        Pre-condition: Valid x and y positions are passed
        Post-condition: objSprite's initial position is set
        Parameters: an x and y position
        Return Values: none
        */
        Bullet(int posX, int posY, Enemy& target);
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~Bullet();
        /*
        Pre-condition: a valid image file exists
        Post-condition: BulletImg is now set to an image
        Parameters: the working path of an image file
        Return Values: true if the image is sucessfully loaded
        */
        static bool InitImg(const std::string& BulletImgFile){ return BulletImg.LoadFromFile(BulletImgFile); }
    protected:
    private:
        static sf::Image BulletImg;
};

#endif // BULLET_H
