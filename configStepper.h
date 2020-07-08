#define INTERVAL 10
#define SPEEDMOTOR 10


const int stepsPerRevolution = 360;

void moveStepper(int ref1, int ref2, int interval, Stepper stepperMotor){
  int delta = (ref1-ref2);
  int stp = stepsPerRevolution/45;
  stepperMotor.setSpeed(SPEEDMOTOR);
  if (delta > interval){
    stepperMotor.step(stp);
  } else {
    stepperMotor.step(-stp);
  }
}