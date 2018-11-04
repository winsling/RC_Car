int val=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(12,INPUT);
  Serial.begin(115200);
}

void loop() {

  val=digitalRead(12);
  Serial.println(val);

}
