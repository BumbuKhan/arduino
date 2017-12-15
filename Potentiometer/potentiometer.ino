int potpin = 0; // initialize analog pin 0
int ledpin = 11;
int val = 0; // temporarily store variables value from the sensor

void setup () {
  pinMode(ledpin, OUTPUT); // pin 11 is an output
  Serial.begin(9600);
}

void loop () {
  val = analogRead(potpin); // reading sensor value from the potentiometer
  Serial.println(val);

  analogWrite(ledpin, val/4); // turn on LED and set up brightness (max output is 255)
  delay(10);
}

