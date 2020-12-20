int fromPi = 0;

int LED = 3;

void setup() {
  Serial.begin(9600);

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

    
    if (fromPi == 'O') {
      digitalWrite(LED, HIGH);
    }

    if (fromPi == 'F') {
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
