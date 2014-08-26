#include "Sidebar.h"
#include <iostream>

using namespace std;

sf::Image Sidebar::sidebarImg;
sf::Image Sidebar::expbarImg;
sf::Image Sidebar::expbarendImg;

Sidebar::Sidebar()
{
     sidebarSprite.SetImage(sidebarImg);
    sidebarSprite.SetPosition(600,0);
    expbarSprite.SetImage(expbarImg);
    expbarendSprite.SetImage(expbarendImg);
}

Sidebar::~Sidebar()
{
    //dtor
}

bool Sidebar::InitImg(const std::string& sidebarImgFile, const std::string& expbarImgFile, const std::string& expbarendImgFile) {
    int val = sidebarImg.LoadFromFile(sidebarImgFile);
    int val2 = expbarImg.LoadFromFile(expbarImgFile);
    int val3 = expbarendImg.LoadFromFile(expbarendImgFile);
    sidebarImg.CreateMaskFromColor(sf::Color(255, 0, 255), 0);
    expbarendImg.CreateMaskFromColor(sf::Color(255, 0, 255), 0);
    return val && val2 && val3;
}

std::string IntToStr( int n );

void Sidebar::Draw(sf::RenderWindow &App, Player &myPlayer, World& myWorld){
    App.Draw(sidebarSprite);

    double percent = myPlayer.getPercent();
    if (percent != 0.0){
        int nonbarlength = (int)(575 - 575*percent);
        expbarSprite.Resize(11, (int)(575 * percent) + 1);
        expbarSprite.SetPosition(614, 12 + nonbarlength);
        expbarendSprite.SetPosition(614, 12 + (575));
        App.Draw(expbarendSprite);
        expbarendSprite.SetPosition(614, 10 + nonbarlength);
        App.Draw(expbarendSprite);
        App.Draw(expbarSprite);
    }

    //Draw the bottom text
    sf::Font MyFont;
    if (!MyFont.LoadFromFile("images/fixedsys.ttf"))
    {
        // Error...
    }

    sf::String WaveText("Wave: " + IntToStr(myWorld.GetWave()), MyFont, 16);
    WaveText.SetPosition(670, 525);
    WaveText.SetColor(sf::Color(26, 138, 60));

    sf::String LivesText("Lives: " + IntToStr(myWorld.Getlives()), MyFont, 16);
    LivesText.SetPosition(670, 550);
    LivesText.SetColor(sf::Color(26, 138, 60));

    App.Draw(WaveText);
    App.Draw(LivesText);


}
