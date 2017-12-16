int BASE = 3; // the I/O pin for the first LED
int NUM = 5; // amount of LEDs

void setup () {
  for (int i = BASE; i < BASE + NUM; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop () {
  for (int i = BASE; i < BASE + NUM; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW); // turning LEDs one by one
  }
}

