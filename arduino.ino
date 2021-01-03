#include "FastLED.h"

#define NUM_LEDS 150
#define DATA_PIN 8

CRGB leds[NUM_LEDS];
bool expectColor = false;
int index = 0;

void setup() {
//  Serial.begin(115200);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  FastLED.clear();
//  for (int i = 0; i < 15; i++) {
//    leds[i] = CRGB(255, 255, 255);
//    delay(10);
//    FastLED.show();
//  }
   leds[0] = CRGB(255, 255, 255);
}

void loop() {
//  if (Serial.available() > 0) { 
//    Serial.readBytes( (char*)leds, NUM_LEDS * 3);
//    index++;
//    FastLED.show();
//    if (index == 150) {
//      index = 0;
//    }
//    
//  }
  
}
