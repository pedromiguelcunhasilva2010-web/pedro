#include <Arduino.h>

// Definição dos pinos dos LEDs
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;

void setup() {
  // Configurar os pinos como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  // Liga todos os LEDs
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);

  delay(1000); // espera 1 segundo

  // Desliga todos os LEDs
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  delay(1000); // espera 1 segundo
}