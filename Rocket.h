#ifndef ROCKET_H
#define ROCKET_H

#include "Projectile.h"

class Rocket : public Projectile{
    public:
        /*
        Pre-condition: Valid x and y positions are passed
        Post-condition: objSprite's initial position is set
        Parameters: an x and y position
        Return Values: none
        */
        Rocket(int posX, int posY, Enemy& target);
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~Rocket();
        /*
        Pre-condition: a valid image file exists
        Post-condition: RocketImg is now set to an image
        Parameters: the working path of an image file
        Return Values: true if the image is sucessfully loaded
        */
        static bool InitImg(const std::string& RocketImgFile){ return RocketImg.LoadFromFile(RocketImgFile); }
    protected:
    private:
        static sf::Image RocketImg;
};

#endif // ROCKET_H
