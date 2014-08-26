#ifndef LOCATION_H
#define LOCATION_H

#include "WorldObj.h"


class Location : public WorldObj
{
    public:
    /*
        Pre-condition: Valid x and y positions are passed
        Post-condition: obj's initial position is set
        Parameters: an x and y position
        Return Values: none
        */
        Location(int posX, int posY) : WorldObj(posX, posY){};
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~Location();
    protected:
    private:
};

#endif // LOCATION_H
