#include <Arduino.h>

#define JOY_X 33
#define JOY_Y 2
#define JOY_Z 32
#define BUT 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(JOY_Z, INPUT_PULLUP);
  pinMode(BUT, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("%d\t%d\t%d\t%d\n", analogRead(JOY_X), analogRead(JOY_Y), digitalRead(JOY_Z), digitalRead(BUT));
  delay(500);
}