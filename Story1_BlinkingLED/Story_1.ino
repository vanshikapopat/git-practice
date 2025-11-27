// C++ code for Arduino for blinking LED
//
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Fast blink
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  
  // Slow blink
  digitalWrite(LED_BUILTIN, HIGH);
  delay(800);
  digitalWrite(LED_BUILTIN, LOW);
  delay(800);
}