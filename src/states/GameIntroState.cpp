#include "GameIntroState.h"
#include "../utils/Arduboy2Ext.h"
#include "../images/Images.h"


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void GameIntroState::activate(StateMachine & machine) {
  	
  auto & gameStats = machine.getContext().gameStats;

  this->counter = 0;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void GameIntroState::update(StateMachine & machine) { 

	auto & arduboy = machine.getContext().arduboy;
	auto justPressed = arduboy.justPressedButtons();

  if (arduboy.everyXFrames(2)) {

    switch (counter) {

      case 0 ... 59:
        break;

      case 60 ... 75:
        break;

      case 76 ... 90:
        break;

      case 91 ... 161:
        break;

      case 162 ... 190:
        break;

      case 191:
        machine.changeState(machine.getContext().nextState, GameStateType::None); 
        break;

    }

    this->counter++;

  }


  // Skip intro ..
  
  if (justPressed & A_BUTTON) machine.changeState(machine.getContext().nextState, GameStateType::None); 
  
}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void GameIntroState::render(StateMachine & machine) {

	auto & arduboy = machine.getContext().arduboy;
	auto & gameStats = machine.getContext().gameStats;

  BaseState::renderCommonScenery(machine);
  
  arduboy.display(true);

}
