#include <FastLED.h>

#define EFFECT_BUTTON_PIN 9

boolean lastEffectButton = LOW; 
boolean currentEffectButton = LOW;

void setup() {
  pinMode(EFFECT_BUTTON_PIN, INPUT);
  setupEffects();
}

void loop() {
   listenEffectButton();
   showEffect();
}

bool _pressed = false;
bool _holding = false;
uint32_t _tmr;

void listenEffectButton() {
  currentEffectButton = debounce(lastEffectButton, EFFECT_BUTTON_PIN);
  if (lastEffectButton == LOW && currentEffectButton == HIGH) {
    _pressed = true;
    _tmr = millis();
  }
  if (lastEffectButton == HIGH && currentEffectButton == HIGH && _pressed && millis() - _tmr >= 300) {
      _holding = true;
     _tmr = millis ();
     setNextBrightness();
  }
  if (lastEffectButton == HIGH && currentEffectButton == LOW) {
    if (!_holding) {
      setNextEffect();
    }
     _holding = false;
     _pressed = false;
     _tmr = millis ();
  }
  lastEffectButton = currentEffectButton;
}

boolean debounce(boolean last, int pin) {
  boolean current = digitalRead(pin);
  if (last != current) {
    delay(5);
    current = digitalRead(pin);
    return current;
  }
}
