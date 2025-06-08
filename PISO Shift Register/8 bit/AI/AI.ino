/*
  Arduino Mega program to read parallel data from a 74HC165 shift register.
  Connections:
    - 74HC165 QH (serial out)   -> Arduino Mega Pin 51 (MISO, or any digital)
    - 74HC165 CP (clock)        -> Arduino Mega Pin 52 (SCK, or any digital)
    - 74HC165 PL (latch/load)   -> Arduino Mega Pin 53 (SS, or any digital)
    - 74HC165 CE (enable, active low) -> GND
    - 74HC165 Parallel Inputs   -> Your switches or data source
    - VCC, GND appropriately
*/

#define DATA_PIN   9  // QH (serial out)
#define CLOCK_PIN  11  // CP (clock)
#define LATCH_PIN  10  // PL (latch/load, active low)

void setup() {
  Serial.begin(9600);
  pinMode(DATA_PIN, INPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);

  digitalWrite(CLOCK_PIN, LOW);
  digitalWrite(LATCH_PIN, HIGH);

  digitalWrite(33, LOW);
  digitalWrite(35, HIGH);
  digitalWrite(37, LOW);
  digitalWrite(39, LOW);
  digitalWrite(41, LOW);
  digitalWrite(43, LOW);
  digitalWrite(45, LOW);
  digitalWrite(47, LOW);
}

uint8_t read74HC165() {
  uint8_t data = 0;

  // Latch/load to copy parallel inputs into shift register
  digitalWrite(LATCH_PIN, LOW);
  delayMicroseconds(100);
  digitalWrite(LATCH_PIN, HIGH);

  // Read 8 bits
  for (int i = 0; i < 8; i++) {
    data <<= 1;
    data |= digitalRead(DATA_PIN);

    // Pulse the clock
    digitalWrite(CLOCK_PIN, HIGH);
    delayMicroseconds(100);
    digitalWrite(CLOCK_PIN, LOW);
    delayMicroseconds(100);
  }
  return data;
}

void loop() {
  uint8_t value = read74HC165();
  Serial.print("Read value: ");
  for (int i = 7; i >= 0; i--) {
    Serial.print((value >> i) & 0x01);
  }
  Serial.print("\n");
  delay(500);
}