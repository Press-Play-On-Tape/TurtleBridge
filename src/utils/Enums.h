#pragma once

#include <stdint.h>
#include "Utils.h"

//#define DEBUG
//#define DEBUG_PLAYGAME


// - Overall Settings -----------------

// #define TARGET_SCORE_BASE 10  
// #define TARGET_SCORE_INC_PER_LEVEL 5 
#define TARGET_SCORE_BASE 45 
#define TARGET_SCORE_INC_PER_LEVEL 5 
#define LED_BRIGHTNESS 32

#define TURTLES_COUNT 5
#define FISH_NONE 255 
#define RETURN_TO_LOOKING_DOWN_FROM_UP 20
#define RETURN_TO_LOOKING_DOWN_FROM_DIVING 18




// - Fire Game ------------------------

#define PLAYER_MIN_X_POS 18
#define PLAYER_MID_X_POS 39
#define PLAYER_MAX_X_POS 60
#define PLAYER_WIDTH_HALF 20

#define PLAYER_Y_POS 42
#define PLAYER_STEP_INC 6 


// - High Scores ---------------------

#define NAME_LENGTH 3
#define NAME_LENGTH_PLUS_TERM (NAME_LENGTH + 1)

#define HS_NAME_LEFT 36
#define HS_SCORE_LEFT 69
#define HS_CHAR_TOP 22
#define HS_CHAR_V_SPACING 9
#define HS_PRESS_A_DELAY 100

#define NO_WINNER 255

constexpr size_t eepromStart = 120;
constexpr size_t eepromStart_C1 = eepromStart + 1;
constexpr size_t eepromStart_C2 = eepromStart + 2;
constexpr size_t eepromSaveEntriesCount = 3;
constexpr size_t eepromSaveEntriesStart = eepromStart + 3;

#define FLASH_FRAME_COUNT_2 56

enum class GameStateType : uint8_t {
  None,
	SplashScreen,
	TitleScreen,
  GameIntroScreen,
  PlayGameScreen,
  HighScoreScreen
};

enum class Direction : uint8_t {
  Up,     // 00
  Down,   // 01
  Left,   // 02
  Right,  // 03
  None
};

enum class TurtleMode : uint8_t {
  LookingUp,     // 00
  LookingDown,   // 01
  Diving,        // 02
  None
};

struct GameStats {

  public: 
    
    GameStats() { };

    uint16_t score = 0;
    uint8_t misses = 0;
    int16_t health = 0;
    uint16_t level = 0;
    uint8_t xPosition = 0;  // Player x position between sequences ..
    uint16_t targetScore = 0;
    bool gameOver = false;

    void resetGame() {

      this->level = 0;
      this->health = 0;
      this->misses = 0;
      this->score = 0; 
      this->gameOver = false;

    }

};