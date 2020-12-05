#include<Servo.h>

int in1= 6;
int in2= 7;  
int solenoidPin1=3; 
int solenoidPin2=8;
int solenoidPin3=12; 
int watlevelval1=0;
int watlevelpin1=A5;
int watlevelval2=0;
int watlevelpin2=A4;
int watlevelval3=0;
int watlevelpin3=A3;
Servo servo1;
Servo servo2;

void setup() 
{
  Serial.begin(9600);
  pinMode(solenoidPin1,OUTPUT);
  pinMode(watlevelpin1,INPUT);
  pinMode(solenoidPin1,OUTPUT);
  pinMode(solenoidPin2, OUTPUT);
  pinMode(watlevelpin2,INPUT);
   pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    servo1.attach(5);
    servo2.attach(9);
    servo1.write(0);
    servo2.write(0);
    delay(2000);
               
}
 
void loop() {
  
  watlevelval1= analogRead(watlevelpin1);
  if(watlevelval1>300)
  {
    Serial.println("water level has reached the point");

  digitalWrite(solenoidPin1, HIGH);    //Switch Solenoid ON
     delay(10000);  
    
  }
 else if (watlevelval1<300)
 {
  Serial.println("water level has not reached the point");
    digitalWrite(solenoidPin1, LOW);     //Switch Solenoid OFF
  delay(1000); 
  
 }
 watlevelval2= analogRead(watlevelpin2);
  if(watlevelval2>300)
  {
    Serial.println("water level has reached the point");
     digitalWrite(solenoidPin1,LOW);
     delay(1000);
    digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);
     servo1.write(90);
     delay(3000);
     servo1.write(0);
     delay(5000);
     digitalWrite(in1,LOW);
     digitalWrite(in2,LOW);
     delay(1000);
  digitalWrite(solenoidPin2, HIGH);    //Switch Solenoid ON
     delay(10000);  
    
  }
 else if (watlevelval2<300 )
 {
  Serial.println("water level has not reached the point");
   digitalWrite(in1,LOW);
     digitalWrite(in2,LOW);
    digitalWrite(solenoidPin2, LOW);     //Switch Solenoid OFF
  delay(1000); 
  
 }
 watlevelval3= analogRead(watlevelpin3);
  if(watlevelval3>300)
  {
    Serial.println("water level has reached the point");
     digitalWrite(solenoidPin2,LOW);
     delay(1000);
     servo2.write(90);
     delay(3000);
     servo2.write(0);
     delay(5000);
  digitalWrite(solenoidPin3, HIGH);    //Switch Solenoid ON
     delay(10000);  
    
  }
 else if (watlevelval2<300 )
 {
  Serial.println("water level has not reached the point");
    digitalWrite(solenoidPin3, LOW);     //Switch Solenoid OFF
  delay(1000); 
  
 }
}
