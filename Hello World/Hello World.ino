int val;
int ledpin = 13;

void setup () {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop () {
  val = Serial.read();

  if (val == 'R') {
    digitalWrite(ledpin, HIGH);
    delay(2000);
    digitalWrite(ledpin, LOW);

    Serial.println("HELLO WORLD");
  }
}

