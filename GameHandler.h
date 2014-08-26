#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "PathFinder.h"
#include "World.h"
#include "WorldObj.h"
#include "Player.h"
#include "AccessOptions.h"
#include "SlowEnemy.h"
#include "FastEnemy.h"
#include "Sidebar.h"
#include "EnemyHandler.h"
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <string>  //these two for int to str
#include <sstream> //
#include <cstdlib> //for random numbers

using namespace std;

typedef struct{
int Exp;
int Life;
} savPlayer;


typedef struct {
        //WorldObj* ptr;
        int X,Y;
        int tTypeS;
    } slTower;

class GameHandler
{
    public:
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~GameHandler();
        /*
        Pre-condition: dependencies for the application are available
        Post-condition: the main game loop is executed
        Parameters: an initialized SFML window
        Return Values: none
        */
        static void PlayGame(sf::RenderWindow& App);

         //Made in order to access World myWorld
        friend class AccessOptions;
        //Made in order to access Player myPlayer
        friend class Sidebar;
    protected:
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        GameHandler();
    private:
        static sf::RenderWindow App;
        static World myWorld;
        static Player myPlayer;
};

#endif // GAMEHANDLER_H
