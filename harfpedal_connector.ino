void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
}

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

void loop() {
  // int d = 0;
  // d = digitalRead(8);
  // Serial.println(d);

  int a = 0;
  a = analogRead(0);
  //  Serial.println(a);
  long v = a;
  if (v < VOL_MIN) v = VOL_MIN;
  if (VOL_MAX < v) v = VOL_MAX;
  v = (v - VOL_MIN) * 127 / (VOL_MAX - VOL_MIN);
  if (v != last_value) {
    Serial.println(v);
    last_value = v;
  }

  delay(INTERVAL);
}
