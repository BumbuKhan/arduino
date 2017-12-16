int ledpin = 11;
int inpin = 7;
int val;

void setup () {
  pinMode(inpin, INPUT);
  pinMode(ledpin, OUTPUT);
}

void loop () {
  val = digitalRead(inpin);

  if (val == LOW) {
    digitalWrite(ledpin, LOW);
  } else {
    digitalWrite(ledpin, HIGH);
  }
}

