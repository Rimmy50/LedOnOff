#include "FastLED.h"
#define NUM_LEDS 150
#define OUTPUT_PIN 8
#define LED_STRIP WS2812B

CRGB leds[NUM_LEDS];

int fromPi = 0;


void setup() {
  Serial.begin(9600);

  FastLED.addLeds<LED_STRIP, OUTPUT_PIN, GRB>(leds, NUM_LEDS);
  
  
}

void loop() {
  if (Serial.available() > 0) { 
    fromPi = Serial.read();

    /*
    Serial.print("I received: ");
    Serial.print(fromPi, DEC);
    */

    
    if (fromPi == 'O') {
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Red;
      }
      
      FastLED.show();
    }
    if (fromPi == 'F') {
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;
      }
      
      FastLED.show();
    }
    
    
    /*
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
    */
    
  }
  
}
