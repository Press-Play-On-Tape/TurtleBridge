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



  this->player.setPosition(0);

  this->launchFishCounter = random(120, 180);
  this->stickHeadUpCounter = random(200, 240);

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
	auto justPressed = arduboy.justPressedButtons();


  if (!BaseState::getPaused()) {

    if (this->launchFishCounter > 0) launchFishCounter--;
    if (this->stickHeadUpCounter > 0) stickHeadUpCounter--;


    // Launch a fish?

    if (this->launchFishCounter == 0) {

      this->launchFishCounter = random(120, 180);
      uint8_t fishIndex = getDisabledFish(machine);

      if (fishIndex != FISH_NONE) {

        auto &fish = this->fishes[fishIndex];
        fish.setEnabled(true);
        fish.setDelay(random(20, 40));

      }

    }


    // Stick turtles head up?

    if (this->stickHeadUpCounter == 0) {

      this->stickHeadUpCounter = random(200, 240);
      uint8_t fishIndex = getDisabledFish(machine);

      if (fishIndex != FISH_NONE) {

        auto &turtle = this->turtles[fishIndex];
        turtle.setMode(TurtleMode::LookingUp);

      }

    }

    // Update player position ..

    // if ((justPressed & LEFT_BUTTON) && this->player.canMoveLeft())      { this->player.moveLeft(); }
    // if ((justPressed & RIGHT_BUTTON) && this->player.canMoveRight())    { this->player.moveRight(); }
      if (arduboy.everyXFrames(2)) {
    if ((pressed & LEFT_BUTTON) && this->player.canMoveLeft())      { 
//      this->player.moveLeft(); 
      this->player.setDirection(Direction::Left);
      }
    if ((pressed & RIGHT_BUTTON) && this->player.canMoveRight())    { 
      this->player.setDirection(Direction::Right);
    //  this->player.moveRight(); 
    }
    
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
// //sjh
//     uint8_t stickHeadUpCounter = 0;

  }


//  machine.changeState(GameStateType::GameIntroScreen, GameStateType::None);


  // Handle other buttons ..

  BaseState::handleCommonButtons(machine);

}


// ----------------------------------------------------------------------------
//  Get a random fish that is disabled .. 
//
uint8_t PlayGameState::getDisabledFish(StateMachine & machine) {

  auto & gameStats = machine.getContext().gameStats;
  
  uint8_t fishes[5];
  uint8_t fishCount = 0;

  for (uint8_t x = 0; x < TURTLES_COUNT; x++) {
  
    auto fish = this->fishes[x];

    if (!fish.getEnabled() && (gameStats.mode == GameMode::Hard || (gameStats.mode == GameMode::Easy && x != 2))) {
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

  for (uint8_t x = 0; x < TURTLES_COUNT; x++) {

    auto fish = this->fishes[x];

    if (fish.getEnabled()) {
      SpritesB::drawExternalMask(fish.getDisplayX(), fish.getDisplayY(), Images::Fish, Images::Fish_Mask, fish.getImageIndex() + (x < 3 ? 2 : 0), fish.getImageIndex() + (x < 3 ? 2 : 0));
    }

  }


  // Render turtles ..
  // SpritesB::drawExternalMask(0, 34, Images::Water_01, Images::Water_01_Mask, 0, 0);
  // SpritesB::drawExternalMask(12, 33 - (this->turtles[0].getBobUp() ? 1 : 0), Images::Water_02, Images::Water_02_Mask, 0, 0);
  // SpritesB::drawExternalMask(33, 33 - (this->turtles[1].getBobUp() ? 1 : 0), Images::Water_02, Images::Water_02_Mask, 0, 0);
  // SpritesB::drawExternalMask(54, 33 - (this->turtles[2].getBobUp() ? 1 : 0), Images::Water_02, Images::Water_02_Mask, 0, 0);
  // SpritesB::drawExternalMask(75, 33 - (this->turtles[3].getBobUp() ? 1 : 0), Images::Water_02, Images::Water_02_Mask, 0, 0);
  // SpritesB::drawExternalMask(96, 33 - (this->turtles[4].getBobUp() ? 1 : 0), Images::Water_02, Images::Water_02_Mask, 0, 0);
  // SpritesB::drawExternalMask(117, 34, Images::Water_03, Images::Water_03_Mask, 0, 0);

  for (auto &turtle : this->turtles) {
  
    if (turtle.getType() == TurtleType::Black) {
      SpritesB::drawExternalMask(turtle.getDisplayX(), turtle.getDisplayY(), Images::Turtle_03, Images::Turtle_02_03_Mask, turtle.getImageIndex(), turtle.getImageIndex());
    }
    else {
      SpritesB::drawExternalMask(turtle.getDisplayX(), turtle.getDisplayY(), Images::Turtle_01, Images::Turtle_01_Mask, turtle.getImageIndex(), turtle.getImageIndex());
    }

  }


  // Render score ..

  BaseState::renderScore(machine, false, 0);


  SpritesB::drawExternalMask(110, 3, Images::Recipient, Images::Recipient_Mask, 0, 0);


  // Render player ..

  uint8_t turtleIndex = this->player.getTurtleIndex();
  Turtle &turtle = this->turtles[turtleIndex != TURTLE_NONE ? turtleIndex : 0];

  SpritesB::drawExternalMask(this->player.getDisplayX(), this->player.getDisplayY(turtleIndex != TURTLE_NONE ? (turtle.getBobUp() ? 1 : 0) : 0), Images::Arduboy, Images::Arduboy_Mask, this->player.getImageIndex(), this->player.getImageIndex());

  SpritesB::drawExternalMask(0, 34, Images::Water_01, Images::Water_01_Mask, 0, 0);
  SpritesB::drawExternalMask(12, 33 - (this->turtles[0].getBobUp() ? 1 : 0), Images::Water_02, Images::Water_02_Mask, 0, 0);
  SpritesB::drawExternalMask(33, 33 - (this->turtles[1].getBobUp() ? 1 : 0), Images::Water_02, Images::Water_02_Mask, 0, 0);
  SpritesB::drawExternalMask(54, 33 - (this->turtles[2].getBobUp() ? 1 : 0), Images::Water_02, Images::Water_02_Mask, 0, 0);
  SpritesB::drawExternalMask(75, 33 - (this->turtles[3].getBobUp() ? 1 : 0), Images::Water_02, Images::Water_02_Mask, 0, 0);
  SpritesB::drawExternalMask(96, 33 - (this->turtles[4].getBobUp() ? 1 : 0), Images::Water_02, Images::Water_02_Mask, 0, 0);
  SpritesB::drawExternalMask(117, 34, Images::Water_03, Images::Water_03_Mask, 0, 0);


  BaseState::renderGameOverOrPause(machine);
  arduboy.display(true);

}
