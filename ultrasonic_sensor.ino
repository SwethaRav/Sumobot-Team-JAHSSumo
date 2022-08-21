#define trigPin 4
#define echoPin 3
 
void setup() {
  Serial.begin (9600);
  //trigPin Arduino sends signal to start ultrasonic pulse
  pinMode(trigPin, OUTPUT);
  //EchoPin ultrasonic range finder sends info about duration of trip taken by ultrasonic pulse -> Arduino
  pinMode(echoPin, INPUT);
}
 
void loop() {
  //declare variables duration and distance
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
  }
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    exit(0);
  }
  delay(500);
}
