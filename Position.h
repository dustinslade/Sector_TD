#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        //Pre-condition:none
        //Post-condition: none
        //Parameters: none
        //Return Values: none
        Position();
        //Pre-condition:none
        //Post-condition: a new postion is created
        //Parameters: integer x and y
        //Return Values: none
        Position(int x, int y);
        //Pre-condition:none
        //Post-condition: none
        //Parameters: none
        //Return Values: none
        virtual ~Position();
        //Pre-condition:something needs a position
        //Post-condition: position is set
        //Parameters: integer x and y
        //Return Values: none
        void setPosition(int x, int y);
        //Pre-condition:have object that user need X for
        //Post-condition: user gets x of selected object
        //Parameters: none
        //Return Values: integer representing X
        int getX();
        //Pre-condition:have object that user need y for
        //Post-condition: user gets Y of selected object
        //Parameters: none
        //Return Values: integer representing Y
        int getY();
    protected:
    private:
        int X; //This is in pixels
        int Y; //Also in pixels
};

#endif // POSITION_H
