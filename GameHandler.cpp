#include "GameHandler.h"

GameHandler::GameHandler(){
    //ctor
}

GameHandler::~GameHandler(){
    //dtor
}

std::string IntToStr( int n );

void GameHandler::PlayGame(sf::RenderWindow& App){
    //initialize Player image
    Player::InitImg("images/player.png");
    //initialize SlowEnemy image
    SlowEnemy::InitImg("images/slow_enemy.png");
    //initialize FastEnemy image
    FastEnemy::InitImg("images/fast_enemy.png");
    //initialize BulletTower image
    BulletTower::InitImg("images/bullet_tower.png");
    //initialize RocketTower image
    RocketTower::InitImg("images/rocket_tower.png");
    //initialize Bullet image
    Bullet::InitImg("images/bullet.png");
    //initialize Rocket image
    Rocket::InitImg("images/rocket.png");
    //initialize sidebar image
    Sidebar::InitImg("images/sidebar.png","images/ExpBar.png","images/expbarend.png");
    //create World, set image
    World myWorld("images/bg.png");
    //tower placement sound
    sf::SoundBuffer Tbuffer;
    Tbuffer.LoadFromFile("sounds/tower.wav");
    sf::Sound TowerSound(Tbuffer);
    //bullet projectile sound
    sf::SoundBuffer Bbuffer;
    Bbuffer.LoadFromFile("sounds/bullet.wav");
    sf::Sound BulletSound(Bbuffer);
    //rocket projectile sound
    sf::SoundBuffer Rbuffer;
    Rbuffer.LoadFromFile("sounds/rocket.wav");
    sf::Sound RocketSound(Rbuffer);
    //create Player
    Player myPlayer(300, 570);
    //set maximum framerate
    App.SetFramerateLimit(15);
    //lock key-driven events
    App.EnableKeyRepeat(FALSE);
    //initialize the Bullet clock
    sf::Clock BulletTimer;
    //initialize the Rocket clock
    sf::Clock RocketTimer;
    //initialize the wave clock
    sf::Clock WaveTimer;
    //create a sidebar
    Sidebar mySidebar = Sidebar();
    //set the target and make the first path
    PathFinder::Node target(0, 300, 570); //this is bottom center; i.e. the target
    WorldObj StartLoc(300, 0);
    EnemyHandler EnemyHandler;

    //For WaveTimer, time in seconds
    int time_until_wave = 30;

    //Tower prices
    const int bullet_tower_price = 2;
    const int rocket_tower_price = 5;

    //Load the font
    sf::Font MyFont;
    if (!MyFont.LoadFromFile("images/fixedsys.ttf"))
    {
        App.Close();
    }

    //game loop
    while(App.IsOpened()){
        //clear screen
        App.Clear();
        //draw World map
        App.Draw(myWorld.GetbgSprite());
        //draw sidebar
        mySidebar.Draw(App,myPlayer, myWorld);


        sf::Event Event;
        while (App.GetEvent(Event)){
            if (Event.Type == sf::Event::Closed)
                App.Close();
            //exit game
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();
            //place BulletTower
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Num1 && myPlayer.getExp() >= bullet_tower_price)){
                    if(myPlayer.PlaceTower(1, myWorld, BulletTimer.GetElapsedTime(), target, StartLoc))
                        myPlayer.subtractExp(bullet_tower_price);
                    TowerSound.Play();
            }
            //place RocketTower
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Num2 && myPlayer.getExp() >= rocket_tower_price)){
                    if(myPlayer.PlaceTower(2, myWorld, RocketTimer.GetElapsedTime(), target, StartLoc))
                        myPlayer.subtractExp(rocket_tower_price);
                    TowerSound.Play();
            }
            //delete Tower
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Q)){
                myPlayer.DeleteTower(myWorld);
            }

            //Access Menu
            if (App.GetInput().IsKeyDown(sf::Key::Return)){
            AccessOptions menu = AccessOptions();
            if(!menu.runAccess(App,myWorld,myPlayer)){
                App.Close();
            }
        }
            //test pathfinding
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::F1)){
                std::list<PathFinder::Node> path;
                //this will only print if the player is not blocked by towers (intentional)
                if(PathFinder::PathSearch(path, myWorld, myPlayer, target)){
                     for(std::list<PathFinder::Node>::iterator itr = path.begin(); itr != path.end(); ++itr){
                        std::cout << itr->posX << "," << itr->posY << std::endl; //this is the path the enemy needs to follow
                     }
                }
            }
        }

        if(time_until_wave == -1){
            myWorld.IncrementWave();
            int num = rand() % 2;
            //send fast wave
            if (num == 0){
                EnemyHandler.CreateEnemyWave(1, myWorld.GetWave(), StartLoc);
            }
            //send slow wave
            else{
                EnemyHandler.CreateEnemyWave(0, myWorld.GetWave(), StartLoc);
            }
            time_until_wave--;
        }

        //handle losing the game
        if(myWorld.Getlives() <= 0){
            sf::String LoseText("You Lose", MyFont, 40);
            LoseText.SetPosition(250, 250);
            LoseText.SetColor(sf::Color(255, 0, 0));
            time_until_wave--;
            App.Draw(LoseText);

        }
        //left
        if (App.GetInput().IsKeyDown(sf::Key::A)) myPlayer.MoveObj(-30, 0);
        //right
        if (App.GetInput().IsKeyDown(sf::Key::D)) myPlayer.MoveObj(30, 0);
        //up (remember that Y is from 600 to 0, not 0 to 600)
        if (App.GetInput().IsKeyDown(sf::Key::W)) myPlayer.MoveObj(0, -30);
        //down
        if (App.GetInput().IsKeyDown(sf::Key::S)) myPlayer.MoveObj(0, 30);
        //clear screen
        //App.Clear();
        //draw World map
        //App.Draw(myWorld.GetbgSprite());
        //draw sidebar
        //mySidebar.Draw(App,myPlayer, myWorld);
        //draw Player
        App.Draw(myPlayer.GetobjSprite());

        //change timer and draw wave time
        if( (int) WaveTimer.GetElapsedTime() == 1 && time_until_wave > -1){
            time_until_wave--;
            WaveTimer.Reset();
        }
        sf::String TimeText("Next Wave in " + IntToStr(time_until_wave) + " seconds", MyFont, 20);
        TimeText.SetPosition(0, 0);
        TimeText.SetColor(sf::Color(255, 255, 255));

        if(EnemyHandler.GetEnemyWave().empty() && time_until_wave == -2){
            time_until_wave = 30;
            WaveTimer.Reset();
        }

        //move enemies
        EnemyHandler.DoEnemyWave(myWorld, App, target, myPlayer);
        //EnemyHandler.DrawEnemyWave(App);
        //set path at the beginning of each whileloop
        //PathFinder::PathSearch(path, myWorld, myPlayer, target);
        //this loops through every Grid
        for (int x = 0; x < 20; ++x){
            for (int y = 0; y < 20; ++y){
                if (myWorld.GetOccupiedSpace(x, y).set){
                    //draw towers
                    App.Draw(myWorld.GetOccupiedSpace(x, y).ptr->GetobjSprite());
                    for(std::list<Enemy*>::iterator itr = EnemyHandler.EnemyWave.begin(); itr != EnemyHandler.EnemyWave.end(); ++itr){
                        //std::cout<<(**itr).GetHealth()<<std::endl;
                        //create bullets if the player is within the range of a bullet tower
                        if(static_cast<Tower*>(myWorld.GetOccupiedSpace(x, y).ptr)->GetType() == 1 &&
                           ((BulletTimer.GetElapsedTime()) - (static_cast<ProjectileTower*>(myWorld.GetOccupiedSpace(x, y).ptr)->GetTimeLastShot())) > (static_cast<ProjectileTower*>(myWorld.GetOccupiedSpace(x, y).ptr)->GetFrequency()))
                                static_cast<BulletTower*>(myWorld.GetOccupiedSpace(x, y).ptr)->MakeBullet((**itr), BulletTimer.GetElapsedTime(), BulletSound);
                        //or create rockets for a rocket tower
                        else if(static_cast<Tower*>(myWorld.GetOccupiedSpace(x, y).ptr)->GetType() == 2 &&
                            ((RocketTimer.GetElapsedTime()) - (static_cast<ProjectileTower*>(myWorld.GetOccupiedSpace(x, y).ptr)->GetTimeLastShot())) > (static_cast<ProjectileTower*>(myWorld.GetOccupiedSpace(x, y).ptr)->GetFrequency()))
                                static_cast<RocketTower*>(myWorld.GetOccupiedSpace(x, y).ptr)->MakeRocket((**itr), BulletTimer.GetElapsedTime(), RocketSound);
                    }
                    //move and draw all projectiles
                    if((static_cast<Tower*>(myWorld.GetOccupiedSpace(x, y).ptr)->GetType() == 1) ||
                       (static_cast<Tower*>(myWorld.GetOccupiedSpace(x, y).ptr)->GetType() == 2)){
                        //move projectiles (to player atm)
                            static_cast<ProjectileTower*>(myWorld.GetOccupiedSpace(x, y).ptr)->DoProjectile(myPlayer, App);
                        //draw projectiles
                        static_cast<ProjectileTower*>(myWorld.GetOccupiedSpace(x, y).ptr)->DrawProjectile(App);
                    }
                }
            }
        }
        //Draw this last to be on top
        if(time_until_wave > -1) App.Draw(TimeText);

        //render drawn objects
        App.Display();
    }
}

std::string IntToStr( int n )
  {
  std::ostringstream result;
  result << n;
  return result.str();
  }
