#include <Stepper.h>
#include "configStepper.h"
#include "moyenne.h"

// for your motor
#define ORANGE A0
#define ROUGE A1
#define VERT A2
#define BLEU A3

#define pinIN1  8  // IN1 on the ULN2003 azimut stepper
#define pinIN2  9  // IN2 on the ULN2003 azimut stepper
#define pinIN3 10  // IN3 on the ULN2003 azimut stepper
#define pinIN4 11  // IN4 on the ULN2003 azimut stepper

#define pinIN5  3  // IN1 on the ULN2003 inclinaison stepper
#define pinIN6  4  // IN2 on the ULN2003 inclinaison stepper
#define pinIN7 5  // IN3 on the ULN2003 inclinaison stepper
#define pinIN8 6  // IN4 on the ULN2003 inclinaison stepper