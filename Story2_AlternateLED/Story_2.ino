// Story 2 Two external LEDs alternate flashing every second.

// Define the pins connected to the LEDs
const int LED_PIN_1 = 12; 
const int LED_PIN_2 = 11; 

void setup() {
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN_1, HIGH);
  digitalWrite(LED_PIN_2, LOW);
  
  delay(1000); 

  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_2, HIGH);
  
  delay(1000); 
  
}
