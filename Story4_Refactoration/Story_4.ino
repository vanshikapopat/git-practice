const int RED_LED = 2;
const int YELLOW_LED = 3;
const int GREEN_LED_1 = 4;
const int GREEN_LED_2 = 5;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED_1, OUTPUT);
  pinMode(GREEN_LED_2, OUTPUT);
}

void loop() {
  moveForward(5000); // 5 seconds
  stopRobot(1000);   // 1 second
  moveReverse(2000); // 2 seconds
}

// Movement Functions

void moveForward(int duration) {
  digitalWrite(GREEN_LED_1, HIGH);
  digitalWrite(GREEN_LED_2, HIGH);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  delay(duration);
}

void stopRobot(int duration) {
  digitalWrite(GREEN_LED_1, LOW);
  digitalWrite(GREEN_LED_2, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  delay(duration);
}

void moveReverse(int duration) {
  digitalWrite(GREEN_LED_1, LOW);
  digitalWrite(GREEN_LED_2, LOW);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, HIGH);
  delay(duration);
}