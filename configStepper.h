#define INTERVAL 10
#include <Stepper.h>

const int stepsPerRevolution = 500;

void moveStepper(int ref1, int ref2, int interval, Stepper stepperMotor){
  int delta = (analogRead(ORANGE)-analogRead(BLEU));
  if (delta > interval){
  int stp = stepsPerRevolution;
  stepperMotor.setSpeed(motorSpeed);
  if (delta <5){
    stp = stp/16;
  }else{
    stp =stp /8;
  }
  stepperMotor.step(stp);
}
}