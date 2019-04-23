#pragma once

#include "../utils/GameContext.h"
#include "../utils/GameState.h"
#include "../utils/Enums.h"
#include "../entities/Entities.h"
#include "BaseState.h"
#include "../arduboyTones/ArduboyTonesExt.h"

class PlayGameState : public BaseState { //GameState<GameContext, GameStateType> {

  private:
 
    Player player;

    uint8_t counter = 0;
    uint8_t ledCountdown;

  public:
    void activate(StateMachine & machine) override;
    void update(StateMachine & machine) override;
    void render(StateMachine & machine) override;

};