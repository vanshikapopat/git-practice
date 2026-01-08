// Motor control pins
const int leftRev     = 12;
const int leftFwd     = 11;
const int leftEnable  = 10;

const int rightEnable = 9;
const int rightFwd    = 8;
const int rightRev    = 7;

const int LEFT_FEEDBACK  = 3;
const int RIGHT_FEEDBACK = 2;

volatile int leftcounter  = 0;
volatile int rightcounter = 0;

const int COUNTS_PER_METER = 435;
const int TARGET_DISTANCE  = 2;
const int TARGET_COUNTS    = COUNTS_PER_METER * TARGET_DISTANCE;

void LeftMotorISR() {
  leftcounter++;
}

void RightMotorISR() {
  rightcounter++;
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
  leftcounter  = 0;
  rightcounter = 0;

  moveForward();

  while ((leftcounter + rightcounter) / 2 < TARGET_COUNTS) {
  }

  stopMotors();
  exit(0);  
}

void setup() {
  Serial.begin(115200);

  pinMode(leftRev, OUTPUT);
  pinMode(leftFwd, OUTPUT);
  pinMode(leftEnable, OUTPUT);

  pinMode(rightEnable, OUTPUT);
  pinMode(rightFwd, OUTPUT);
  pinMode(rightRev, OUTPUT);

  pinMode(LEFT_FEEDBACK, INPUT_PULLUP);
  pinMode(RIGHT_FEEDBACK, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
}

void loop() {
  story6();   // runs once after reset
}
