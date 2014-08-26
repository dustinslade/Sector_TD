#ifndef ENEMY_H
#define ENEMY_H

#include "WorldObj.h"
#include "PathFinder.h"
#include <iostream>

class Enemy : public WorldObj{
    public:
        /*
        Pre-condition: none
        Post-condition: each Bullet in the BulletClip is safely deallocated
        Parameters: none
        Return Values: none
        */
        virtual ~Enemy();
        /*
        Pre-condition: Want to get velocity of Sprite
        Post-condition: gets velocity
        Parameters: none
        Return Values: the velocity of enemy
        */
        int GetVelocity(){ return Velocity; }
        /*
        Pre-condition: Enemy attack Player
        Post-condition: Player's life decreases
        Parameters: amount of damage
        Return Values: none
        */
        void DamageEnemy(int d) {health-=d ; }
        /*
        Pre-condition: Want to get health of Enemy
        Post-condition: gets health
        Parameters: none
        Return Values: the health of enemy
        */
        int GetHealth() { return health; }
        /*
        Pre-condition: the position passed is not out of bounds (MoveBoundary returns true)
        Post-condition: objSprite is moved to a new position
        Parameters: an x and y position and a World
        Return Values: none
        */
        void MoveObj(int posX, int posY);
        /*Variables that present target's position*/
        int targetX, targetY;
    protected:
        Enemy(int posX, int posY);
        int Velocity;
        int health;
    private:

};

#endif // ENEMY_H
