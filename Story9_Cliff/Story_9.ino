
// Motor Pins
const int MOTOR_L_FWD = 5;
const int MOTOR_R_FWD = 6;
const int MOTOR_L_REV = 3;
const int MOTOR_R_REV = 4;

const int BUTTON_PIN = 2; // cliff sensor
volatile bool cliffDetected = false;

void setup() {
  pinMode(MOTOR_L_FWD, OUTPUT);
  pinMode(MOTOR_R_FWD, OUTPUT);
  pinMode(MOTOR_L_REV, OUTPUT);
  pinMode(MOTOR_R_REV, OUTPUT);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), triggerCliff, FALLING);
}

void loop() {
  if (cliffDetected) {
    executeCliffSafety();
    while(true) { 
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
  
  // Reverse for half a second
  digitalWrite(MOTOR_L_REV, HIGH);
  digitalWrite(MOTOR_R_REV, HIGH);
  delay(500); 
  
  stopRobot();      
}

void driveForward() {
  digitalWrite(MOTOR_L_FWD, HIGH);
  digitalWrite(MOTOR_R_FWD, HIGH);
  digitalWrite(MOTOR_L_REV, LOW);
  digitalWrite(MOTOR_R_REV, LOW);
}

void stopRobot() {
  digitalWrite(MOTOR_L_FWD, LOW);
  digitalWrite(MOTOR_R_FWD, LOW);
  digitalWrite(MOTOR_L_REV, LOW);
  digitalWrite(MOTOR_R_REV, LOW);
}
