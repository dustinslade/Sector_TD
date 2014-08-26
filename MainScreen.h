#ifndef MAINSCREEN_H
#define MAINSCREEN_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Button.h"


class MainScreen
{
    public:
    /*Pre-condition:none
    Post-condition:none
    Parameters:none
    Return Values: none*/
        static MainScreen& Instance()
        {
            static MainScreen singleton;
            return singleton;
        }

        //Preconditions: A Game window has been created.
        //Postconditions: User sees the main screen and chooses an option
        //Parameter: A reference to the Game window (because we don't want this to be copied)
        //Return Values: true if the files were loaded correctly without error. false otherwise.
        bool run(sf::RenderWindow &Game);

        //Preconditions: A Game window has been created.
        //Postconditions: User sees the intro screen and waits for next screen
        //Parameter: A reference to the Game window (because we don't want this to be copied)
        //Return Values: none
        bool Intro(sf::RenderWindow &Game);
        /*Pre-condition:none
        Post-condition:none
        Parameters:none
        Return Values: none*/
        virtual ~MainScreen();
    protected:
    private:
        MainScreen();
        MainScreen(const MainScreen&);
        MainScreen& operator=(const MainScreen&);

};

#endif // MAINSCREEN_H
