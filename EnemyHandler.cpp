#include "EnemyHandler.h"

EnemyHandler::EnemyHandler(){
    //ctor
}

EnemyHandler::~EnemyHandler(){
    //dtor
}

void EnemyHandler::CreateEnemyWave(int enemyType, int enemyLevel, WorldObj StartLoc){
    if (enemyType==0){
        for(int i=0; i<10; i++){
            EnemyWave.push_back(new SlowEnemy(StartLoc.GetposX(), StartLoc.GetposY()-i*60, enemyLevel));
        }
    }
    else if (enemyType==1){
        for(int i=0; i<10; i++){
            EnemyWave.push_back(new FastEnemy(StartLoc.GetposX(), StartLoc.GetposY()-i*60, enemyLevel));
        }
    }
}

void EnemyHandler::DoEnemyWave(World& World, sf::RenderWindow& App, PathFinder::Node& target, Player& myPlayer){
    std::list<PathFinder::Node> path;
    for(std::list<Enemy*>::iterator itr = EnemyWave.begin(); itr != EnemyWave.end(); ++itr){
        //if health is zero, then deallocate the enemy
        bool dead = ((*itr)->GetHealth() <= 0);
        bool reachedEnd = ((*itr)->GetposX() == target.posX && (*itr)->GetposY() == target.posY);
        if (dead){
            myPlayer.addExp(1);
        }
        if (reachedEnd){
            World.DecLife();
        }
        //also, if the enemy reaches the target Node, deallocate
        if(((*itr)->GetposX() == target.posX && (*itr)->GetposY() == target.posY) || dead) { //HEY JAMES INCREASE THE EXPERIENCE
            delete *itr;
            itr = EnemyWave.erase(itr);
            continue;
        }
        //get our next movement order
        if ((*itr)->GetposX()-(*itr)->targetX == 0 && (*itr)->GetposY()-(*itr)->targetY == 0){
            PathFinder::PathSearch(path, World, (**itr), target);
            std::list<PathFinder::Node>::iterator itr2 = path.begin();
            itr2++;
            (*itr)->targetX = itr2->posX;
            (*itr)->targetY = itr2->posY;
        }
        if ((*itr)->GetposX()-(*itr)->targetX > 0){
            (*itr)->MoveObj(-(*itr)->GetVelocity(), 0);
            (*itr)->RotateObj(270);
        }
        else if((*itr)->GetposX()-(*itr)->targetX < 0){
            (*itr)->MoveObj((*itr)->GetVelocity(), 0);
            (*itr)->RotateObj(90);
        }
        if ((*itr)->GetposY()-(*itr)->targetY > 0){
            (*itr)->MoveObj(0, -(*itr)->GetVelocity());
            (*itr)->RotateObj(180);
        }
        else if((*itr)->GetposY()-(*itr)->targetY < 0){
            (*itr)->MoveObj(0, (*itr)->GetVelocity());
            (*itr)->RotateObj(0);
        }
        DrawEnemyWave(App);
            path.clear();
    }


}

void EnemyHandler::DrawEnemyWave(sf::RenderWindow& App){
    for(std::list<Enemy*>::iterator itr = EnemyWave.begin(); itr != EnemyWave.end(); ++itr){
        App.Draw((*itr)->GetobjSprite());
    }
}
