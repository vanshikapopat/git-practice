
// Pins
const int MOTOR_L_FWD = 5;  
const int MOTOR_R_FWD = 6;  
const int BUTTON_PIN = 2; 

// Variables
volatile int pulseCount = 0; 
const int targetPulses = 100; // 100 pulses = 2 meters

void setup() {
  pinMode(MOTOR_L_FWD, OUTPUT);
  pinMode(MOTOR_R_FWD, OUTPUT);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), addPulse, FALLING);

  runStory6();
}

void loop() {
}

void runStory6() {
  while (pulseCount < targetPulses) {
    digitalWrite(MOTOR_L_FWD, HIGH);
    digitalWrite(MOTOR_R_FWD, HIGH);
  }
  
  stopRobot();
}

void addPulse() {
  pulseCount++; 
}

void stopRobot() {
  digitalWrite(MOTOR_L_FWD, LOW);
  digitalWrite(MOTOR_R_FWD, LOW);
}