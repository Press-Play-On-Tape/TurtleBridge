#include "PlayGameState.h"

#include "../utils/Arduboy2Ext.h"
#include "../utils/Physics.h"
#include "../images/Images.h"
#include "../sounds/Sounds.h"


const uint8_t PROGMEM init_turtles[25] = { 
  11, 29, static_cast<uint8_t>(Direction::Left), static_cast<uint8_t>(TurtleMode::LookingDown), 0,
  32, 29, static_cast<uint8_t>(Direction::Left), static_cast<uint8_t>(TurtleMode::LookingDown), 20,
  53, 29, static_cast<uint8_t>(Direction::Left), static_cast<uint8_t>(TurtleMode::LookingDown), 40,
  74, 29, static_cast<uint8_t>(Direction::Right), static_cast<uint8_t>(TurtleMode::LookingDown), 60,
  95, 29, static_cast<uint8_t>(Direction::Right), static_cast<uint8_t>(TurtleMode::LookingDown), 80,
};

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

  for (uint8_t x = 0; x < 5; x++) {
  
    this->turtles[x].setX(pgm_read_byte(&init_turtles[(x * 5)]));
    this->turtles[x].setY(pgm_read_byte(&init_turtles[(x * 5) + 1]));
    this->turtles[x].setDirection(static_cast<Direction>(pgm_read_byte(&init_turtles[(x * 5) + 2])));
    this->turtles[x].setMode(static_cast<TurtleMode>(pgm_read_byte(&init_turtles[(x * 5) + 3])));
    this->turtles[x].setBobUpDown(pgm_read_byte(&init_turtles[(x * 5) + 4]));

  }


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

      if (fishIndex != FISH_NONE) {

        auto &fish = this->fishes[fishIndex];
        fish.setEnabled(true);
        fish.setDelay(random(20, 40));

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

  for (uint8_t x = 0; x < TURTLES_COUNT; x++) {
  
    auto &fish = this->fishes[x];
    auto &turtle = this->turtles[x];

    fish.updatePositionIndex();

    if (fish.isEdible()) {
      turtle.setMode(TurtleMode::Diving);
    }

    turtle.updateMode();

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

  for (uint8_t x = 0; x < TURTLES_COUNT; x++) {
  
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



  // Render Fishes ..

  for (auto &fish : this->fishes) {

    if (fish.getEnabled()) {
      SpritesB::drawExternalMask(fish.getDisplayX(), fish.getDisplayY(), Images::Fish, Images::Fish_Mask, fish.getImageIndex(), fish.getImageIndex());
    }

  }


  // Render turtles ..

  for (auto &turtle : this->turtles) {

    SpritesB::drawExternalMask(turtle.getDisplayX(), turtle.getDisplayY(), Images::Turtle, Images::Turtle_Mask, turtle.getImageIndex(), turtle.getImageIndex());

  }


  // Render score ..

  BaseState::renderScore(machine, false, 0);


  BaseState::renderGameOverOrPause(machine);
  arduboy.display(true);

}
