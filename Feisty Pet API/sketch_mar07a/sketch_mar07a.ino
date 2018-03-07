#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int incomingByte = 0;   // for incoming serial data

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.parseInt();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte);

                if(incomingByte == 1) {
                  Serial.println("Angry");
                  myservo.write(65);
                } else {
                  Serial.println("Normal");
                  myservo.write(100);
                }
        }
}
