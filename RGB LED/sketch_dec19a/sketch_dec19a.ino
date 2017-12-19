int redpin = 11;
int bluepin = 10;
int greenpin = 9;

int val;

void setup () {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);

  Serial.begin(9600);
}

void loop () {
  for(val = 255; val > 0; val--){
    analogWrite(redpin, val);
    analogWrite(bluepin, 255 - val);
    analogWrite(greenpin, 128 - val);
  Serial.println(val, DEC);
  }

}

