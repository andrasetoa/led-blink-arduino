/*
 * LED Blink Arduino Project
 * Created by: [Nama Kamu]
 * GitHub: https://github.com/unebreeton/led-blink-arduino
 * 
 * Features:
 * 1. Basic LED blink
 * 2. Multiple patterns
 * 3. Serial monitor control
 */

// ========== CONFIGURATION ==========
#define LED_PIN 13      // Built-in LED on Arduino Uno
#define BUTTON_PIN 2    // Optional: for future expansion

// ========== SETUP ==========
void setup() {
  // Initialize LED pin
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize Serial communication
  Serial.begin(9600);
  Serial.println("==========================");
  Serial.println("LED Blink Program Started");
  Serial.println("Type '1' for Pattern 1");
  Serial.println("Type '2' for Pattern 2");
  Serial.println("Type '3' for Pattern 3");
  Serial.println("==========================");
}

// ========== MAIN LOOP ==========
void loop() {
  // Check for Serial input
  if (Serial.available() > 0) {
    char command = Serial.read();
    executeCommand(command);
  }
  
  // Default pattern (runs if no serial input)
  pattern1_basic();
}

// ========== FUNCTIONS ==========

// PATTERN 1: Basic blink (1 second interval)
void pattern1_basic() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}

// PATTERN 2: Fast blink (200ms interval)
void pattern2_fast() {
  for(int i = 0; i < 10; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
}

// PATTERN 3: SOS Morse Code
void pattern3_sos() {
  // S (3 short)
  for(int i = 0; i < 3; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
  delay(300);
  
  // O (3 long)
  for(int i = 0; i < 3; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(600);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
  delay(300);
  
  // S (3 short)
  for(int i = 0; i < 3; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
  delay(1000);
}

// Execute command from Serial
void executeCommand(char cmd) {
  switch(cmd) {
    case '1':
      Serial.println("Pattern 1: Basic Blink");
      pattern1_basic();
      break;
    case '2':
      Serial.println("Pattern 2: Fast Blink");
      pattern2_fast();
      break;
    case '3':
      Serial.println("Pattern 3: SOS Morse Code");
      pattern3_sos();
      break;
    default:
      Serial.println("Unknown command. Use 1, 2, or 3");
  }
}
