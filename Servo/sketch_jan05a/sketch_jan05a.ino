int servo_pin = 9;
int my_angle;
int pulse_width;
int val;

void servo_pulse(int servo_pin, int my_angle) {
  pulse_width = (my_angle * 11) + 500;
  digitalWrite(servo_pin, HIGH);
  delayMicroseconds(pulse_width);
  digitalWrite(servo_pin, LOW);
  delay(20 - pulse_width / 1000);
}

void setup() {
  pinMode(servo_pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("servo is ready!");
}

void loop() {
  val = Serial.read();

  if (val >= '0' && val <= '9') {
    val = val - '0';
    val = val * (180 / 9);

    Serial.print("Moving servo to ");
    Serial.print(val, DEC);
    Serial.println();

    for(int i = 0; i <= 50; i++) {
      servo_pulse(servo_pin, val);
    }
  }
}
