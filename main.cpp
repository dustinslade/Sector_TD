#include "GameHandler.h"
#include "MainScreen.h"

int main()
{

    //initialize music
    sf::Music Game_Music;
    //load music
    Game_Music.OpenFromFile("sounds/game_music.ogg");
    //play music
    Game_Music.Play();
    //create game RenderWindow
    sf::RenderWindow App(sf::VideoMode(600, 600, 32), "SectorTD Menu");
    //create main screen
    if(!MainScreen::Instance().run(App)){
        return -1;
    }
    App.Create(sf::VideoMode(800, 600, 32), "SectorTD");
    //stop music
    Game_Music.Stop();
    //begin main game
    GameHandler::PlayGame(App);
    //end
    return EXIT_SUCCESS;
}
