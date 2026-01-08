#define TRIGGER_PIN 4
#define ECHO_PIN 5
#define MAX_DISTANCE 200  

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const int leftRev     = 12;
const int leftFwd     = 11;
const int leftEnable  = 10;

const int rightEnable = 9;
const int rightFwd    = 8;
const int rightRev    = 7;

const int OBSTACLE_CM = 12;   
const int PAUSE_MS    = 300;  
const int BACKUP_MS   = 600;   
const int TURN90_MS   = 850;    

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

void moveBackward() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, HIGH);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, HIGH);
}

void turnLeft() {
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, HIGH);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, HIGH);
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

  sonar.ping_cm();

  moveForward();
}

void loop() {
  unsigned int distance = sonar.ping_cm();

  Serial.print("Distance (cm): ");
  Serial.println(distance);

  if (distance > 0 && distance <= OBSTACLE_CM) {
    stopMotors();
    delay(PAUSE_MS);

    moveBackward();
    delay(BACKUP_MS);

    stopMotors();
    delay(PAUSE_MS);

    turnLeft();
    delay(TURN90_MS);

    stopMotors();
    delay(PAUSE_MS);
    moveForward();
  }
  delay(50);
}
