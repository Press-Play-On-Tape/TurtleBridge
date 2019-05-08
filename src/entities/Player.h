#pragma once

#include "../Utils/Arduboy2Ext.h"
#include "../Utils/Enums.h"

class Player {

  public:

    Player();
     
    uint8_t getDisplayX();
    uint8_t getDisplayY();
    uint8_t getPosition();
    bool isHoldingPackage();
    
    void setPosition(uint8_t position);
    void setHoldingPackage(bool value);


    // Methods ..

    bool canMoveLeft();
    bool canMoveRight();
    void moveLeft();
    void moveRight();

  protected:

    uint8_t position;
    bool holdingPackage;

};

