#include "FastLED.h"

#define NUM_LEDS 150
#define DATA_PIN 8

CRGB leds[NUM_LEDS];
bool expectColor = false;
int index = 0;

void setup() {
  Serial.begin(115200);

  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  if (Serial.available() > 0) { 
    if (expectColor) {
      byte data[3] = Serial.read();
      
      if (data[0] == '$') {
        expectColor = false;
        index = 0;
      } 
      
      else {
        leds[index] = (*((CRGB*) &data));
        index++;
      }  
        
    } 
    
    else {
      if (Serial.read() == '^') {
        expectColor = true;
      }
    }
    
  }
  
}
