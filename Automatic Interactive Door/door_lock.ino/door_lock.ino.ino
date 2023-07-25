#include<LiquidCrystal.h>
#include<Servo.h>
Servo myservo;
int pir=9,led=4;
int pos=0;
int pirout=0,BUZZER=7;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); //LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  pinMode(BUZZER,OUTPUT);
  myservo.attach(6);
  pinMode(led,OUTPUT);
 lcd.begin(16, 2); 
  pinMode(pir,INPUT);
  Serial.begin(9600);
}

void loop()
{
  pirout=digitalRead(pir);
  lcd.setCursor(0,0);           
  if(pirout==HIGH)
  {
  	lcd.print("Motion Detected");
    digitalWrite(BUZZER,HIGH);
    delay(1000);
    digitalWrite(BUZZER,LOW);
    digitalWrite(led,HIGH);
    Serial.print("Motion Detected\n");
    lcd.clear();
    lcd.print("Opening the door!");
    for(pos=0;pos<=180;pos++)
    {
      myservo.write(pos);
      delay(15);
    }
    lcd.clear();
    lcd.print("Get in!");
    delay(3000);
    lcd.clear();
    lcd.print("Relocking!");
    lcd.blink();
    digitalWrite(BUZZER,HIGH);
    delay(1000);
    digitalWrite(BUZZER,LOW);
    lcd.clear();
    lcd.print("Relocking!");
    lcd.blink();
    delay(1000);
    for(pos=180;pos>=0;pos--)
    {
      myservo.write(pos);
      delay(15);
    }
    delay(500);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Welcome!");
  }
  digitalWrite(led,LOW);
  delay(100);            
}
