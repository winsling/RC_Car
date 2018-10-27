#include <Wire.h>

const int buttonPin = 7;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    Wire.begin();
    pinMode(buttonPin, INPUT);
    pinMode(3, OUTPUT);

    digitalWrite(3, LOW);




}

void loop() {

  digitalWrite(3, HIGH);
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

    Wire.beginTransmission(18);

    if (buttonState == HIGH) {
        Wire.write('1');
    }
    else {
        Wire.write('0');
    }
    Wire.endTransmission();
  
    Wire.requestFrom(18, 2);

    byte response[2];
    int index = 0;
  
        // Wait for response
    while (Wire.available()) {
        byte b = Wire.read();
  
        response[index] = b;
        index++;
    }
  
    Serial.print(response[0]);
    Serial.print('.');
    Serial.print(response[1]);
    Serial.println();

  
    delay(2000);
    digitalWrite(3, LOW);

}
  

  
