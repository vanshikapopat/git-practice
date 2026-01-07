// STORY 7 - SQUARE FIGURE OF 8 

const int LEFT_REV     = 12;
const int LEFT_FWD     = 11;
const int LEFT_ENABLE  = 10; 

const int RIGHT_ENABLE = 9;  
const int RIGHT_FWD    = 8;
const int RIGHT_REV    = 7;

const unsigned long EXIT_TIME  = 2000;  // leave garage (2s)
const unsigned long TURN_TIME  = 850;   // 90 degree turn
const unsigned long DRIVE_TIME = 1500;  // length of each side (adjust)

const int SPEED_STRAIGHT = 180;
const int SPEED_TURN     = 180;

void stopRobot() {
  analogWrite(LEFT_ENABLE, 0);
  analogWrite(RIGHT_ENABLE, 0);

  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_FWD, LOW);
  digitalWrite(RIGHT_REV, LOW);
}

void driveForward(int speedPWM) {
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_REV, LOW);

  analogWrite(LEFT_ENABLE, speedPWM);
  analogWrite(RIGHT_ENABLE, speedPWM);
}

void driveForwardFor(unsigned long ms, int speedPWM) {
  driveForward(speedPWM);
  delay(ms);
}

void turnLeftFor(unsigned long ms, int speedPWM) {
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_REV, LOW);

  analogWrite(LEFT_ENABLE, 0);       
  analogWrite(RIGHT_ENABLE, speedPWM);
  delay(ms);
}

void turnRightFor(unsigned long ms, int speedPWM) {
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_REV, LOW);

  analogWrite(LEFT_ENABLE, speedPWM);
  analogWrite(RIGHT_ENABLE, 0);      
  delay(ms);
}


void leftHandSquare() {
  for (int i = 0; i < 4; i++) {
    driveForwardFor(DRIVE_TIME, SPEED_STRAIGHT);
    turnLeftFor(TURN_TIME, SPEED_TURN);
  }
}

void rightHandSquare() {
  for (int i = 0; i < 4; i++) {
    driveForwardFor(DRIVE_TIME, SPEED_STRAIGHT);
    turnRightFor(TURN_TIME, SPEED_TURN);
  }
}


void story7_FigureOf8() {
  driveForwardFor(EXIT_TIME, SPEED_STRAIGHT);
  leftHandSquare();

  rightHandSquare();

  stopRobot();
  while (true) { }
}

void setup() {
  pinMode(LEFT_REV, OUTPUT);
  pinMode(LEFT_FWD, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);

  pinMode(RIGHT_ENABLE, OUTPUT);
  pinMode(RIGHT_FWD, OUTPUT);
  pinMode(RIGHT_REV, OUTPUT);

  stopRobot();
}

void loop() {
  story7_FigureOf8();  
}
