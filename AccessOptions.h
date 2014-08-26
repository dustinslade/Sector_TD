#ifndef ACCESSOPTIONS_H
#define ACCESSOPTIONS_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.h"
#include "GameHandler.h"
#include "World.h"

class AccessOptions
{
    public:
        //Pre-condition:none
        //Post-condition: none
        //Parameters: none
        //Return Values: none
        AccessOptions();
        //Pre-condition:none
        //Post-condition: none
        //Parameters: none
        //Return Values: none
        virtual ~AccessOptions();
        //Pre-condition:start new game button is selected
        //Post-condition: old game is deleted and new one is started
        //Parameters: SFML Windows
        //Return Values: true if new game is started, false otherwise
        bool startNewGame(sf::RenderWindow &Menu, sf::RenderWindow &App);
        //Pre-condition:save game button is selected
        //Post-condition: game is saved to game files
        //Parameters: World object
        //Return Values: true is game files is saved, false otherwise
        bool saveSector(World& myWorld, Player& myPlayer);
        //Pre-condition:resume game button is selected
        //Post-condition: access menu is closed, back to game screen
        //Parameters: SFML RenderWindow
        //Return Values: true if menu closes, false otherwise
        bool resumeGame(sf::RenderWindow &Menu);
        //Pre-condition:exiting game button is selected
        //Post-condition: everything closes
        //Parameters: none
        //Return Values: true if everything closes, false otherwise
        bool exitGame(sf::RenderWindow &Menu, sf::RenderWindow &App);
        //Pre-condition:menu button is selected
        //Post-condition: menu screen is executed
        //Parameters: SFML RenderWindow
        //Return Values: true is menu opens, false otherwise
        bool runAccess(sf::RenderWindow &Menu, World& myWorld, Player& myPlayer);

    protected:
    private:
};

#endif // ACCESSOPTIONS_H
