// Motor control pins
int leftRev = 12;
int leftFwd = 11;
int leftEnable = 10;

int rightEnable = 9;
int rightFwd = 8;
int rightRev = 7;

void setup() {
  pinMode(leftRev, OUTPUT);
  pinMode(leftFwd, OUTPUT);
  pinMode(leftEnable, OUTPUT);

  pinMode(rightEnable, OUTPUT);
  pinMode(rightFwd, OUTPUT);
  pinMode(rightRev, OUTPUT);
}

void loop() {
  // --- 1. FORWARD (5 Seconds) ---
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, HIGH);
  digitalWrite(leftRev, LOW);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, HIGH);
  digitalWrite(rightRev, LOW);

  delay(5000);

  // --- 2. STOP (1 Second) ---
  digitalWrite(leftEnable, LOW);
  digitalWrite(rightEnable, LOW);

  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, LOW);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, LOW);

  delay(1000);

  // --- 3. REVERSE (2 Seconds) ---
  digitalWrite(leftEnable, HIGH);
  digitalWrite(leftFwd, LOW);
  digitalWrite(leftRev, HIGH);

  digitalWrite(rightEnable, HIGH);
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightRev, HIGH);

  delay(2000);
}
