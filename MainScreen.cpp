#include "MainScreen.h"


MainScreen::MainScreen()
{
    //ctor
}

MainScreen::~MainScreen()
{
    //dtor
}

bool MainScreen::Intro(sf::RenderWindow &Game){


    //initialize clock
    sf::Clock timer;

    //initialize first image
    sf::Image first_screen;
    //initialize 2nd screen
    sf::Image enter_screen;

    //load images for screens
    first_screen.LoadFromFile("images/intro1.png");
    enter_screen.LoadFromFile("images/intro2.png");

    //initialize two sprites for the screens
    sf::Sprite first_screen_sprite;
    sf::Sprite enter_screen_sprite;

    //set the sprites
    enter_screen_sprite.SetImage(enter_screen);
    first_screen_sprite.SetImage(first_screen);

    //set positions of sprite
    first_screen_sprite.SetPosition(0,0);
    enter_screen_sprite.SetPosition(0,0);

    //clear window
    Game.Clear();

    //Draw Sprite
    Game.Draw(first_screen_sprite);
    //display the window
    Game.Display();

    Game.Clear();
    //Draw enter screen
    Game.Draw(enter_screen_sprite);
    Game.Display();

    timer.Reset();
    int current_screen = 1;
    //loop for screen being open
    while(Game.IsOpened())
    {
            //initialize Event
    sf::Event Event;
        if(timer.GetElapsedTime() > .5){
            Game.Clear();
            current_screen == 1 ? Game.Draw(first_screen_sprite) : Game.Draw(enter_screen_sprite);
            Game.Display();
            timer.Reset();
            current_screen = current_screen == 1 ? 0 : 1;
        }

        while(Game.GetEvent(Event)){
            //for closing window
            if((Event.Type == sf::Event::Closed) || ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))){
                Game.Close();
                return false;
            }
            if(Event.Type == sf::Event::KeyPressed && Event.Key.Code == 278)
                return true;

            }
    }
}




bool MainScreen::run(sf::RenderWindow &Game){

    //BUG TO FIX: When closing the window on New Game options, a new game is created anyway.
    //set maximum framerate
    Game.SetFramerateLimit(15);

    //initalize event
    sf::Event Event;

    //calls function Intro and uses Game window
    if(!Intro(Game))
        return false;

    //initialize image
    sf::Image image;
    //load correct image
    if(!image.LoadFromFile("images/options.png"))
        return false;

    //Create a sprite
    sf::Sprite sprite;

    //set sprite image
    sprite.SetImage(image);

    //set the sprite position
    sprite.SetPosition(0,0);
    //initialize new game button
    //first two inputs are the actual pixel size of the button (or text)
    //for position, open photoshop, make a selection that goes as high as the text on the screen but the width ends at the beginning of the text
    //the width is the first entry, the second entry is the title size (600) minus the height
    Button newGame = Button(176, 26, Position(100, 400));

    while(Game.IsOpened())
    {
        //loop for event handling
        if(Game.GetEvent(Event))
        {
            //for closing window
            if((Event.Type == sf::Event::Closed) || ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))){
                Game.Close();
                return false;
            }

            Position click = Position(Event.MouseButton.X, Event.MouseButton.Y);
            if(Event.Type == sf::Event::MouseButtonPressed && newGame.clickedOn(click))
                return true;
        }
        //clear window
        Game.Clear();

        //Draw Sprite
        Game.Draw(sprite);
        //display the window
        Game.Display();
    }

    return true;

}
