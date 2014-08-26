#ifndef SIDEBAR_H
#define SIDEBAR_H
#include "GameHandler.h"
#include "WorldObj.h"

class Sidebar
{
    public:
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        Sidebar();
        /*
        Pre-condition: none
        Post-condition: none
        Parameters: none
        Return Values: none
        */
        virtual ~Sidebar();
        /*
        Pre-condition: a valid image file exists
        Post-condition: sidebarImg is now set to an image
        Parameters: the working path of an image file
        Return Values: true if the image is sucessfully loaded
        */
        static bool InitImg(const std::string& sidebarImgFile, const std::string& expbarImgFile, const std::string& expbarendImgFile);
        /*
        Pre-condition: Want to draw sidebar
        Post-condition: Sidebar on screen
        Parameters: SFML Window
        Return Values: none
        */
       void Draw(sf::RenderWindow &App, Player &myPlayer, World& myWorld);
    protected:
    private:
        static sf::Image sidebarImg;
        static sf::Image expbarImg;
        static sf::Image expbarendImg;
        sf::Sprite sidebarSprite;
        sf::Sprite expbarSprite;
        sf::Sprite expbarendSprite;
};

#endif // SIDEBAR_H
