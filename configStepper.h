#define INTERVAL 10
#include <Stepper.h>

const int stepsPerRevolution = 360;

void moveStepper(int ref1, int ref2, int interval, Stepper stepperMotor){
  int delta = (analogRead(ORANGE)-analogRead(BLEU));
  if (delta > interval){
  int stp = stepsPerRevolution/45;
  stepperMotor.setSpeed(motorSpeed);
 
  stepperMotor.step(stp);
}
}