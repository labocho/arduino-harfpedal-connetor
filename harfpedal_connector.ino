// https://github.com/FortySevenEffects/arduino_midi_library
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// ROLAND:
// 5V を TIP、D7 を RING、A0 を SLEEVE に
const int VOL_MIN = 540;
const int VOL_MAX = 840;

// KORG:
// 5V を TIP に、A0 を SLEEVE に
// const int VOL_MIN = 320;
// const int VOL_MAX = 970;

const int INTERVAL = 100;

int last_value = -1;

void setup() {
  pinMode(8, INPUT);
  MIDI.begin(1);
  MIDI.turnThruOff();
}

void loop() {
  long v = analogRead(0);
  // Serial.println(v);

  if (v < VOL_MIN) v = VOL_MIN;
  if (VOL_MAX < v) v = VOL_MAX;
  v = (v - VOL_MIN) * 127 / (VOL_MAX - VOL_MIN);

  if (v != last_value) {
    // Serial.println(v);
    MIDI.sendControlChange(64, v, 1);
    last_value = v;
  }

  delay(INTERVAL);
}
