#include <FastLED.h>

#define EFFECT_BUTTON_PIN 9
#define BRIGHTNESS_BUTTON_PIN 11

boolean lastEffectButton = LOW; 
boolean currentEffectButton = LOW;

boolean lastBrightnessButton = LOW; 
boolean currentBrightnessButton = LOW;

void setup() {
  pinMode(EFFECT_BUTTON_PIN, INPUT);
  pinMode(BRIGHTNESS_BUTTON_PIN, INPUT);
  setupEffects();
}

void loop() {
   listenEffectButton();
   listenBrightnessButton();
   showEffect();
}

void listenEffectButton() {
  currentEffectButton = debounce(lastEffectButton, EFFECT_BUTTON_PIN);
  if (lastEffectButton == LOW && currentEffectButton == HIGH) {
     setNextEffect();
  }
  lastEffectButton = currentEffectButton;
}

void listenBrightnessButton() {
  currentBrightnessButton = debounce(lastBrightnessButton, BRIGHTNESS_BUTTON_PIN);
  if (lastBrightnessButton == LOW && currentBrightnessButton == HIGH) {
     setNextBrightness();
  }
  lastBrightnessButton = currentBrightnessButton;
}

boolean debounce(boolean last, int pin) {
  boolean current = digitalRead(pin);
  if (last != current) {
    delay(5);
    current = digitalRead(pin);
    return current;
  }
}
