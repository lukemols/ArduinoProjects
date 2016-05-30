#include "pitches.h"

const int threshold = 10;    // minimum reading of the sensors that generates a note

int times = 24;

// notes to play, corresponding to the 3 sensors:
int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C3
};

void setup() {

}

void loop() {
      times--;
      if(times <= 0)
        exit(0);
      tone(8, notes[times % 3], 20);
      delay(500);
  
}
