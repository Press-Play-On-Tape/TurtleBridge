#include "Player.h"

#include "../utils/Physics.h"
#include "../utils/Enums.h"

#define NUM_OF_ELEMENTS 5

const int8_t PROGMEM positionData[] = { 
  14, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown),
  16, -2, static_cast<int8_t>(Player_Positions::Jumping_Left_01),
  17, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_02),
  18, -3, static_cast<int8_t>(Player_Positions::Jumping_Right_01),
  19, -2, static_cast<int8_t>(Player_Positions::Jumping_Right_02),
  20, 0, static_cast<int8_t>(Player_Positions::Jumping_Left_02),
};


Player::Player() { 

}

int8_t Player::getDisplayX() {

  return pgm_read_byte(&positionData[this->position * 3]);

}

int8_t Player::getDisplayY() {

  return pgm_read_byte(&positionData[(this->position * 3) + 1]);

}

uint8_t Player::getPosition() {

  return this->position;

}

uint8_t Player::getImageIndex() {

Serial.println(pgm_read_byte(&positionData[this->position * 3] + 2));
  return pgm_read_byte(&positionData[this->position * 3] + 2);

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

  return this->position < 6;

}

void Player::moveLeft() {

  this->position--;

}

void Player::moveRight() {

  this->position++;

}
