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

}

void Turtle::setDirection(Direction direction) {

  this->direction = direction;

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
      return this->y;

    case TurtleMode::Diving:
      return this->y;

    default:
      return this->y;

  }

}