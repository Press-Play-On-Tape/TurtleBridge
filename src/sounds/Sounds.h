#pragma once

namespace Sounds {

  const uint16_t PackageDelivered[] PROGMEM = { 220,50, 440,50, 880,50, TONES_END };

  const uint16_t PackagePickedUp[] PROGMEM = { 440,50, 880,50, TONES_END };

  const uint16_t PackageNotDelivered[] PROGMEM = { 440,50, 180,50, TONES_END };

  const uint16_t Turtle[] PROGMEM = { 30, 50, 50, 50, TONES_END };

  const uint16_t Drowning[] PROGMEM = { 440,50, 420,50, 400,50, 380,50, 360,50, 340,50, 320,50, 300,50, 
                                        280,50, 260,50, 240,50, 220,50, 200,50, 180,50, 160,50, 140,50,
                                        120,50, 100,50, 80,50, NOTE_REST, 10, 80,50, NOTE_REST, 20, 80,50, 
                                        NOTE_REST, 40, 80,50, NOTE_REST, 60, 80,50, NOTE_REST, 90,
                                        NOTE_REST, 130, 80,50, NOTE_REST, 180, 80,50, NOTE_REST, 240,
                                        NOTE_REST, 310, 80,50, NOTE_REST, 390, 80,50, 
                                        TONES_END };

  const uint16_t Score[] PROGMEM = {
    NOTE_REST,454, NOTE_B5,241, NOTE_REST,440, NOTE_C6,241, NOTE_REST,440, NOTE_A5,241, NOTE_REST,440, NOTE_A5,241,
    NOTE_REST,213, NOTE_B5,241, NOTE_REST,213, NOTE_B5,582, NOTE_REST,99, NOTE_C6,241, NOTE_REST,440, NOTE_A5,241,
    NOTE_REST,213, NOTE_F5,454, NOTE_REST,25, NOTE_F5,227, NOTE_REST,25, NOTE_E5,227, NOTE_REST,125, NOTE_D5,1155, 
    NOTE_REST,1000, 
    NOTE_REST,454, NOTE_B5,241, NOTE_REST,440, NOTE_C6,241, NOTE_REST,440, NOTE_A5,241, NOTE_REST,440, NOTE_A5,241,
    NOTE_REST,213, NOTE_B5,241, NOTE_REST,213, NOTE_B5,582, NOTE_REST,99, NOTE_C6,241, NOTE_REST,440, NOTE_A5,241,
    NOTE_REST,213, NOTE_F5,454, NOTE_REST,25, NOTE_F5,227, NOTE_REST,25, NOTE_E5,227, NOTE_REST,125, NOTE_D5,1155, 
    NOTE_REST,1000, 
    TONES_END
  };

}