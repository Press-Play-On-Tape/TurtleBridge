#include "Player.h"

#include "../utils/Physics.h"
#include "../utils/Enums.h"

#define NUM_OF_ELEMENTS 4

const int8_t PROGMEM positionData[340] = { 

  // 14, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 15, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 16, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 17, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 18, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 19, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 20, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 21, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 22, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 23, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 24, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 25, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 26, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 27, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 28, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 29, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 30, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 31, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 32, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 33, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 34, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 35, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,

  // 35, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 35, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 35, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 35, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 35, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 35, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 35, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,

  // 36, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 37, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 38, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 39, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 40, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 41, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 42, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 43, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 44, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 45, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 46, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 47, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 48, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 49, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 50, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 51, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 52, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 53, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 54, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 55, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 56, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 56, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,

  // 56, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 56, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 56, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 56, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 56, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 56, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 56, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,

  // 56, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 56, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 57, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 57, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 58, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 59, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 60, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 61, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 62, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 63, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 64, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 65, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 66, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 67, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 68, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 69, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 70, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 71, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 72, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 73, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 74, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 74, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,

  // 74, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 74, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 74, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 74, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 74, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,


  // 74, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 75, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 76, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 77, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 78, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 79, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 80, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 81, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 82, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 83, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 84, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 85, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 86, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 87, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 88, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 89, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 90, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 91, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 92, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  // 93, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 94, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  // 95, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,

  // 95, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 95, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 95, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 95, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 95, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 95, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,
  // 95, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 0,


  14, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 1,

  15, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  16, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  17, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  18, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  19, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  20, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  21, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  22, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  23, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  24, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  25, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  26, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  27, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  28, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  29, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  30, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  31, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  32, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  33, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  34, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  
  35, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 2,

  37, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  38, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  39, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  40, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  41, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  42, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  43, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  44, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  45, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  46, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  47, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  48, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  49, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  50, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  51, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  52, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  53, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  54, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  55, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  56, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,

  56, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 3,

  56, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  57, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  57, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  58, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  59, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  60, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  61, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  62, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  63, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  64, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  65, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  66, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  67, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  68, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  69, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  70, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  71, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  72, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  73, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  74, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,

  74, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 4,

  75, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  76, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  77, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  78, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  79, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  80, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  81, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  82, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  83, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  84, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  85, -10, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  86, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  87, -9, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  88, -8, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  89, -7, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  90, -5, static_cast<int8_t>(Player_Positions::Jumping_Left_02), 0,
  91, -3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  92, -1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  93, 1, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,
  94, 3, static_cast<int8_t>(Player_Positions::Jumping_Left_01), 0,

  95, 3, static_cast<int8_t>(Player_Positions::Standing_ArmsDown), 5,

};


Player::Player() { 

}

int8_t Player::getDisplayX() {

  return pgm_read_byte(&positionData[this->position * NUM_OF_ELEMENTS]);

}

int8_t Player::getDisplayY(uint8_t offset) {
Serial.print(">");
Serial.print(pgm_read_byte(&positionData[(this->position * NUM_OF_ELEMENTS) + 1]));
Serial.print("-");
Serial.print(offset);
Serial.print("=");
Serial.println(pgm_read_byte(&positionData[(this->position * NUM_OF_ELEMENTS) + 1]) - offset);
  return pgm_read_byte(&positionData[(this->position * NUM_OF_ELEMENTS) + 1]) - offset + 2;

}

uint8_t Player::getPosition() {

  return this->position;

}

Direction Player::getDirection() {

  return this->direction;

}

uint8_t Player::getImageIndex() {

  return pgm_read_byte(&positionData[this->position * NUM_OF_ELEMENTS] + 2) + (this->direction == Direction::Right ? 4 : 0);

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

void Player::setDirection(Direction direction) {

  this->direction = direction;

}


// Methods ..

bool Player::canMoveLeft() {

  return this->position > 0;

}

bool Player::canMoveRight() {

  return this->position < 114;

}

void Player::moveLeft() {

  this->position--;

}

void Player::moveRight() {

  this->position++;

}

void Player::move() {

  switch (this->direction) {

    case Direction::Left:
      this->position--;
      break;

    case Direction::Right:
      this->position++;
      break;

    default:
      break;

  }

  if (pgm_read_byte(&positionData[this->position * NUM_OF_ELEMENTS] + 3) != 0) {

    this->direction = Direction::None;

  }

}

uint8_t Player::getTurtleIndex() {

  uint8_t turtleIndex = TURTLE_NONE;
  uint8_t posData = pgm_read_byte(&positionData[this->position * NUM_OF_ELEMENTS] + 3);

Serial.println(posData);


  if (posData != 0) {

    turtleIndex = posData - 1;

  }

  return turtleIndex;

}