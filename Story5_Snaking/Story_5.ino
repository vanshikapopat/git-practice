
// Pins
const int MOTOR_L_FWD = 5;  
const int MOTOR_R_FWD = 6;  
const int MOTOR_L_REV = 3;  
const int MOTOR_R_REV = 2;  

void setup() {
  pinMode(MOTOR_L_FWD, OUTPUT);
  pinMode(MOTOR_R_FWD, OUTPUT);
  pinMode(MOTOR_L_REV, OUTPUT);
  pinMode(MOTOR_R_REV, OUTPUT);

  runStory5();
}

void loop() {
}

void runStory5() {
  // 2s straight, 2s left, 2s right, 2s left, 2s right
  moveStraight(255, 2000); 
  moveLeft(130, 2000);     
  moveRight(130, 2000);
  moveLeft(130, 2000);
  moveRight(130, 2000);
  stopRobot(0);
}

void runStory4() {
  moveForward(5000);
  stopRobot(1000);
  moveReverse(2000);
}


// Moves straight
void moveStraight(int speed, int duration) {
  analogWrite(MOTOR_L_FWD, speed);
  analogWrite(MOTOR_R_FWD, speed);
  digitalWrite(MOTOR_L_REV, LOW);
  digitalWrite(MOTOR_R_REV, LOW);
  delay(duration);
}

// Curves left
void moveLeft(int turnSpeed, int duration) {
  analogWrite(MOTOR_L_FWD, turnSpeed); 
  analogWrite(MOTOR_R_FWD, 255);       
  delay(duration);
}

// Curves right
void moveRight(int turnSpeed, int duration) {
  analogWrite(MOTOR_L_FWD, 255);
  analogWrite(MOTOR_R_FWD, turnSpeed);
  delay(duration);
}

void moveForward(int duration) {
  digitalWrite(MOTOR_L_FWD, HIGH);
  digitalWrite(MOTOR_R_FWD, HIGH);
  digitalWrite(MOTOR_L_REV, LOW);
  digitalWrite(MOTOR_R_REV, LOW);
  delay(duration);
}

void moveReverse(int duration) {
  digitalWrite(MOTOR_L_FWD, LOW);
  digitalWrite(MOTOR_R_FWD, LOW);
  digitalWrite(MOTOR_L_REV, HIGH);
  digitalWrite(MOTOR_R_REV, HIGH);
  delay(duration);
}

void stopRobot(int duration) {
  digitalWrite(MOTOR_L_FWD, LOW);
  digitalWrite(MOTOR_R_FWD, LOW);
  digitalWrite(MOTOR_L_REV, LOW);
  digitalWrite(MOTOR_R_REV, LOW);
  delay(duration);
}