class button {
  public:
    button (byte pin) {
      _pin = pin;
      pinMode(_pin, INPUT_PULLUP);
    }
    int click() {
      bool btnState = digitalRead(_pin);
      if (!btnState && !_flag && millis() - _tmr >= 100) {
        _flag = true;
        _tmr = millis();
        return 1;
      }
      if (!btnState && _flag && millis() - _tmr >= 500) {
        _tmr = millis ();
        return 2;
      }
      if (btnState && _flag) {
        _flag = false;
        _tmr = millis();
      }
      return 0;
    }
  private:
    byte _pin;
    uint32_t _tmr;
    bool _flag;
};
