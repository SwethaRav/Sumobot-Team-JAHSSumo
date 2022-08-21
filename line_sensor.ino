
#define SENSOR_PIN A0
void setup(){
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}

void loop(){
  //int a = digitalRead(SENSOR_PIN);
  Serial.print(analogRead(SENSOR_PIN));
  if (analogRead(SENSOR_PIN) < 500) {
    Serial.println("BLACK");
  }
  else {
    Serial.println("WHITE");
  }
  //Serial.println(a);
  delay(100);
}
