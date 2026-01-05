
// Pins
const int MOTOR_L_FWD = 5;  
const int MOTOR_R_FWD = 6;  
const int MOTOR_L_REV = 3;
const int MOTOR_R_REV = 2;

// Timing constants from instructions
const int EXIT_TIME = 2000;   // 
const int TURN_TIME = 850;    // 
const int DRIVE_TIME = 1500;  // 

void setup() {
  pinMode(MOTOR_L_FWD, OUTPUT);
  pinMode(MOTOR_R_FWD, OUTPUT);
  pinMode(MOTOR_L_REV, OUTPUT);
  pinMode(MOTOR_R_REV, OUTPUT);

  runStory6(); // Start on reset
}

void loop() {}

void runStory6() {
  // 1. Exit the Garage
  moveStraight(255, EXIT_TIME);
  
  // 2. Left Hand Square
  for (int i = 0; i < 4; i++) {
    moveStraight(255, DRIVE_TIME);
    turnLeft(255, TURN_TIME);
  }

  // 3. Right Hand Square
  for (int i = 0; i < 4; i++) {
    moveStraight(255, DRIVE_TIME);
    turnRight(255, TURN_TIME);
  }

  stopRobot();
}


void moveStraight(int speed, int duration) {
  analogWrite(MOTOR_L_FWD, speed);
  analogWrite(MOTOR_R_FWD, speed);
  delay(duration);
}

void turnLeft(int speed, int duration) {
  analogWrite(MOTOR_L_FWD, 0);     // Stop left
  analogWrite(MOTOR_R_FWD, speed); // Drive right
  delay(duration);
}

void turnRight(int speed, int duration) {
  analogWrite(MOTOR_L_FWD, speed); // Drive left
  analogWrite(MOTOR_R_FWD, 0);     // Stop right
  delay(duration);
}

void stopRobot() {
  digitalWrite(MOTOR_L_FWD, LOW);
  digitalWrite(MOTOR_R_FWD, LOW);
}
