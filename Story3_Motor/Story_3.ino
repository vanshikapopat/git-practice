void setup() {
  // Initialize all used pins as outputs
  pinMode(2, OUTPUT); // Red LED
  pinMode(3, OUTPUT); // Yellow LED
  pinMode(4, OUTPUT); // Green LED 1
  pinMode(5, OUTPUT); // Green LED 2
}

void loop() {
  // --- 1. FORWARD (5 Seconds) ---
  // Turn on Green LEDs, turn off others
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(5000); // Wait for 5 seconds

  // --- 2. STOP (1 Second) ---
  // Turn all LEDs off
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(1000); // Wait for 1 second

  // --- 3. REVERSE (2 Seconds) ---
  // Turn on Red and Yellow LEDs, turn off Green
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(2000); // Wait for 2 seconds
  
  // The loop then restarts from the beginning
}
