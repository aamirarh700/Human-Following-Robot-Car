//Coded By TechLogy Hub 
// This code is for a OBSTACLE AVOIDING ROBOT

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

long cm, duration;
const int echoPin = 7;
const int trigPin = 6;

const int lm1 = 2;
const int lm2 = 3;
const int rm1 = 4;
const int rm2 = 5;

// Above is the motor driver pin connection. lm1, lm2, rm1 and
//rm2 are the digital input pins from arduino to the motor driver.

void setup()
{
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{

  // the distance ahead using an ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

// converting the time into a distance in Centimetre
  
   cm = duration*0.034/2;
 
  if(cm < 20)
  {
    stop_bot();
    delay(2000);
   
    go_back();
    delay(2000);
    
    stop_again();
    delay(1000);
   
    go_left();
    delay(1000);
  }
  
  else
  {
    go_straight();
    delay(1000);
  }
  
// For Serial Monitor
Serial.print("Distance:CM ");  
Serial.println(cm); 
  
}

//  Here are the functions that are used in the program

void go_straight()
{
lcd.setCursor(0,0);
lcd.print("FOLLOW HUMAN");
lcd.setCursor(0,1);
lcd.print("MOVING FORWARD");
  
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}
void stop_bot()
{
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print("SOMETHING AHEAD");
lcd.setCursor(0,1);
lcd.print("STOP!!");
  
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}
void go_back()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("TAKING REVERSE");
lcd.setCursor(0,1);
lcd.print(cm);
  
  digitalWrite(lm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,HIGH);
  digitalWrite(rm1,LOW);
} 

void stop_again()
{
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print("BREAK FOR TURN");
  
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}

void go_left()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("TURNING LEFT");
lcd.setCursor(0,1);
lcd.print(cm);
  
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}

void go_right()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("TURNING RIGHT");
lcd.setCursor(0,1);
lcd.print(cm);
  
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}
