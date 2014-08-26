#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "WorldObj.h"
#include "Enemy.h"

class Projectile : public WorldObj{
    public:
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~Projectile();
        /*
        Pre-condition: Want Enemy's target
        Post-condition: Has Enemy's target
        Parameters: none
        Return Values: Enemy's target
        */
        Enemy* GetTarget(){ return Target; }
        /*
        Pre-condition: Want damage
        Post-condition: Has damage
        Parameters: none
        Return Values: Damage value
        */
        int GetDamage() { return damage; }
    protected:
        /*
        Pre-condition: Valid x and y positions are passed
        Post-condition: objSprite's initial position is set
        Parameters: an x and y position
        Return Values: none
        */
        Enemy* Target;
         /*
        Pre-condition: new Projectile wanted
        Post-condition: new Projectile created
        Parameters: projectile's position
        Return Values: new Projectile
        */
        Projectile(int posX, int posY);
        int damage;
    private:
};

#endif // PROJECTILE_H
