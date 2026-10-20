
#include <SPI.h>
#include <Wire.h>

#define PIN_ANTENNA A0
#define BUZZER_PIN 12
#define CHECK_DELAY 1000

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6

void setup() {
  Serial.begin(9600);

  pinMode(PIN_ANTENNA, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void showReadings(int emfValue) {
  Serial.print("EMF: ");
  Serial.println(emfValue);
}

void updateLEDs(int value) {
  // Apaga todos os LEDs
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);

  // Acende os LEDs conforme a intensidade
  if (value >= 80)  digitalWrite(LED1, HIGH);
  if (value >= 150) digitalWrite(LED2, HIGH);
  if (value >= 250) digitalWrite(LED3, HIGH);
  if (value >= 400) digitalWrite(LED4, HIGH);
  if (value >= 600) digitalWrite(LED5, HIGH);
}

void updateBuzzer(int value) {
  if (value >= 600) {
    tone(BUZZER_PIN, 2500);
    delay(50);
  }
  else if (value >= 400) {
    tone(BUZZER_PIN, 2000);
    delay(50);
  }
  else if (value >= 250) {
    tone(BUZZER_PIN, 1000);
    delay(50);
  }
  else {
    noTone(BUZZER_PIN);
  }
}

void loop() {
  static unsigned long nextCheck = 0;
  static long emfSum = 0;
  static int iterations = 0;

  int emfValue = constrain(analogRead(PIN_ANTENNA), 0, 1023);

  emfSum += emfValue;
  iterations++;

  updateLEDs(emfValue);
  updateBuzzer(emfValue);

  if (millis() >= nextCheck) {
    int avgValue = iterations > 0 ? emfSum / iterations : emfValue;

    showReadings(avgValue);

    emfSum = 0;
    iterations = 0;

    nextCheck = millis() + CHECK_DELAY;
  }
}
