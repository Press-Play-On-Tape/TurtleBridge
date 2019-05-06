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


    // Methods ..

    uint8_t getImageIndex();
    uint8_t getDisplayX();
    uint8_t getDisplayY();

  protected:

    uint8_t x;
    uint8_t y;
    TurtleMode mode = TurtleMode::LookingDown;
    Direction direction;

};

