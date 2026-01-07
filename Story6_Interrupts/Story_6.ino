// STORY 6 – INTERRUPTS

const int leftRev     = 12;
const int leftFwd     = 11;
const int leftEnable  = 10;

const int rightEnable = 9;
const int rightFwd    = 8;
const int rightRev    = 7;

const int leftSensor  = 2;   // Interrupt pin
const int rightSensor = 3;   // Interrupt pin

volatile int pulseCount = 0;
const int pulsesFor2m = 100;   // Calibrated value

void countLeft() {
  pulseCount++;
}

void countRight() {
  pulseCount++;
}
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

void story6() {
  pulseCount = 0;     // Reset distance
  moveForward();      // Start moving

  while (pulseCount < pulsesFor2m) {
  }

  stopMotors();       

  while (true) {
  }
}

void setup() {
  pinMode(leftRev, OUTPUT);
  pinMode(leftFwd, OUTPUT);
  pinMode(leftEnable, OUTPUT);

  pinMode(rightEnable, OUTPUT);
  pinMode(rightFwd, OUTPUT);
  pinMode(rightRev, OUTPUT);

  pinMode(leftSensor, INPUT_PULLUP);
  pinMode(rightSensor, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(leftSensor), countLeft, FALLING);
  attachInterrupt(digitalPinToInterrupt(rightSensor), countRight, FALLING);
}
void loop() {
  story6();   // Runs once when reset is pressed
}
