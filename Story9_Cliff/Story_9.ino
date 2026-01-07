// STORY 9 – CLIFF

const int LEFT_REV     = 12;
const int LEFT_FWD     = 11;
const int LEFT_ENABLE  = 10;   // PWM

const int RIGHT_ENABLE = 9;    // PWM
const int RIGHT_FWD    = 8;
const int RIGHT_REV    = 7;

const int BUTTON_PIN = 2;      // interrupt pin
volatile bool cliffDetected = false;

const int SPEED = 180;         

void setup() {
  pinMode(LEFT_REV, OUTPUT);
  pinMode(LEFT_FWD, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);

  pinMode(RIGHT_ENABLE, OUTPUT);
  pinMode(RIGHT_FWD, OUTPUT);
  pinMode(RIGHT_REV, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), triggerCliff, FALLING);

  stopRobot();
}

void loop() {
  if (cliffDetected) {
    executeCliffSafety();

    while (true) {
      stopRobot();
    }
  } else {
    driveForward();
  }
}

void triggerCliff() {
  cliffDetected = true;
}

void executeCliffSafety() {
  stopRobot();
  delay(200);

  driveReverse();
  delay(500);

  stopRobot();
}

void driveForward() {
  // Forward direction pins
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_REV, LOW);

  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_REV, LOW);

  analogWrite(LEFT_ENABLE, SPEED);
  analogWrite(RIGHT_ENABLE, SPEED);
}

void driveReverse() {
  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(LEFT_REV, HIGH);

  digitalWrite(RIGHT_FWD, LOW);
  digitalWrite(RIGHT_REV, HIGH);

  analogWrite(LEFT_ENABLE, SPEED);
  analogWrite(RIGHT_ENABLE, SPEED);
}

void stopRobot() {
  analogWrite(LEFT_ENABLE, 0);
  analogWrite(RIGHT_ENABLE, 0);

  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_FWD, LOW);
  digitalWrite(RIGHT_REV, LOW);
}
