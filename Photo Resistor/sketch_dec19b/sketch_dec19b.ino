int potpin = 0;
int ledpin = 11;
int val = 0;

void setup () {
//  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 255);
  Serial.println(val);

  analogWrite(ledpin, val);
  delay(10);
}

