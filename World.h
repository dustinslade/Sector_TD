#ifndef WORLD_H
#define WORLD_H

#include "WorldObj.h"


class WorldObj;

class World{
    public:
        //this allows us to quickly see if a map position has an item in it
        typedef struct Grid{
            WorldObj* ptr;
            bool set;
            Grid() : ptr(), set(0) {}
        } Grid;
        /*
        Pre-condition: a valid bgImgFile is available
        Post-condition: a World is created and has a bgImgFile loaded into it's bgSprite
        Parameters: the working path of an image file
        Return Values: none
        */
        World(const std::string& bgImgFile);
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~World();
        /*
        Pre-condition: bgSprite has been initialized to a valid image
        Post-condition: bgSprite has not been changed
        Parameters: none
        Return Values: the sprite associated with a World
        */
        sf::Sprite GetbgSprite() const { return bgSprite; }
        /*
        Pre-condition: OccupiedSpaces is filled with Grids
        Post-condition: OccupiedSpaces has not been changed
        Parameters: a column and row index of OccupiedSpaces
        Return Values: a particular Grid from the OccupiedSpaces table
        */
        Grid GetOccupiedSpace(int indX, int indY) const { return OccupiedSpaces[indX][indY]; }
        /*
        Pre-condition: OccupiedSpaces is filled with Grids and a valid obj exists
        Post-condition: the Grid stored at the column and row has it's ptr to obj and set is changed to one
        Parameters: a column and row index of OccupiedSpaces and an obj
        Return Values: none
        */
        void SetOccupiedSpace(WorldObj* obj, int indX, int indY);
        /*
        Pre-condition: bgImg has been initialized to a valid image
        Post-condition: the World's bgImg dimensions have not been changed
        Parameters: none
        Return Values: the x dimensions of the World
        */
        int GetdimX() const { return bgImg.GetWidth(); }
        /*
        Pre-condition: bgImg has been initialized to a valid image
        Post-condition: the World's bgImg dimensions have not been changed
        Parameters: none
        Return Values: the y dimensions of the World
        */
        int GetdimY() const { return bgImg.GetHeight(); }
        /*
        Pre-condition: GetOccupiedSpace().set is true when called in player's DeleteTower
        Post-condition: the Grid stored at the column and row is "deleted"; the Tower at ptr is deallocated, the ptr is set to NULL, and set is changed to zero
        Parameters: a column and row index of OccupiedSpaces
        Return Values: none
        */
        void ClearOccupiedSpace(int indX, int indY);
        /*
        Pre-condition: Want Player's/World's live
        Post-condition: Get's live value
        Parameters: none
        Return Values: Live value
        */
        int Getlives() { return lives; }
        /*
        Pre-condition: Enemy's reached target
        Post-condition: Live lost
        Parameters: none
        Return Values:none
        */
        void DecLife() { --lives; }
        /*
        Pre-condition: None
        Post-condition: none
        Parameters: none
        Return Values: current wave number
        */
        int GetWave() { return current_wave; }
        /*
        Pre-condition: None
        Post-condition: current wave is incremented
        Parameters: none
        Return Values: none
        */
        void IncrementWave() { current_wave++; }
    protected:
    private:
        sf::Image bgImg;
        sf::Sprite bgSprite;
        Grid OccupiedSpaces[20][20]; //20x30=600
        int lives;
        int current_wave;
};

#endif // WORLD_H
