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

void setup() {
  Serial.begin(115200);
//============
// nothing to do inside the setup
} // setup

void loop() {
Stepper azimutHoraire(stepsPerRevolution, pinIN1, pinIN3, pinIN2, pinIN4); // Tourne dans le sens des aiguilles d'une montre, bien
Stepper azimutAnti(stepsPerRevolution, pinIN4, pinIN2, pinIN3, pinIN1); // Tourne dans le sens des aiguilles inverse d'une montre, bien

Stepper inclinaisonHoraire(stepsPerRevolution, pinIN8, pinIN6, pinIN7, pinIN5); // Tourne dans le sens des aiguilles d'une montre, bien
Stepper inclinaisonAnti(stepsPerRevolution, pinIN5, pinIN6, pinIN7, pinIN8); // Tourne dans le sens des aiguilles inverse d'une montre, bien
//===========
// read the sensor value:
// int sensorReading = analogRead(A0);
// map it to a range from 0 to 100:
// int motorSpeed = map(sensorReading, 0, 1023, 0, 100);

 Serial.print("ORANGE->");
  Serial.println(analogRead(ORANGE));
  Serial.print("ROUGE->");
  Serial.println(analogRead(ROUGE));
  Serial.print("VERT->");
  Serial.println(analogRead(VERT));
  Serial.print("BLEU->");
  Serial.println(analogRead(BLEU));
  Serial.println("----------");
  delay(1000);

// int motorSpeed = 10;

// set the motor speed:
// if (motorSpeed > 0) {
//   inclinaisonAnti2.setSpeed(motorSpeed);
//   myStepper.setSpeed(motorSpeed);
//   // step 1/16 of a revolution:
//   myStepper2.step(stepsPerRevolution / 16);
//   myStepper.step(stepsPerRevolution / 16);
//   }
moveStepper(ORANGE,BLEU,10,azimutHoraire);

// int orange_bleu = (analogRead(ORANGE)-analogRead(BLEU));
// if (orange_bleu > 10){
//   int stp = stepsPerRevolution;
//   azimutHoraire.setSpeed(motorSpeed);
//   azimutHoraire.step(stp/45);
// }

// if (orange_bleu < 10){
//   int stp = stepsPerRevolution;
//   azimutHoraire.setSpeed(motorSpeed);
//   azimutHoraire.step(-stp/45);
// }


} // loop
