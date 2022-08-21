/********* Connections **********/
// Motor connections
#define   IN1   9
#define   IN2   8
#define   IN3   7
#define   IN4   6
#define   ENA   5
#define   ENB   10

// defining constatns
// F == forward
//B == backward
#define FWD 1
#define BWD 5
#define STOP 0
#define LEFT 7
#define RIGHT 3

#define trigPin 4
#define echoPin 3

void setup() {
  Serial.begin(9600);
  //signal sensor pin to start the motor
  //trigPin Arduino sends signal to start ultrasonic pulse
  pinMode(trigPin, OUTPUT);
  //EchoPin ultrasonic range finder sends info about duration of trip taken by ultrasonic pulse -> Arduino
  pinMode(echoPin, INPUT);
  //delay around 5 seconds before the sumobot moves
  delay(3500);
 
}
void motor(int dir, int speed);
void loop() {
  //declare variables duration and distance
  float duration, distance;
  //set  the ultrasonic sensor to be off
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  //sets the ultrasonic senstor to be on
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  //if the distance between object detected and sensor is <= 20
  //then move the motor forward
       
       if (distance <= 35){
          Serial.println("Should be moving forward.");
          Serial.print("Distance = ");
          Serial.println(distance);
          //now move the motor forward
          motor(FWD,255);
          }
        //or else rotate 
        else {
          Serial.println("Should rotate now");
          Serial.print("Distance = ");
          Serial.println(distance);
          motor(LEFT,255);
        }
    }

void motor(int dir, int speed) {
  
  if (dir == FWD) {
    // Left motor forward with full speed
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed);
    // Right motor forward with full speed
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed);
  } else if (dir == BWD) {
    // Left motor backward with full speed
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed);
    // Right motor backward with full speed
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speed);
  } else if (dir == LEFT) {
    // Left motor forward with full speed
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed);
    // Right motor backward with full speed
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed);
  } else if (dir == RIGHT) {
    // Left motor forward with full speed
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed);
    // Right motor backward with full speed
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speed);
  } else if (dir == STOP) {
    Serial.println("STOP");
    // Left motor stop
    analogWrite(ENA, 0);
    // Right motor stop
    analogWrite(ENB, 0);

    //if the ena doesn't work switch off all motor
    //digitalWrite(IN3, LOW);
  }
}
