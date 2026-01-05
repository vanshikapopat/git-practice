

// Motor Pins
const int MOTOR_L_FWD = 5;  // Green LED 1
const int MOTOR_R_FWD = 6;  // Green LED 2
const int MOTOR_L_REV = 3;  // Red LED 1
const int MOTOR_R_REV = 4;  // Red LED 2

const int BUTTON_PIN = 2;   
volatile bool obstacleDetected = false;

void setup() {
  pinMode(MOTOR_L_FWD, OUTPUT);
  pinMode(MOTOR_R_FWD, OUTPUT);
  pinMode(MOTOR_L_REV, OUTPUT);
  pinMode(MOTOR_R_REV, OUTPUT);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), triggerObstacle, FALLING);
}

void loop() {
  if (obstacleDetected) {
    executeEscape();
    obstacleDetected = false; // Reset for next obstacle
  } else {
    driveForward();
  }
}

void triggerObstacle() {
  obstacleDetected = true;
}

void executeEscape() {
  // 1. Stop and Pause
  stopRobot(500); 
  
  // 2. Back Up (Red LEDs)
  digitalWrite(MOTOR_L_REV, HIGH);
  digitalWrite(MOTOR_R_REV, HIGH);
  delay(1000); 
  stopRobot(200);

  // 3. Turn 90 Degrees Left
  // To turn left, stop left motor and drive right motor forward
  digitalWrite(MOTOR_L_FWD, LOW);
  digitalWrite(MOTOR_R_FWD, HIGH);
  delay(850);
  
  stopRobot(500);
}

void driveForward() {
  digitalWrite(MOTOR_L_FWD, HIGH);
  digitalWrite(MOTOR_R_FWD, HIGH);
  digitalWrite(MOTOR_L_REV, LOW);
  digitalWrite(MOTOR_R_REV, LOW);
}

void stopRobot(int duration) {
  digitalWrite(MOTOR_L_FWD, LOW);
  digitalWrite(MOTOR_R_FWD, LOW);
  digitalWrite(MOTOR_L_REV, LOW);
  digitalWrite(MOTOR_R_REV, LOW);
  delay(duration);
}
