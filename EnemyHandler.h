#ifndef ENEMYHANDLER_H
#define ENEMYHANDLER_H

#include "Tower.h"
#include "Enemy.h"
#include "Location.h"
#include "SlowEnemy.h"
#include "FastEnemy.h"
#include "PathFinder.h"
#include "Player.h"

#include <SFML/Audio.hpp>
#include <cmath>
#include <iostream>

#define PI 3.14159265

class EnemyHandler
{
    public:
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        EnemyHandler();
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~EnemyHandler();
        /*
        Pre-condition: Want to creat an Enemy
        Post-condition: Enemy is created
        Parameters: Enemy's type, level, and starting location
        Return Values: none
        */
        void CreateEnemyWave(int enemyType, int enemyLevel, WorldObj StartLoc);
        /*
        Pre-condition: Want to start enemy wave
        Post-condition: Enemy wave started
        Parameters: World, SFML Window, a target
        Return Values: none
        */
        void DoEnemyWave(World& World, sf::RenderWindow& App, PathFinder::Node& target, Player& myPlayer);
        /*
        Pre-condition: Want to draw wave
        Post-condition: Wave drawn on screen
        Parameters: SFML Window
        Return Values: none
        */
        void DrawEnemyWave(sf::RenderWindow& App);
        /*
        Pre-condition: Want to get a list of enemy wave
        Post-condition: got list
        Parameters: none
        Return Values: list of enemys
        */
        std::list<Enemy*> GetEnemyWave() { return EnemyWave; }
        //list of enemy wave
        std::list<Enemy*> EnemyWave;

};

#endif // ENEMYHANDLER_H
