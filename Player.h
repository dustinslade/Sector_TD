#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "WorldObj.h"
#include "BulletTower.h"
#include "RocketTower.h"
#include "PathFinder.h"
#include <typeinfo>


class Player : public WorldObj{
    public:
        /*
        Pre-condition: valid x and y positions are passed
        Post-condition: objSprite's initial position is set
        Parameters: an x and y position
        Return Values: none
        */
        Player(int posX, int posY);
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~Player();
        /*
        Pre-condition: a valid image file exists
        Post-condition: playerImg is now set to an image
        Parameters: the working path of an image file
        Return Values: true if the image is sucessfully loaded
        */
        static bool InitImg(const std::string& playerImgFile) { return playerImg.LoadFromFile(playerImgFile); }
        /*
        Pre-condition: a valid tower type is passed
        Post-condition: the World's OccupiedSpaces position is updated with a tower
        Parameters: a Tower type and World
        Return Values: true if the tower is placed and the position is not occupied
        */
        bool PlaceTower(int tType, World& World, float t, PathFinder::Node target, WorldObj StartLoc);
        /*
        Pre-condition: the player is in a valid grid of World
        Post-condition: if the grid is occupied, the item within the grid is deleted, otherwise, nothing occurs
        Parameters: a reference to a World type (it will be altered)
        Return Values: true if the tower is deleted, false if the tower is not deleted
        */
        bool DeleteTower(World& World);
         /*
        Pre-condition: the player has been created
        Post-condition: the exp of the player is increased by a certain amount
        Parameters: an integer number of experience points
        Return Values: none
        */
        void addExp(int exp);
        /*
        Pre-condition: the player has been created
        Post-condition: the exp of the player is decreased by a certain amount
        Parameters: an integer number of experience points
        Return Values: none
        */
        void subtractExp(int exp);
        /*
        Pre-condition: player created
        Post-condition: none
        Parameters: none
        Return Values: value between 0-1 representing the percent of exp_to_level that the player has
        */
        double getPercent();
        /*
        Pre-condition: player created
        Post-condition: none
        Parameters: none
        Return Values: value of player's experience
        */
        int getExp();
        /*
        Pre-condition: player created
        Post-condition: player's experience set
        Parameters: desires exp value
        Return Values: none
        */
        void setExp(int exp);
    protected:
    private:
        static sf::Image playerImg;
        static const WorldObj StartLoc;
        int total_exp;
        int max_exp;
};

#endif // PLAYER_H
