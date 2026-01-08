#define TRIGGER_PIN 4
#define ECHO_PIN 5

#define TRIGGER_DOWN 13
#define ECHO_DOWN 17

#define MAX_DISTANCE 200

NewPing sonarFront(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
NewPing sonarDown(TRIGGER_DOWN, ECHO_DOWN, MAX_DISTANCE);

const int leftRev     = 12;
const int leftFwd     = 11;
const int leftEnable  = 10;

const int rightEnable = 9;
const int rightFwd    = 8;
const int rightRev    = 7;

const int GROUND_OK_CM   = 5;     
const int DROP_LIMIT_CM  = 12;    

void moveForward() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, HIGH);
  digitalWrite(leftRev, LOW);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, HIGH);
  digitalWrite(rightRev, LOW);
}

void moveBackward() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, HIGH);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, HIGH);
}

void stopMotors() {
  digitalWrite(leftEnable, LOW);
  digitalWrite(rightEnable, LOW);

  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, LOW);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, LOW);
}

void setup() {
  Serial.begin(115200);

  pinMode(leftRev, OUTPUT);
  pinMode(leftFwd, OUTPUT);
  pinMode(leftEnable, OUTPUT);

  pinMode(rightEnable, OUTPUT);
  pinMode(rightFwd, OUTPUT);
  pinMode(rightRev, OUTPUT);

  sonarFront.ping_cm();
  sonarDown.ping_cm();

  moveForward();
}

void loop() {

  unsigned int groundDistance = sonarDown.ping_cm();

  Serial.print("Ground distance (cm): ");
  Serial.println(groundDistance);

  if (groundDistance == 0 || groundDistance > DROP_LIMIT_CM) {

    stopMotors();
    delay(200);

    moveBackward();
    delay(500);

    stopMotors();

    exit(0);
  }

  moveForward();

  delay(50); 
}
