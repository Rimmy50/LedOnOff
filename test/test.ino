#include "FastLED.h"
#define NUM_LEDS 150
#define OUTPUT_PIN 8
#define LED_STRIP WS2812B

CRGB leds[NUM_LEDS];

int fromPi = 0;

<<<<<<< HEAD:arduino.ino
int LED = 8;
=======
>>>>>>> 49d142f16da5ea030a0d665cbfe029c4ccfd83ca:test/test.ino

void setup() {
  Serial.begin(115200);

  FastLED.addLeds<LED_STRIP, OUTPUT_PIN, GRB>(leds, NUM_LEDS);
  
  
}

void loop() {
  if (Serial.available() > 0) { 
    fromPi = Serial.read();

    /*
    Serial.print("I received: ");
    Serial.print(fromPi, DEC);
    */

    
<<<<<<< HEAD:arduino.ino
    if (fromPi == '1') {
      digitalWrite(LED, HIGH);
    }

    if (fromPi == '0') {
      digitalWrite(LED, LOW);
=======
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
>>>>>>> 49d142f16da5ea030a0d665cbfe029c4ccfd83ca:test/test.ino
    }
    
    
    /*
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
    */
    
  }
  
}
