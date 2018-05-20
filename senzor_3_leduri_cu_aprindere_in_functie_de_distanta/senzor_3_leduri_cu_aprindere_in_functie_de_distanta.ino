#define trigPin 7
#define echoPin 6
#define led1 8
#define led2 9
#define led3 10

int sound = 250;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
 
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 

  if (distance >20 && distance <40 ) {
    digitalWrite(led1, HIGH);
   
}
  else {
    digitalWrite(led1,LOW);
  }
 
  if (distance >=10 && distance <=20) {
      digitalWrite(led2, HIGH);
      sound = 270;
} 
  else {
    digitalWrite(led2, LOW);
  }

  if (distance < 10) {
    digitalWrite(led3, HIGH);
    sound = 290;
}
  else {
    digitalWrite(led3,LOW);
  }

 
  if (distance > 40 || distance <= 0){
    Serial.println("Out of range");
    
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
   
   
  }
  delay(500);
}
