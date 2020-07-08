#define INTERVAL 10
#define SPEEDMOTOR 10

#define HAUT 10
#define BAS 11
#define GAUCHE 12
#define DROITE 13
#define HAUTGAUCHE 14
#define HAUTDROITE 15
#define BASGAUCHE 16
#define BASDROITE 17

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
  case DROITE:
    azimut.step(stp);
    break;
  case HAUTGAUCHE:
    inclinaison.step(stp);
    azimut.step(-stp);
    break;
  case HAUTDROITE:
    inclinaison.step(stp);
    azimut.step(stp);
    break;
  case BASGAUCHE:
    inclinaison.step(-stp);
    azimut.step(-stp);
    break;
  case BASDROITE:
    inclinaison.step(-stp);
    azimut.step(stp);
    break;
  }
}