#include <Arduino.h>
#include <Tone32.h>
#include "Pitches.h"
#include "main.h"

#define BUZZER_PIN 33
#define BUZZER_CHANNEL 0

void setup() {
  Serial.begin( 115200 );
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  playmusic();
  // no need to repeat the melody.
  delay( 10 * 1000 );
}

void playmusic() {
  // notes in the melody:
  int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
  };

  int thisNote = 0;
  do  {
      int noteDuration = 2000 / noteDurations[thisNote];
      int note = melody[thisNote];

      tone(BUZZER_PIN, note, noteDuration, BUZZER_CHANNEL );

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:

      int pauseBetweenNotes = noteDuration * 1.30;

      delay(pauseBetweenNotes);

      // stop the tone playing:

      noTone(BUZZER_PIN, BUZZER_CHANNEL);
  } while (thisNote++ < 8);
}
