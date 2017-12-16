int redled = 10;
int yellowled = 7;
int greenled = 4; // I don't have green one :(

void setup () {
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
}

void loop () {
  digitalWrite(greenled, HIGH); // turn on green LED
  delay(5000); // keep it for 5 sec

  digitalWrite(greenled, LOW); // turning off green LED

  // blinks 3 times
  for (int i = 0; i < 3; i++) {
    delay(500); // waiting 0.5 sec
    digitalWrite(yellowled, HIGH);

    delay(500);
    digitalWrite(yellowled, LOW);
  }

  delay(500);
  digitalWrite(redled, HIGH);
  delay(5000);
  digitalWrite(redled, LOW);
}

