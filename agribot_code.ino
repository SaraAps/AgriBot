#include <Servo.h>
#define PUMP_PIN 2 // Water Pump Pin


int moisturePin = 1;

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;

int motor3pin1 = 6; // Define pin for Motor 3
int motor3pin2 = 7;

int motor4pin1 = 8; // Define pin for Motor 4
int motor4pin2 = 9;

Servo seedsServo; 
Servo soilServo;


Servo shovelServo;

int seedServoPIN = 10;  
int soilServoPIN = 11;
int shovelServoPIN = 13; 

int pos=0;
int poss=0;


void setup() {
    Serial.begin(9600); 
    pinMode(motor1pin1, OUTPUT);// Setup for Motor 1
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor2pin1, OUTPUT);// Setup for Motor 2
    pinMode(motor2pin2, OUTPUT);
    pinMode(motor3pin1, OUTPUT); // Setup for Motor 3
    pinMode(motor3pin2, OUTPUT);
    pinMode(motor4pin1, OUTPUT); // Setup for Motor 4
    pinMode(motor4pin2, OUTPUT);
    seedsServo.attach(10);
    soilServo.attach(11);
    shovelServo.attach(13);
    pinMode(PUMP_PIN, OUTPUT); // Set pin as OUTPUT
    pinMode(PUMP_PIN, LOW);

}
void pravo(){
    digitalWrite(motor1pin1, HIGH);// Move Motor 1 forward
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);// Move Motor 2 backward
    digitalWrite(motor2pin2, HIGH);
    digitalWrite(motor3pin1, LOW); // Move Motor 3 backward
    digitalWrite(motor3pin2, HIGH);
    digitalWrite(motor4pin1, HIGH); // Move Motor 4 forward
    digitalWrite(motor4pin2, LOW);
}
void levo(){
   digitalWrite(motor2pin1, LOW);// Move Motor 2 backward
   digitalWrite(motor2pin2, HIGH);
   digitalWrite(motor3pin1, LOW); // Move Motor 3 backward
   digitalWrite(motor3pin2, HIGH);
}
void stop() {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, LOW);
    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, LOW);
}


// void navodni(){
//   digitalWrite(PUMP_PIN, HIGH); 
//   Serial.println("The Water Pump is ON!");
//   delay(3000); 
//   digitalWrite(PUMP_PIN, LOW); 
//   Serial.println("The Water Pump is OFF!");
//   delay(3000); 
// }

void moisture(){
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(moisturePin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");

  if (moisture_percentage < 50) {
    digitalWrite(pumpPin, HIGH); // Turn on the water pump
  } else {
    digitalWrite(pumpPin, LOW); // Turn off the water pump
  }
    
  delay(1000);
}


void loop() {
  pravo();
  delay(3000);
  stop();
  delay(3000);
  levo();
  delay(2155);
  stop();
  pravo();
  delay(3000);

  moisture();

  //Seeds
  for (pos = 0; pos <= 45; pos += 1) { 
    seedsServo.write(pos);            
    delay(8);                       
  }
  for (pos = 45; pos >= 0; pos -= 1) { 
    seedsServo.write(pos);              
    delay(8);                      
  }

  //Soil
  for (poss = 0; pos <= 90; pos += 1) { 
    soilServo.write(pos);             
    delay(70);                      
  }
  for (poss = 90; pos >= 0; pos -= 1) { 
    soilServo.write(pos);             
    delay(30);                       
  }
  //Digg
  for (pos = 0; pos <= 90; pos += 1) { 
    shovelServo.write(pos);    
    delay(50);                      
  }
  for (pos = 90; pos >= 0; pos -= 1) { 
    shovelServo.write(pos); 
    delay(30);                       
  }  

 // Move all motors backward
    digitalWrite(motor1pin1, LOW);// Move Motor 1 backward
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH); // Move Motor 2 forward
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor3pin1, HIGH); // Move Motor 3 forward
    digitalWrite(motor3pin2, LOW);
    digitalWrite(motor4pin1, LOW); // Move Motor 4 backward
    digitalWrite(motor4pin2, HIGH);
