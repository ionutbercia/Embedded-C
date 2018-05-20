#define enA 9
#define in1 6
#define in2 7




void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void loop() {
  
  analogWrite(enA, 200); // Send PWM signal to L298N Enable pin

 
  
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    //delay(20);
  
}
