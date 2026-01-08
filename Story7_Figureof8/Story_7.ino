// Motor pins
const int leftRev     = 12;
const int leftFwd     = 11;
const int leftEnable  = 10;

const int rightEnable = 9;
const int rightFwd    = 8;
const int rightRev    = 7;

const int DRIVE_OUT_MS = 2000;
const int DRIVE_SIDE_MS = 2000;
const int TURN_MS = 850;

void moveForward() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, HIGH);
  digitalWrite(leftRev, LOW);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, HIGH);
  digitalWrite(rightRev, LOW);
}

void stopMotors() {
  digitalWrite(leftEnable, LOW);
  digitalWrite(rightEnable, LOW);

  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, LOW);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, LOW);
}

void turnLeft() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, HIGH);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, HIGH);
  digitalWrite(rightRev, LOW);
}

void turnRight() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, HIGH);
  digitalWrite(leftRev, LOW);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, HIGH);
}

void moveForwardTimed(int ms) {
  moveForward();
  delay(ms);
}

void turnLeftTimed(int ms) {
  turnLeft();
  delay(ms);
}

void turnRightTimed(int ms) {
  turnRight();
  delay(ms);
}

void story7_FigureOf8() {
  moveForwardTimed(DRIVE_OUT_MS);

  for (int side = 0; side < 4; side++) {
    moveForwardTimed(DRIVE_SIDE_MS);
    turnLeftTimed(TURN_MS);
  }

  for (int side = 0; side < 4; side++) {
    moveForwardTimed(DRIVE_SIDE_MS);
    turnRightTimed(TURN_MS);
  }
  stopMotors();
  exit(0);
}

void setup() {
  pinMode(leftRev, OUTPUT);
  pinMode(leftFwd, OUTPUT);
  pinMode(leftEnable, OUTPUT);

  pinMode(rightEnable, OUTPUT);
  pinMode(rightFwd, OUTPUT);
  pinMode(rightRev, OUTPUT);
}

void loop() {
  story7_FigureOf8();
}
