// Story 4: Refactored Rover Movements with Functions

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

// Function: Move Forward
void moveForward() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, HIGH);
  digitalWrite(leftRev, LOW);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, HIGH);
  digitalWrite(rightRev, LOW);

  delay(5000); // 5 seconds forward
}

// Function: Stop Rover
void stopRover() {
  digitalWrite(leftEnable, LOW);
  digitalWrite(rightEnable, LOW);

  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, LOW);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, LOW);

  delay(1000); // 1 second stop
}

// Function: Move Reverse
void moveReverse() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, HIGH);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, HIGH);

  delay(2000); // 2 seconds reverse
}

// Main Loop
void loop() {
  moveForward();
  stopRover();
  moveReverse();
  stopRover(); 
}