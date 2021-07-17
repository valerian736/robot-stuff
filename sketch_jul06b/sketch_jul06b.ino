#include <Servo.h>

int servoX = 4;
int servoY = 2;

int x;
int y;

int vrx = A0;
int vry = A1;
int but = 3;

Servo servox;
Servo servoy;

void setup() {
  Serial.begin(9600);
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  servox.attach(servoX);
  servoy.attach(servoY);
  servox.write(100);
  servoy.write(90);

}

void loop() {
  x = analogRead(vrx);
  x = map(x, 2, 1008, 0, 180);
  y = analogRead(vry);
  y = map(y, 2, 1008, 0, 180);
  servox.write(x);
  servoy.write(y);
  //Serial.print("x: ");
  //Serial.print(x);
  //Serial.print("y");
  //Serial.println(y);
  
  
}
