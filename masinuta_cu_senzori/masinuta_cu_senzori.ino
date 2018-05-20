#define enA 10
#define in1 9
#define in2 8
#define enB 6
#define in3 7
#define in4 5
#define trigPin1 4
#define echoPin1 3
#define trigPin2 13
#define echoPin2 12


void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
   pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  
  analogWrite(enA, 200); // Send PWM signal to L298N Enable pin
  analogWrite(enB, 200); // Send PWM signal to L298N Enable pin
long duration, distance;
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = (duration/2) / 29.1;



  if (distance >20 ) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
     digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }

  else{
 digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
     digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);


  }


  }
    //delay(20);
  

