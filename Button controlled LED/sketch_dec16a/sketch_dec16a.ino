int ledpin = 11;
int inpin = 7;
int val;
int curstate;

void setup () {
  pinMode(inpin, INPUT);
  pinMode(ledpin, OUTPUT);
  curstate = 0;
}

void loop () {
  val = digitalRead(inpin);

  if (val) {
    curstate = !curstate;
  }

  digitalWrite(ledpin, curstate);
}

