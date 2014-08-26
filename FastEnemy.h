#ifndef FASTENEMY_H
#define FASTENEMY_H

#include "Enemy.h"

class FastEnemy : public Enemy{
    public:
    /*
        Pre-condition: want a new fast enemy
        Post-condition: new fast enemy created
        Parameters: fast enemy x-pos and y-pos
        Return Values: new fast enemy
        */
        FastEnemy(int posX, int posY, int lev);
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~FastEnemy();
        /*
        Pre-condition: a valid image file exists
        Post-condition: FastEnemyImg is now set to an image
        Parameters: the working path of an image file
        Return Values: true if the image is sucessfully loaded
        */
        static bool InitImg(const std::string& FastEnemyImgFile){ return FastEnemyImg.LoadFromFile(FastEnemyImgFile); }
    protected:
    private:
        static sf::Image FastEnemyImg;
};

#endif // FASTENEMY_H
