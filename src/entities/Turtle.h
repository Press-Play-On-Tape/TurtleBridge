#pragma once

#include "../Utils/Arduboy2Ext.h"
#include "../Utils/Enums.h"

class Turtle {

  public:

    Turtle();


    // Properties ..

    uint8_t getX();
    uint8_t getY();
    TurtleMode getMode();
    Direction getDirection();

    void setX(uint8_t x);
    void setY(uint8_t y);
    void setMode(TurtleMode mode);
    void setDirection(Direction direction);
    void setBobUpDown(uint8_t bobUpDown);


    // Methods ..

    uint8_t getImageIndex();
    uint8_t getDisplayX();
    uint8_t getDisplayY();
    void updateMode();

  protected:

    uint8_t x;
    uint8_t y;
    uint8_t returnToLookingDown;
    uint8_t bobUpDown;
    TurtleMode mode = TurtleMode::LookingDown;
    Direction direction;

};

