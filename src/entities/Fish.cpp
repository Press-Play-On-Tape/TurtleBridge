#include "Fish.h"

#include "../utils/Enums.h"

const uint8_t positionX[5][5] = { 
  { 0, 3, 6, 8, 9 },
  { 26, 28, 30, 31, 32 },
  { 51, 52, 53, 53, 53 },
  { 91, 89, 87, 86, 85 },
  { 119, 116, 113, 111, 109 },
};

const uint8_t positionY[5] = { 
  59, 56, 53, 50, 47
};


Fish::Fish() { 
}

bool Fish::getEnabled() {

  return this->enabled;

}

uint8_t Fish::getFishIndex() {

  return this->fishIndex;

}

uint8_t Fish::getImageIndex() {

  return this->imageIndex;

}

uint8_t Fish::getDelay() {

  return this->delayValue;

}

void Fish::setEnabled(bool enabled) {

  this->enabled = enabled;

  if (enabled) {
    this->counter = 120;
    this->imageIndex = 0;
    this->positionIndex = 0;
  }

}

void Fish::setFishIndex(uint8_t value) {

  this->fishIndex = value;

}

void Fish::setImageIndex(uint8_t value) {

  this->imageIndex = value;

}

void Fish::setDelay(uint8_t value) {

  this->delayValue = value;
  this->delayValueInit = value;

}


// Methods ..

uint8_t Fish::getDisplayX() {

  return positionX[this->fishIndex][this->positionIndex];

}

uint8_t Fish::getDisplayY() {

  return positionY[this->positionIndex];

}

void Fish::updateImageIndex() {

  this->imageIndex = (this->imageIndex == 1 ? 0 : 1);

}


void Fish::updatePositionIndex() {

  if (this->delayValue > 0) this->delayValue--;

  if (this->delayValue == 0) {

    this->delayValue = this->delayValueInit;
    this->positionIndex++;

    if (this->positionIndex == 5) {

      this->enabled = false;

    }

  }

}