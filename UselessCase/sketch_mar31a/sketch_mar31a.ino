#include <Servo.h>

int i; // we'll increase this variable every time the tumbler is turned on

// Tumbler setup
int tumblerPin = 2;

int debugOn = false;

// Feisty Bear's hand setup
int handPin = 3;
int handInitialAngle = 160; // this is the state in which bear's hand is inside the box
int handOff = 160; // the same with 'handInitialAngle'
int handOn = 10; // the bear's hand is out of the box - trying to turn tumbler off
Servo hand;

// Feisty bear setup
int bearPin = 4;
int bearInitialAngle = 100; // this is the state in which bear is smiling - pretty face
int bearCalmedDown = 100; // the same with 'bearInitialAngle'
int bearAngry = 60; // getting angry
Servo bear;

// Cap setup
int capPin = 5;
int capInitialAngle = 115; // by default cap is closed
int capClosed = 115; // the same with 'capInitialAngle'
int capOpened = 0; // the cap is opened
Servo cap;


void setup() {
  Serial.begin(9600);

  pinMode(tumblerPin, INPUT);

  hand.attach(handPin);
  hand.write(handInitialAngle);

  bear.attach(bearPin);
  bear.write(bearInitialAngle);
  
  cap.attach(capPin);
  cap.write(capInitialAngle);
}

void loop() {
  if(debugOn) {
    Serial.println("Debug mode is on");
    openCap();
  } else {
    if (isTumblerOn()) {
      if ( i >= 3) {
        makeBearAngry();
      }
      
      openCap();
      delay(500);
  
      // turninf gumbler off
      turnTumblerOff();
  
      // waiting for a second so bear could get it's hand back into the box
      delay(500);
  
      // increasing the counter
      increaseCounter();
    } else {
      hideHand();
      calmBearDown();
      delay(500);
      closeCap();
    }
  }
}

/* helper functions */
bool getTumblerSatet() { return digitalRead(tumblerPin);}
bool isTumblerOn() { return getTumblerSatet() == 1;}
bool isTumblerOff() { return !isTumblerOn();}
void turnTumblerOff() { hand.write(handOn);}
void hideHand() { hand.write(handOff);}
void increaseCounter() {i++;}

void makeBearAngry() { bear.write(bearAngry);}
void calmBearDown() { bear.write(bearCalmedDown);}

void openCap() { cap.write(capOpened);}
void closeCap() { cap.write(capClosed);}


