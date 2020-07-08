#define INTERVAL 10


const int stepsPerRevolution = 360;

void moveStepper(int ref1, int ref2, int interval, Stepper stepperMotor){
  int delta = (ref1-ref2);
  if (delta > interval){
  int stp = stepsPerRevolution/45;
  stepperMotor.setSpeed(motorSpeed);
 
  stepperMotor.step(stp);
}
}