#include "FastLED.h"

#define NUM_LEDS 150
#define DATA_PIN 8

CRGB leds[NUM_LEDS];
bool expectColor = false;
int index = 0;

void setup() {
  Serial.begin(115200);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  FastLED.clear();
  FastLED.show();
  
}

void loop() {
  if (Serial.available() > 0) { 
    Serial.readBytes( (char*)leds, NUM_LEDS * 3);
    index++;
    FastLED.show();
  }

  
}
