#include "AccessOptions.h"

//constructor
AccessOptions::AccessOptions()
{
    //ctor
}
//destructor
AccessOptions::~AccessOptions()
{
    //dtor
}
//function
bool AccessOptions::startNewGame(sf::RenderWindow &Menu, sf::RenderWindow &App)
{
    //needs world making to be made into a
    //function instead of something just found in the main.
     Menu.Close();

    App.Create(sf::VideoMode(800, 600, 32), "SectorTD");
    GameHandler::PlayGame(App);
    return true;

}
//function
bool AccessOptions::saveSector(World& myWorld, Player& myPlayer)
{
    slTower towerS[400];
    savPlayer playerSaved;
    int numTowersSaved =0;
    ofstream  myfile;
    myfile.open("savingSector.txt");
    for(int j=0; j<400; j++){
        towerS[j].X =0;
        towerS[j].Y =0;
        towerS[j].tTypeS =0;
    }

    playerSaved.Exp = myPlayer.getExp();
    playerSaved.Life = myWorld.Getlives();
    myfile << playerSaved.Exp<<' ';
    myfile << playerSaved.Life<<'\n';

    for(int n= 0; n<20; n++){
        for(int m=0; m<20; m++){
            if(myWorld.GetOccupiedSpace(n,m).set){
               numTowersSaved++;
            }
        }
    }


    myfile << numTowersSaved<<'\n';
    for(int x= 0; x<20; x++){
        for(int y=0; y<20; y++){
            if(myWorld.GetOccupiedSpace(x,y).set){
                towerS[y].X =x;
                towerS[y].Y =y;
                towerS[y].tTypeS = static_cast<Tower*>(myWorld.GetOccupiedSpace(x,y).ptr)->GetType();
                myfile << towerS[y].X << ' ';
                myfile << towerS[y].Y << ' ';
                myfile << towerS[y].tTypeS << '\n';
            }
        }
    }
        myfile.close();
    return 1;
}



//function
bool AccessOptions::resumeGame(sf::RenderWindow &Menu)
{
    Menu.Close();
    return true;
}
//function
bool AccessOptions::exitGame(sf::RenderWindow &Menu, sf::RenderWindow &App)
{
    Menu.Close();
 //how do you delete the Game...just close window??
    App.Close();
    return true;
}
//function
bool AccessOptions::runAccess(sf::RenderWindow &Menu, World& myWorld, Player& myPlayer)
{
    //extern World myWorld;
    //creating an image and using events
    sf::Event Event;

    sf::Image image;
    if(!image.LoadFromFile("images/accessMenu2.png"))
    return false;

    //create a sprite
    sf::Sprite sprite;
    sprite.SetImage(image);

    int xoffset = 50;
    int yoffset = 25;

    sprite.SetPosition(xoffset,yoffset);

    //list of Buttons on screen
    Button newGame = Button(305,73,Position(100+xoffset,42+yoffset));
    Button saveGame = Button(193,72,Position(165+xoffset,150+yoffset));
    Button resumeGame = Button(233,74,Position(144+xoffset,269+yoffset));
    Button exitGame = Button(139,87,Position(195+xoffset,380+yoffset));

    while(Menu.IsOpened())
    {
        //loop for event handling
        if(Menu.GetEvent(Event))
        {
            if(Event.Type==sf::Event::Closed)
            Menu.Close();

            Position click = Position(Event.MouseButton.X, Event.MouseButton.Y);
            //determining what button is pressed & task to follow
            if(Event.Type==sf::Event::MouseButtonPressed && newGame.clickedOn(click))
                {
                    sf::RenderWindow App;
                    startNewGame(Menu, App);
                }
            if(Event.Type==sf::Event::MouseButtonPressed && saveGame.clickedOn(click))
                {
                    saveSector(myWorld,myPlayer);
                }
            if(Event.Type==sf::Event::MouseButtonPressed && resumeGame.clickedOn(click))
                {
                    return true;
                }
            if(Event.Type==sf::Event::MouseButtonPressed &&exitGame.clickedOn(click))
                {
                    //also closes all other windows and system
                    return false;
                }
            }
        //clear window
        //Menu.Clear();

        //draw sprite
        Menu.Draw(sprite);
        //display
        Menu.Display();
    }
    return true;
}
