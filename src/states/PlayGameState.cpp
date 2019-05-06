#include "PlayGameState.h"

#include "../utils/Arduboy2Ext.h"
#include "../utils/Physics.h"
#include "../images/Images.h"
#include "../sounds/Sounds.h"


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void PlayGameState::activate(StateMachine & machine) {

  auto & gameStats = machine.getContext().gameStats;
  auto & arduboy = machine.getContext().arduboy;
  auto & sound = machine.getContext().sound;  

  gameStats.gameOver = false;
  this->counter = 0;
  

  // Initialise turtles ..

  this->turtles[0].setX(11);
  this->turtles[0].setY(29);
  this->turtles[0].setDirection(Direction::Left);
  this->turtles[0].setMode(TurtleMode::LookingDown);

  this->turtles[1].setX(32);
  this->turtles[1].setY(29);
  this->turtles[1].setDirection(Direction::Left);
  this->turtles[1].setMode(TurtleMode::LookingDown);

  this->turtles[2].setX(53);
  this->turtles[2].setY(29);
  this->turtles[2].setDirection(Direction::Left);
  this->turtles[2].setMode(TurtleMode::LookingDown);

  this->turtles[3].setX(74);
  this->turtles[3].setY(29);
  this->turtles[3].setDirection(Direction::Right);
  this->turtles[3].setMode(TurtleMode::LookingDown);

  this->turtles[4].setX(95);
  this->turtles[4].setY(29);
  this->turtles[4].setDirection(Direction::Right);
  this->turtles[4].setMode(TurtleMode::LookingDown);


  // Initialise fishes ..

  for (uint8_t x = 0; x < 5; x++) {

    auto &fish = this->fishes[x];
    fish.setFishIndex(x);
    fish.setEnabled(false);

  }



  this->player.setX(PLAYER_MIN_X_POS);

  this->launchFishCounter = random(120, 180);

  BaseState::setPaused(false);
  sound.setOutputEnabled(arduboy.audio.enabled);

}
  

// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void PlayGameState::update(StateMachine & machine) { 

	auto & arduboy = machine.getContext().arduboy;
  auto & gameStats = machine.getContext().gameStats;
  auto & sound = machine.getContext().sound;  
	auto pressed = arduboy.pressedButtons();


  if (!BaseState::getPaused()) {

    if (this->launchFishCounter > 0) launchFishCounter--;


    // Launch a fish?

    if (this->launchFishCounter == 0) {

      this->launchFishCounter = random(120, 180);
      uint8_t fishIndex = getDisabledFish();
Serial.print("fish: ");
Serial.println(fishIndex);
      if (fishIndex != FISH_NONE) {

        auto &fish = this->fishes[fishIndex];
        fish.setEnabled(true);
        fish.setDelay(random(20, 40));

      }

        for (uint8_t x = 0; x < 5; x++) {

          auto &fish = this->fishes[x];
          Serial.print("Fish No: ");
          Serial.print(fish.getFishIndex());
          Serial.print(", enabled");
          Serial.println(fish.getEnabled());

        }

    }


    // Update player position ..

    if ((pressed & LEFT_BUTTON) && this->player.canMoveLeft())      { this->player.setDirection(Direction::Left); }
    if ((pressed & RIGHT_BUTTON) && this->player.canMoveRight())    { this->player.setDirection(Direction::Right); }
    
    if (arduboy.everyXFrames(2)) {

      player.move();

    }


    // if (gameStats.misses >= 3 && allVictimsDisabled()) {

    //   gameStats.gameOver = true;

    // }

  }


  // Update fish image indexes ..

  if (arduboy.everyXFrames(16)) {

    for (auto &fish : this->fishes) {

      fish.updateImageIndex();

    }

  }



  // Update fish locations ..

  for (auto &fish : this->fishes) {

    fish.updatePositionIndex();

  }


//  machine.changeState(GameStateType::GameIntroScreen, GameStateType::None);


  // Handle other buttons ..

  BaseState::handleCommonButtons(machine);

}


// ----------------------------------------------------------------------------
//  Get a random fish that is disabled .. 
//
uint8_t PlayGameState::getDisabledFish() {
  
  uint8_t fishes[5];
  uint8_t fishCount = 0;

  for (uint8_t x = 0; x < 5; x++) {
  
    auto fish = this->fishes[x];

    if (!fish.getEnabled()) {
      fishes[fishCount] = x;
      fishCount++;
    }

  }

  if (fishCount > 0) {
    return fishes[random(0, fishCount)];
  }
  else {
    return FISH_NONE;
  }

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void PlayGameState::render(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
  auto & gameStats = machine.getContext().gameStats;

  BaseState::renderCommonScenery(machine);


  // Render turtles ..

  for (auto &turtle : this->turtles) {

    SpritesB::drawExternalMask(turtle.getDisplayX(), turtle.getDisplayY(), Images::Turtle, Images::Turtle_Mask, turtle.getImageIndex(), turtle.getImageIndex());

  }


  // Render Fishes ..

  Serial.println("--------------------------------");
  for (auto &fish : this->fishes) {

    if (fish.getEnabled()) {
      Serial.print("render ");
      Serial.print(fish.getFishIndex());
      Serial.print(" at ");
      Serial.print(fish.getDisplayX());
      Serial.print(", ");
      Serial.println(fish.getDisplayY());
      SpritesB::drawExternalMask(fish.getDisplayX(), fish.getDisplayY(), Images::Fish, Images::Fish_Mask, fish.getImageIndex(), fish.getImageIndex());
    }

  }


  // Render score ..

  BaseState::renderScore(machine, false, 0);


  BaseState::renderGameOverOrPause(machine);
  arduboy.display(true);

}
