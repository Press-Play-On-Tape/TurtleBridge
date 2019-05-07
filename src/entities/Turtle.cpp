#include "Turtle.h"

#include "../utils/Enums.h"


Turtle::Turtle() { 
}

uint8_t Turtle::getX() {

  return this->x;

}

uint8_t Turtle::getY() {

  return this->y;

}

TurtleMode Turtle::getMode() {

  return this->mode;

}

Direction Turtle::getDirection() {

  return this->direction;

}

void Turtle::setX(uint8_t x) {

  this->x = x;

}

void Turtle::setY(uint8_t y) {

  this->y = y;

}

void Turtle::setMode(TurtleMode mode) {

  this->mode = mode;

  switch (this->mode) {

    case TurtleMode::LookingUp:
      this->returnToLookingDown = RETURN_TO_LOOKING_DOWN_FROM_UP;
      break;

    case TurtleMode::LookingDown:
      this->returnToLookingDown = 0;
      break;

    case TurtleMode::Diving:
      this->returnToLookingDown = RETURN_TO_LOOKING_DOWN_FROM_DIVING;
      break;
      
  }

}

void Turtle::setDirection(Direction direction) {

  this->direction = direction;

}

void Turtle::setBobUpDown(uint8_t bobUpDown) {

  this->bobUpDown = bobUpDown;

}


// Methods ..

uint8_t Turtle::getImageIndex() {

  return static_cast<uint8_t>(this->mode) + (this->direction == Direction::Right ? 3 : 0);

}

uint8_t Turtle::getDisplayX() {

  return this->x;

}

uint8_t Turtle::getDisplayY() {

  switch (this->mode) {

    case TurtleMode::LookingUp:
      return this->y - 4;

    case TurtleMode::LookingDown:
      return this->y + (this->bobUpDown < 50 ? -1 : 0);

    case TurtleMode::Diving:

      switch (this->returnToLookingDown) {

        case 0 ... 3:
          return this->y + 1;
        case 4 ... 6:
          return this->y + 2;
        case 7 ... 12:
          return this->y + 3;
        case 13 ... 15:
          return this->y + 2;
        case 16 ... 18:
          return this->y + 1;
        
        default : return this->y;

      }

    default:
      return this->y;

  }

}

void Turtle::updateMode() {

  if (this->bobUpDown > 0) {
    this->bobUpDown--;
  }
  else {
    this->bobUpDown = 100;
  }


  if (this->returnToLookingDown > 0) {
    this->returnToLookingDown--;
  }
  else {
    this->mode = TurtleMode::LookingDown;
  }

}