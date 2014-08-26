#ifndef SLOWENEMY_H
#define SLOWENEMY_H

#include "Enemy.h"

class SlowEnemy : public Enemy{
    public:
        /*
        Pre-condition: want a new slow enemy
        Post-condition: new slow enemy created
        Parameters: slow enemy x-pos and y-pos
        Return Values: new slow enemy
        */
        SlowEnemy(int posX, int posY, int lev);
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~SlowEnemy();
        /*
        Pre-condition: a valid image file exists
        Post-condition: FastEnemyImg is now set to an image
        Parameters: the working path of an image file
        Return Values: true if the image is sucessfully loaded
        */
        static bool InitImg(const std::string& SlowEnemyImgFile){ return SlowEnemyImg.LoadFromFile(SlowEnemyImgFile); }
    protected:
    private:
        static sf::Image SlowEnemyImg;
};

#endif // SLOWENEMY_H
