#ifndef WORLDOBJ_H
#define WORLDOBJ_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"

class World;

class WorldObj{
    public:
        /*
        Pre-condition: Valid x and y positions are passed
        Post-condition: objSprite's initial position is set
        Parameters: an x and y position
        Return Values: none
        */
        WorldObj(int posX, int posY);
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~WorldObj();
        /*
        Pre-condition: the particular WorldObj has an initialized image that has been loaded into the objSprite
        Post-condition: objSprite has not been changed
        Parameters: none
        Return Values: the sprite associated with a WorldObj
        */
        sf::Sprite GetobjSprite() const { return objSprite; }
        /*
        Pre-condition: the child obj has set the position of it's sprite
        Post-condition: objSprite's position has not been changed
        Parameters: none
        Return Values: the x position of objSprite
        */
        int GetposX() const { return objSprite.GetPosition().x; }
        /*
        Pre-condition: the child obj has set the position of it's sprite
        Post-condition: objSprite's position has not been changed
        Parameters: none
        Return Values: the y position of objSprite
        */
        int GetposY() const { return objSprite.GetPosition().y; }
        /*
        Pre-condition: Valid x and y positions are passed, World dimensions are assumed (fixed)
        Post-condition: a boolean value is set and returned
        Parameters: an x and y position and a World
        Return Values: true if the position is within the bounds, false otherwise
        */
        bool MoveBoundary(int posX, int posY);
        /*
        Pre-condition: the position passed is not out of bounds (MoveBoundary returns true)
        Post-condition: objSprite is moved to a new position
        Parameters: an x and y position and a World
        Return Values: none
        */
        void MoveObj(int posX, int posY);
        /*
        Pre-condition: an objSprite is loaded
        Post-condition: objSprite is rotated
        Parameters: an angle in degrees
        Return Values: none
        */
        void RotateObj(float angle) { objSprite.SetRotation(angle); }
         /*
        Pre-condition: an objSprite needs a center
        Post-condition: objSprite is centered
        Parameters: position of center
        Return Values: none
        */
        void SetCenter(float x, float y){ objSprite.SetCenter(x, y); }
    protected:
        sf::Sprite objSprite;
    private:
};

#endif // WORLDOBJ_H
