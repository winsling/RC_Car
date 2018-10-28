#include <Servo.h>

Servo ESC1;

int potpin = 0;
int val;


void setup() {

ESC1.attach(9); //Adds ESC to certain pin. arm();

Serial.begin(9600);

}

void loop() {

  val = analogRead(potpin);
  val = map(val,0,1023,70,110);
  ESC1.write(val);
  Serial.println(val);
  delay(15);

}
