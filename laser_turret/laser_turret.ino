#include <Servo.h>

int servoX = 4;
int servoY = 2;

int x;
int y;

int vrx = A0;
int vry = A1;
int but = 3;

int count = 0;
int angle = 0;
int val = LOW;
Servo servox;
Servo servoy;

void setup() {
  
  Serial.begin(9600);
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  pinMode(but, INPUT);
  servox.attach(servoX);
  servoy.attach(servoY);
  servox.write(100);
  servoy.write(100);
  digitalWrite(but, HIGH);

}

void loop() {
  val = digitalRead(but);
  
  if (val == LOW) {        
      count = 1;
    }
   else
   {
      count = 0; 
   }

   switch(count)
   {
      case 0:
          x = analogRead(vrx);
          x = map(x, 2, 1008, 0, 180);
          y = analogRead(vry);
          y = map(y, 2, 1008, 180, 0);
  
          servox.write(x);
          servoy.write(y);
          break;

      case 1:
          for (angle = 0; angle <= 180; angle += 30) {
              servox.write(angle);
              delay(150);
             }
          // And back from 180 to 0 degrees:
          for (angle = 180; angle >= 0; angle -= 30) {
            servox.write(angle);
            delay(150);
          }        
          break;  
   }
    


  Serial.println(val);
  Serial.print("counts ");
  Serial.println(count);
}
