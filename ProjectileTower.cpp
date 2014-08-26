#include "ProjectileTower.h"

ProjectileTower::ProjectileTower(int posX, int posY, float t) : Tower(posX, posY){
    TimeLastShot = t;
}

ProjectileTower::~ProjectileTower(){
    for(std::vector<Projectile*>::iterator itr = ProjectileClip.begin(); itr != ProjectileClip.end(); ++itr){
        delete (*itr);
    }
}

void ProjectileTower::DrawProjectile(sf::RenderWindow& App){
    for(std::vector<Projectile*>::iterator itr = ProjectileClip.begin(); itr != ProjectileClip.end(); ++itr){
        App.Draw((*itr)->GetobjSprite());
    }
}

bool ProjectileTower::DoProjectile(WorldObj obj, sf::RenderWindow& App){
    for(std::vector<Projectile*>::iterator itr = ProjectileClip.begin(); itr != ProjectileClip.end(); ++itr){
        //set angle of Projectile
        float b = (600 - (*itr)->GetposY()) - (600 - (*itr)->GetTarget()->GetposY()); //put y-coordinates in terms of the standard cartesian (0 to 600 instead of 600 to 0); pythagorean side b
        float a = (*itr)->GetposX() - (*itr)->GetTarget()->GetposX(); //pythagorean side a
        float c = sqrt(a*a + b*b); //pythagorean side c
        float angle = (180/PI)*asin(a/c); //find the rad to our obj, convert to degrees
        if ((*itr)->GetTarget()->GetposY() > (*itr)->GetposY()) angle = 180 - angle; //if the obj is below the Projectile, then we need to flip the Projectile's sprite
        (*itr)->RotateObj(angle); //rotate the actual sprite
        //move Projectile to target
        int aOffset, bOffset;
        //a must be flipped for the Projectile to move towards the WorldObj (b is already flipped); we add 30 to offset the flip when we are a positive x from the Projectile
        if ((*itr)->GetposX() < (*itr)->GetTarget()->GetposX()) aOffset = -a+30;
        else aOffset = -a;
        if ((*itr)->GetposY() < (*itr)->GetTarget()->GetposY()) bOffset = b+30;
        else bOffset = b;
        (*itr)->MoveObj(aOffset*App.GetFrameTime()*projVelocity, bOffset*App.GetFrameTime()*projVelocity); //if a is not negative, then the Projectile will move in the opposite direction; b is already flipped for us (600-posY)
        //check if Projectile has hit obj and deallocate
        if (!(abs((*itr)->GetposX() - (*itr)->GetTarget()->GetposX()) > 30 || abs((*itr)->GetposY() - (*itr)->GetTarget()->GetposY()) > 30) && //is the object inside of the 30x30 space
            (((*itr)->GetposY() - (*itr)->GetTarget()->GetposY()) >= 0) && //because we used abs(), make sure that negative displacement is ignored (Projectile traveling under a tower)
            (((*itr)->GetposX() - (*itr)->GetTarget()->GetposX()) >= 0)) {
            (*itr)->GetTarget()->DamageEnemy((*itr)->GetDamage());
            std::cout << (*itr)->GetTarget()->GetHealth() << std::endl;
            ProjectileClip.erase(itr);
            return true;
        } //same for x (Projectile traveling right from a tower)
    }
    return false;
}
