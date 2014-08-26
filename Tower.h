#ifndef TOWER_H
#define TOWER_H

#include "WorldObj.h"
#include <vector>

class Tower : public WorldObj{
    public:
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~Tower();
        /*
        Pre-condition: the Tower has a tType
        Post-condition: the tType has not been altered
        Parameters: none
        Return Values: the type identifier of the tower
        */
        int GetType() const { return tType; }
        /*
        Pre-condition: the passed obj is valid
        Post-condition: a boolean is returned and the obj is not changed
        Parameters: a WorldObj
        Return Values: true if a passed WorldObj is within the Tower's range
        */
        bool RangeCheck(const WorldObj& obj);
    protected:
        /*
        Pre-condition: Valid x and y positions are passed
        Post-condition: objSprite's initial position is set
        Parameters: an x and y position
        Return Values: none
        */
        Tower(int posX, int posY);
        //Tower's type
        int tType;
        //Tower's range
        int range;
    private:
};

#endif // TOWER_H
