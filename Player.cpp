#include "Player.h"

sf::Image Player::playerImg;

Player::Player(int posX, int posY) : WorldObj(posX, posY){
    playerImg.SetSmooth(false); //prevents SFML from blurring images
    objSprite.SetImage(playerImg);
    total_exp = 20;
     max_exp = 100;
}

Player::~Player(){
    //dtor
}

bool Player::PlaceTower(int tType, World& World, float t, PathFinder::Node target, WorldObj StartLoc){
    bool i=0;
    std::list<PathFinder::Node> path;
    //check if the space the player is in is currently occupied before trying to build
    if (!World.GetOccupiedSpace(GetposX()/30, GetposY()/30).set){
        if (tType == 1){
            World.SetOccupiedSpace(new BulletTower(GetposX(), GetposY(), t), GetposX()/30, GetposY()/30);
            i=1;
        }
        else if (tType == 2){
            World.SetOccupiedSpace(new RocketTower(GetposX(), GetposY(), t), GetposX()/30, GetposY()/30);
            i=1;
        }
    }
    //check to make sure there is a possible path. If there is no way through, the placement is undone.
    if(!(PathFinder::PathSearch(path, World, StartLoc, target))){
        World.ClearOccupiedSpace(GetposX()/30, GetposY()/30);
        i=0;
    }
    //user cannot build in an occupied position
    return i;
}

bool Player::DeleteTower(World& World){
    //confirm that the space is currently occupied
    if (World.GetOccupiedSpace(GetposX()/30, GetposY()/30).set){

        if(typeid(*World.GetOccupiedSpace(GetposX()/30, GetposY()/30).ptr).name() == "ProjectileTower")
            total_exp += 3;
        else
            total_exp += 5;
        World.ClearOccupiedSpace(GetposX()/30, GetposY()/30);
        return 1;
    }
    else{
        return 0;
    }
}
void Player::addExp(int exp){
    ( (total_exp + exp) > max_exp ) ? total_exp = max_exp : total_exp += exp;
}

void Player::subtractExp(int exp){
    ( (total_exp - exp) < 0 ) ? total_exp = 0 : total_exp -= exp;
}

double Player::getPercent(){
    return (double)total_exp / (double)max_exp;
}

int Player::getExp(){
    return total_exp;
}

void Player::setExp(int exp){
total_exp =exp;
 }
