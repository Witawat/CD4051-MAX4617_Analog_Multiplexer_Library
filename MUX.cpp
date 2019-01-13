#include "MUX.h"

// Constructor

MUX::MUX(uint8_t pinC, uint8_t pinB, uint8_t pinA) {
  _pinA = pinA; 
  _pinB = pinB; 
  _pinC = pinC;
  
  cp[0] = _pinA;
  cp[1] = _pinB;
  cp[2] = _pinC;
}

// Methods

void MUX::setup(void) {
	
	// Initialization of addressing pins
  for (int i  = 0; i < 3; i++) {
    pinMode(cp[i], OUTPUT);
  }
  
	// By default Channel 0 is selected
  for (int posPin  = 0; posPin < 3; posPin++) {
    digitalWrite(cp[posPin], LOW);
  }
  
}
	// Select channel by bit shifting
void MUX::selectChannel(uint8_t ch) {
  
  for (int state = 0; state < 3; state++) {
    digitalWrite(cp[state], ch & 1);
    ch >>= 1;
  }
}
