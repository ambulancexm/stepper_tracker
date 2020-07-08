#define INTERVAL 10
#define SPEEDMOTOR 10

const int stepsPerRevolution = 360;
Stepper azimut(stepsPerRevolution, pinIN1, pinIN3, pinIN2, pinIN4);      // positif horaire négatif antihoraire
Stepper inclinaison(stepsPerRevolution, pinIN8, pinIN6, pinIN7, pinIN5); // positif horaire négatif antihoraire

void moveStepper(int ref1, int ref2, int interval, Stepper stepperMotor)
{
  int delta = (ref1 - ref2);
  int stp = stepsPerRevolution / 45;
  stepperMotor.setSpeed(SPEEDMOTOR);
  if (delta > interval)
  {
    stepperMotor.step(stp);
  }
  else
  {
    stepperMotor.step(-stp);
  }
}

void choixStepper(int choix)
{
  stepperMotor.setSpeed(SPEEDMOTOR);
  int stp = stepsPerRevolution / 45;
  switch (choix)
  {
  case HAUT:
    inclinaison.step(stp);
    break;
  case BAS:
    inclinaison.step(-stp);
    break;
  case GAUCHE:
    azimut.step(-stp);
    break;
  case DROIT:
    azimut.step(stp);
    break;
  case HAUTGAUCHE:
    inclinaison.step(stp);
    azimut.step(-stp);
    break;
  case HAUTDROIT:
    inclinaison.step(stp);
    azimut.step(stp);
    break;
  case BASGAUCHE:
    inclinaison.step(-stp);
    azimut.step(-stp);
    break;
  case BASDROIT:
    inclinaison.step(-stp);
    azimut.step(stp);
    break;
  }
}