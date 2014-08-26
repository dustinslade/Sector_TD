#ifndef BUTTON_H
#define BUTTON_H
#include "Position.h"

class Button
{
    public:
        //Pre-condition:none
        //Post-condition: none
        //Parameters: none
        //Return Values: none
        Button();
        //Pre-condition:none
        //Post-condition: a new button with a position is created
        //Parameters: width, height and position of button
        //Return Values: none
        Button(int w, int h, Position p);
        //Pre-condition:object needs a position
        //Post-condition: position is set
        //Parameters: position
        //Return Values: none
        void setPosition(Position p);
        //Pre-condition:has object user wants to set height for
        //Post-condition: a height is set
        //Parameters: height
        //Return Values: none
        void setHeight(int h);
        //Pre-condition:has object user wants to set width for
        //Post-condition: a width is set
        //Parameters: width
        //Return Values: none
        void setWidth(int w);
        //Pre-condition:have object that user need height for
        //Post-condition: user gets height of selected object
        //Parameters: none
        //Return Values: integer representing height
        int getHeight(){ return height; }
        //Pre-condition:have object that user need width for
        //Post-condition: user gets width of selected object
        //Parameters: none
        //Return Values: integer representing width
        int getWidth() { return width; }
        //Pre-condition:buttons are present
        //Post-condition: button is activated
        //Parameters: position of button
        //Return Values: true if button was clicked on, false if not
        bool clickedOn(Position p);
        //Pre-condition:none
        //Post-condition: none
        //Parameters: none
        //Return Values: none
        virtual ~Button();
    protected:
    private:
        Position pos;  //This is the top left corner of the button
        int width;  //in pixels
        int height; //also pixels
};

#endif // BUTTON_H
