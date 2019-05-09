#include "Player.h"

#include "../utils/Physics.h"
#include "../utils/Enums.h"

#define NUM_OF_ELEMENTS 5

const uint8_t PROGMEM positionX[] = { 
  0, 3, 4, 5,
};

const uint8_t PROGMEM positionY[] = { 
  0, 3, 4, 5,
};

Player::Player() { 

}

uint8_t Player::getDisplayX() {
Serial.print(this->position);
Serial.print(" ");
Serial.print(pgm_read_byte(&positionX[this->position]));
Serial.print(" ");
Serial.println(pgm_read_byte(&positionY[this->position]));
  return pgm_read_byte(&positionX[this->position]);

}

uint8_t Player::getDisplayY() {

  return pgm_read_byte(&positionY[this->position]);

}

uint8_t Player::getPosition() {

  return this->position;

}

bool Player::isHoldingPackage() {

  return this->holdingPackage;

}

void Player::setPosition(uint8_t position) {

  this->position = position;

}

void Player::setHoldingPackage(bool value) {

  this->holdingPackage = value;

}


// Methods ..

bool Player::canMoveLeft() {

  return this->position > 0;

}

bool Player::canMoveRight() {

  return this->position < 4;

}

void Player::moveLeft() {

  this->position--;

}

void Player::moveRight() {

  this->position++;

}
