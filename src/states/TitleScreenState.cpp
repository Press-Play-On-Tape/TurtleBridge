#include "TitleScreenState.h"
#include "../images/Images.h"
#include "../utils/EEPROM_Utils.h"
#include "../sounds/Sounds.h"

constexpr const static uint8_t PRESS_A_DELAY = 200;
constexpr const static uint8_t UPLOAD_DELAY = 16;


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void TitleScreenState::activate(StateMachine & machine) {

  auto & gameStats = machine.getContext().gameStats;
  auto & arduboy = machine.getContext().arduboy;
  auto & sound = machine.getContext().sound;  
	
  gameStats.resetGame();
  sound.setOutputEnabled(arduboy.audio.enabled);

  BaseState::initWater();
  //sound.tones(Sounds::Score);

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void TitleScreenState::update(StateMachine & machine) {

  auto & arduboy = machine.getContext().arduboy;
  auto justPressed = arduboy.justPressedButtons();
  auto pressed = arduboy.pressedButtons();


	// Restart ?

	if (pressed & DOWN_BUTTON) {

		if (this->restart < UPLOAD_DELAY) {
			this->restart++;
		}
		else {
			arduboy.exitToBootloader();
		}

	}
	else {
		this->restart = 0;
	}


	// Handle other input ..

	if (justPressed & A_BUTTON) {
		machine.changeState(GameStateType::PlayGameScreen, GameStateType::None); 
	}

	if (justPressed & B_BUTTON) {
		machine.changeState(GameStateType::HighScoreScreen, GameStateType::None); 
	}


  BaseState::updateWater(machine);


  // Update 'Press A' counter / delay ..

  if (this->pressACounter < PRESS_A_DELAY) this->pressACounter++;

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void TitleScreenState::render(StateMachine & machine) {

  auto & arduboy = machine.getContext().arduboy;

  BaseState::renderCommonScenery(machine);
  BaseState::renderWater();

  Sprites::drawExternalMask(27, 9, Images::Title, Images::Title_Mask, 0, 0);

  if (this->pressACounter == PRESS_A_DELAY) {

    Sprites::drawExternalMask(26, 41, Images::PressAandB, Images::PressAandB_Mask, 0, 0);

  }

  arduboy.displayWithBackground();

}
