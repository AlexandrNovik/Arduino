#include <FastLED.h>

#define EFFECT_BUTTON_PIN 9

boolean lastEffectButton = LOW; 
boolean currentEffectButton = LOW;

void setup() {
  // Buttons
  pinMode(EFFECT_BUTTON_PIN, INPUT);
  setupEffects();
}

void loop() {
   listenEffectButton();
   showEffect();
}

void listenEffectButton() {
  currentEffectButton = debounce(lastEffectButton);
  if (lastEffectButton == LOW && currentEffectButton == HIGH) {
     setNextEffect();
  }
  lastEffectButton = currentEffectButton;
}

boolean debounce(boolean last) {
  boolean current = digitalRead(EFFECT_BUTTON_PIN);
  if (last != current) {
    delay(5);
    current = digitalRead(EFFECT_BUTTON_PIN);
    return current;
  }
}
