#ifndef ROCKETTOWER_H
#define ROCKETTOWER_H

#include "ProjectileTower.h"
#include "Rocket.h"

class RocketTower : public ProjectileTower{
    public:
        /*
        Pre-condition: Valid x and y positions are passed
        Post-condition: objSprite's initial position is set
        Parameters: an x and y position
        Return Values: none
        */
        RocketTower(int posX, int posY, float t);
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~RocketTower();
        /*
        Pre-condition: a ProjClip exists and a WorldObj is in range of the tower
        Post-condition: the end of the ProjClip contains a pointer to a new Proj
        Parameters: none
        Return Values: none
        */
        void MakeRocket(Enemy& obj, float time, sf::Sound& RocketSound);
        /*
        Pre-condition: a valid image file exists
        Post-condition: RocketTowerImg is now set to an image
        Parameters: the working path of an image file
        Return Values: true if the image is sucessfully loaded
        */
        static bool InitImg(const std::string& RocketTowerImgFile){ return RocketTowerImg.LoadFromFile(RocketTowerImgFile); }
    protected:
    private:
        static sf::Image RocketTowerImg;
};

#endif // ROCKETTOWER_H
