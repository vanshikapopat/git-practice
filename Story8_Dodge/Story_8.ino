// STORY 8 – DODGE

const int LEFT_REV     = 12;
const int LEFT_FWD     = 11;
const int LEFT_ENABLE  = 10;

const int RIGHT_ENABLE = 9; 
const int RIGHT_FWD    = 8;
const int RIGHT_REV    = 7;

const int OBSTACLE_BTN = 2;   
const int SPEED_FWD   = 180; 
const int SPEED_TURN  = 180;

const int PAUSE_MS    = 500;
const int REVERSE_MS  = 600;
const int TURN_90_MS  = 850; 

void moveForward() {
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_REV, LOW);

  analogWrite(LEFT_ENABLE, SPEED_FWD);
  analogWrite(RIGHT_ENABLE, SPEED_FWD);
}

void stopRobot() {
  analogWrite(LEFT_ENABLE, 0);
  analogWrite(RIGHT_ENABLE, 0);

  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_FWD, LOW);
  digitalWrite(RIGHT_REV, LOW);
}

void reverseRobot(int ms) {
  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(LEFT_REV, HIGH);
  digitalWrite(RIGHT_FWD, LOW);
  digitalWrite(RIGHT_REV, HIGH);

  analogWrite(LEFT_ENABLE, SPEED_FWD);
  analogWrite(RIGHT_ENABLE, SPEED_FWD);
  delay(ms);
}

void turnLeft90(int ms) {
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_REV, LOW);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_REV, LOW);

  analogWrite(LEFT_ENABLE, 0);
  analogWrite(RIGHT_ENABLE, SPEED_TURN);
  delay(ms);
}
bool obstaclePressed() {
  return digitalRead(OBSTACLE_BTN) == LOW;
}

bool obstacleTriggeredOnce() {
  if (!obstaclePressed()) return false;

  delay(30);
  if (!obstaclePressed()) return false;

  while (obstaclePressed()) { }
  delay(30);
  return true;
}

void setup() {
  pinMode(LEFT_REV, OUTPUT);
  pinMode(LEFT_FWD, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);

  pinMode(RIGHT_ENABLE, OUTPUT);
  pinMode(RIGHT_FWD, OUTPUT);
  pinMode(RIGHT_REV, OUTPUT);

  pinMode(OBSTACLE_BTN, INPUT_PULLUP);

  stopRobot();
}

void loop() {
  moveForward();

  // If obstacle within 12cm is detected
  if (obstacleTriggeredOnce()) {
    stopRobot();
    delay(PAUSE_MS);

    reverseRobot(REVERSE_MS);
    stopRobot();
    delay(200);

    turnLeft90(TURN_90_MS);
    stopRobot();
    delay(200);
  }
}