/*
 ex380_moteur_pas_a_pas.ino
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include "config.h"



// initialize the stepper library on pins 8 through 11:
//Stepper myStepper(stepsPerRevolution, 10, 11, 9, 8);  // 11, 10, 9, 8  pas bon
//Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);  // Tourne dans le sens des aiguilles d'une montre
//Stepper myStepper(stepsPerRevolution, 9, 10, 11, 8);  // Tourne dans l'autre sens (sens trigonométrique), mais pas bien
//Stepper myStepper(stepsPerRevolution, 10, 11, 8, 9);  // Tourne dans le sens des aiguilles d'une montre
//Stepper myStepper(stepsPerRevolution, 11, 8, 9, 10);  // Tourne dans l'autre sens (sens trigonométrique), mais pas bien
//Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8); // Tourne dans le sens trigonométrique, bien

//Stepper myStepper(stepsPerRevolution, pinIN4, pinIN2, pinIN3, pinIN1); // Tourne dans le sens trigonométrique, bien
int stepCount = 0;  // number of steps the motor has taken

int etatButton = 0;
int pinButtonArret = 2;



int orientation[16][3] = {
  //{max, min, sens},
  //LIGNE 1
  {0, 0, false},
  {0, 1, HAUT},
  {0, 2, GAUCHE},
  {0, 3, HAUTGAUCHE},
  //LIGNE 2
  {1, 0, BAS},
  {1, 1, false},
  {1, 2, HAUTGAUCHE},
  {1, 3, DROITE},
  //LIGNE 3
  {2, 0, DROITE},
  {2, 1, BASDROITE},
  {2, 2, false},
  {2, 3, BAS},
  //LIGNE 4
  {3, 0, BASDROITE},
  {3, 1, GAUCHE},
  {3, 2, HAUT},
  {3, 3, false}

};

int minMax[2][2] = {{0, -1}, {1024, -1}};
int capteurSolaire[4] = {0, 0, 0, 0};
int solairePin[4] = {ORANGE, ROUGE, BLEU, VERT};

void raz(){
  //minMax[0][0]= -1;
  //minMax[1][0]= -1;
}

void recupValue() {
for (int i= 0; i < 4; i++) {
  capteurSolaire[i] = moyenne(analogRead(solairePin[i]));
}
}
void chercher()
{
  //recherche grandeur entre 4 capteur 
  int val[4] = {capteurSolaire[0], capteurSolaire[1], capteurSolaire[2], capteurSolaire[3]};

  for (int i = 0; i<4; i++){
    if (val[i] > minMax[0][0])
    {
      minMax[0][0] = val[i];
      minMax[0][1] = i;
    }
    if (val[i] < minMax[1][0])
    {
      minMax[1][0] = val[i];
      minMax[1][1] = i;
    }
  }

  // if index max et mini son 0 ou 1 = droite, 2 ou 3 = gauche
  // if index max et mini son 0 ou 2 = haut , 1 ou 3 = bas 
}

int RotationSens()
{
  //Calcul = indexMax * 4 + indexMin 
  int result = ((minMax[0][1] * 4) + minMax[1][1]);
  if ((minMax[0][1] - minMax[1][1]) > 10)
    return false;
  return orientation[result][2];
  
}

void setup() {
  Serial.begin(115200);
  pinMode(pinButtonArret,INPUT);
//============
// nothing to do inside the setup
} // setup

void loop() {
  recupValue();
  chercher();
  Serial.print("MAX : valeur -> ");
  Serial.print(minMax[0][0]);
  Serial.print(" Index -> ");
  Serial.println(minMax[0][1]);

  Serial.print("MIN : valeur -> ");
  Serial.print(minMax[1][0]);
  Serial.print(" Index -> ");
  Serial.println(minMax[1][1]);

if (digitalRead(pinButtonArret) == true)
  etatButton = !etatButton;

if (etatButton)
{
  choixStepper(RotationSens());  
}
raz();
} // loop
