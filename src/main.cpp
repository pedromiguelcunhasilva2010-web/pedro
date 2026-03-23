#include <Arduino.h>

// Número de botões/LEDs
const int num = 4;

// Arrays de pinos
int botoes[num] = {2, 3, 4, 5};
int leds[num]   = {8, 9, 10, 11};

// Estados
bool estadoLED[num] = {false, false, false, false};
bool ultimoEstadoBotao[num] = {HIGH, HIGH, HIGH, HIGH};

// Debounce
unsigned long ultimoTempo[num] = {0, 0, 0, 0};
const unsigned long delayDebounce = 50;

void setup() {
  for (int i = 0; i < num; i++) {
    pinMode(botoes[i], INPUT_PULLUP);
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < num; i++) {
    bool leitura = digitalRead(botoes[i]);

    // Se mudou o estado, reset do tempo
    if (leitura != ultimoEstadoBotao[i]) {
      ultimoTempo[i] = millis();
    }

    // Se passou tempo suficiente (debounce)
    if ((millis() - ultimoTempo[i]) > delayDebounce) {
      
      // Se botão foi pressionado (HIGH → LOW)
      if (ultimoEstadoBotao[i] == HIGH && leitura == LOW) {
        estadoLED[i] = !estadoLED[i]; // alterna estado
      }
    }

    // Atualiza estado anterior
    ultimoEstadoBotao[i] = leitura;

    // Atualiza LED
    digitalWrite(leds[i], estadoLED[i] ? HIGH : LOW);
  }
}