#include <Wire.h>

const int ledPin = 3;



byte dat[5]={0,1,2,3,4};
char c;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    Wire.begin(18);
    Wire.onRequest(requestEvent); // data request to slave
    Wire.onReceive(receiveEvent); // data slave recieved     
    pinMode(ledPin, OUTPUT);

}

void receiveEvent(int howMany) {
    // remember the question: H=humidity, T=temperature
    while (0 < Wire.available()) {
        byte x = Wire.read();
        c = x;
    }
}
  
void requestEvent() {
    // respond to the question
    if (c == '1') {
        byte response[] = { dat[0], dat[1] };
        Wire.write(response, 2);

 
    }
    else {
        byte response[] = { dat[2], dat[3] };
        Wire.write(response, 2);

  
    }
}

void loop() {
  // put your main code here, to run repeatedly:

  
  if (c == '1') {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  

    
  
}
