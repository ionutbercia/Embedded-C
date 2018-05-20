/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

// defines pins numbers
const int trigPin = 2;
const int echoPin = 12;
const int LedPin = 11;

// defines variables
volatile long duration;
volatile int distance;
volatile byte state = LOW;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(LedPin, OUTPUT);
attachInterrupt(digitalPinToInterrupt(trigPin),blink, CHANGE);
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
digitalWrite(LedPin, state);
}

void blink(){
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
if(distance < 10){
  state = HIGH;  
}else{
  state = LOW;
}
}


