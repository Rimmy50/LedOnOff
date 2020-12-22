int fromPi = 0;

int LED = 8;

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) { 
    fromPi = Serial.read();

    //Serial.print("Test");

    /*
    Serial.print("I received: ");
    Serial.print(fromPi, DEC);
    */

    
    if (fromPi == '1') {
      digitalWrite(LED, HIGH);
    }

    if (fromPi == '0') {
      digitalWrite(LED, LOW);
    }
    
    
    /*
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
    */
    
  }
  
}
