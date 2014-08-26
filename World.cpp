#include "World.h"

World::World(const std::string& bgImgFile){
    bgImg.LoadFromFile(bgImgFile);
    bgImg.SetSmooth(false); //prevents SFML from blurring images
    bgSprite.SetImage(bgImg);
    lives = 10;
    current_wave = 0;
}

World::~World(){
    //dtor
}

void World::SetOccupiedSpace(WorldObj* obj, int indX, int indY){
    OccupiedSpaces[indX][indY].ptr = obj;
    OccupiedSpaces[indX][indY].set = 1;
}

void World::ClearOccupiedSpace(int indX, int indY){
    delete OccupiedSpaces[indX][indY].ptr;
    OccupiedSpaces[indX][indY].ptr = NULL;
    OccupiedSpaces[indX][indY].set = 0;
}
