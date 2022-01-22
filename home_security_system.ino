#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); 
int pirled1 = 3;
int pirled2 = 13;                
int pirsensor = 11;              
int state = LOW;             
int val = 0;    
int pirbuzzer = 12;
int gasled1 = 7;
int gasled2 = 6;
int gasbuzzer = 8;
int gasA0 = A5;
int sensorThres = 350;
const int flameled1=2;
const int flameled2=5; 
const int flamepin=A2;
const int flamebuzzer=4;
const int threshold=200;
int flamesensvalue=0;
void setup() {

  Serial.println(" logging time completed!");
  pinMode(pirled1, OUTPUT);  
  pinMode(pirled2, OUTPUT);
  pinMode(pirsensor, INPUT);   
  pinMode(pirbuzzer, OUTPUT);
  pinMode(gasled1, OUTPUT);
  pinMode(gasled2, OUTPUT);
  pinMode(gasbuzzer, OUTPUT);
  pinMode(gasA0, INPUT);
  pinMode(flamepin, INPUT);
  pinMode(flameled1, OUTPUT);
  pinMode(flameled2, OUTPUT);
  pinMode(flamebuzzer, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(1000);
  }
void loop(){
    flamesensvalue=analogRead(flamepin); 
if (flamesensvalue<=threshold) {
    digitalWrite(flameled1,HIGH);
    digitalWrite(flameled2,HIGH); 
    tone(flamebuzzer,300);
    delay(100); 
    mySerial.println("OK");
    delay(1000);
    mySerial.println("ATH");
    delay(1000);
    mySerial.println("AT+CMGF=1");
    delay(1000);
    mySerial.println("AT+CMGS=\"+919837456073\"\r");
    delay(1000);
    mySerial.println("Fire Detected!");
    delay(1000);
    mySerial.println((char)26);
    delay(1000);
}
else{
  digitalWrite(flameled1,HIGH);
  digitalWrite(flameled2,LOW);
  noTone(flamebuzzer);
}
if ( digitalRead(pirsensor) == HIGH){  
    digitalWrite(pirbuzzer, HIGH);
    digitalWrite(pirled1, HIGH); 
    digitalWrite(pirled2, HIGH);
    mySerial.println("OK");
    delay(1000);
    mySerial.println("ATH");
    delay(1000);
    mySerial.println("AT+CMGF=1");
    delay(1000);
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");//XX IS YOUR MOBILE NUMBER WHRE GSM MODULE SEND SMS
    delay(1000);
    mySerial.println("Motion Detected!");
    delay(1000);
    mySerial.println((char)26);
    delay(1000);

  }
    if ( digitalRead(pirsensor) == LOW) 
{
  digitalWrite(pirbuzzer, LOW);
  digitalWrite(pirled1, HIGH);
  digitalWrite(pirled2, LOW);

delay(1000);
}

int analogSensor = analogRead(gasA0);
Serial.print("Pin A0: ");
Serial.println(analogSensor);
if (analogSensor > sensorThres)
{
     digitalWrite(gasled2, HIGH);
     digitalWrite(gasled1, HIGH);
     digitalWrite(gasbuzzer,HIGH);
     mySerial.println("OK");
     delay(1000);
     mySerial.println("ATH");
     delay(1000);
     mySerial.println("AT+CMGF=1");
     delay(1000);
     mySerial.println("AT+CMGS=\"+919837456073\"\r");
     delay(1000);
     mySerial.println("Gas Leakage alert");
     delay(1000);
     mySerial.println((char)26);
     delay(1000);
    
}
else
 {
    digitalWrite(gasled2, LOW);
    digitalWrite(gasled1, HIGH);
    digitalWrite(gasbuzzer,LOW);
  }

}
