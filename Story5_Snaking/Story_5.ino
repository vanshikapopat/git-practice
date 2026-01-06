// Story 5: Rover Movement with Snake Pattern
// Builds on Story 4

// Motor control pins
int leftRev = 12;
int leftFwd = 11;
int leftEnable = 10;

int rightEnable = 9;
int rightFwd = 8;
int rightRev = 7;

// Setup
void setup() {
  pinMode(leftRev, OUTPUT);
  pinMode(leftFwd, OUTPUT);
  pinMode(leftEnable, OUTPUT);

  pinMode(rightEnable, OUTPUT);
  pinMode(rightFwd, OUTPUT);
  pinMode(rightRev, OUTPUT);
}
// Story 4 Functions

// Move Forward for fixed time
void moveForward() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, HIGH);
  digitalWrite(leftRev, LOW);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, HIGH);
  digitalWrite(rightRev, LOW);

  delay(5000); // 5 seconds forward
}

// Stop Rover for fixed time
void stopRover() {
  digitalWrite(leftEnable, LOW);
  digitalWrite(rightEnable, LOW);

  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, LOW);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, LOW);

  delay(1000); // 1 second stop
}

// Move Reverse for fixed time
void moveReverse() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, HIGH);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, HIGH);

  delay(2000); // 2 seconds reverse
}
// Story 5 Functions (PWM Control)
// Move straight at a given speed
void moveStraight(int speed) {
  digitalWrite(leftFwd, HIGH);
  digitalWrite(leftRev, LOW);
  digitalWrite(rightFwd, HIGH);
  digitalWrite(rightRev, LOW);

  analogWrite(leftEnable, speed);
  analogWrite(rightEnable, speed);
}

// Turn left by slowing left motor
void moveLeft(int speedLeft, int speedRight) {
  digitalWrite(leftFwd, HIGH);
  digitalWrite(leftRev, LOW);
  digitalWrite(rightFwd, HIGH);
  digitalWrite(rightRev, LOW);

  analogWrite(leftEnable, speedLeft);
  analogWrite(rightEnable, speedRight);
}

// Turn right by slowing right motor
void moveRight(int speedLeft, int speedRight) {
  digitalWrite(leftFwd, HIGH);
  digitalWrite(leftRev, LOW);
  digitalWrite(rightFwd, HIGH);
  digitalWrite(rightRev, LOW);

  analogWrite(leftEnable, speedLeft);
  analogWrite(rightEnable, speedRight);
}

// Stop motors with optional delay
void stopMotors(int delayTime) {
  analogWrite(leftEnable, 0);
  analogWrite(rightEnable, 0);

  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, LOW);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, LOW);

  delay(delayTime);
}

// Story 4 Function
// Runs the full Story 4 sequence
void Story4() {
  moveForward();
  stopRover();
  moveReverse();
  stopRover();
}

// Story 5 Function
// Snake movement sequence
void Story5() {
  moveStraight(200); // 2 sec straight
  delay(2000);

  moveLeft(150, 255); // 2 sec left
  delay(2000);

  moveRight(255, 150); // 2 sec right
  delay(2000);

  moveLeft(150, 255); // 2 sec left
  delay(2000);

  moveRight(255, 150); // 2 sec right
  delay(2000);

  stopMotors(1000); // final stop
}

// Main loop
void loop() {
  Story5(); // Run the snake movement
}
