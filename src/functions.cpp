#include "main.h"
#include "functions.hpp"

Motor FL (FLmotor);
Motor FR (FRmotor);
Motor BL (BLmotor);
Motor BR (BRmotor);

Motor Lintake(Lmotor);
Motor Rintake(Rmotor);
Motor Topindexer (Topmotor);
Motor Btmindexer (Btmmotor);

ADIAnalogIn Tsensor (Topsensor);
ADIAnalogIn Bsensor (Botsensor);


//kappa
double abscap(double value, double cap) {
  if(value > cap) return cap;
  else if(value < -cap) return -cap;
  else return value;
}



//base PID
void baseMove(double targL, double targR, double kP, double kD, double cutoff) {
  //reset position
  FL.tare_position();
  FR.tare_position();
  BL.tare_position();
  BR.tare_position();

  //Convesion rate
  targL /= INCH_PER_DEG;
  targR /= INCH_PER_DEG;


  double errorL = targL - BL.get_position(), errorR = targR - BR.get_position();
  double prevErrorL = errorL, prevErrorR = errorR;
  double powerL = 0, powerR = 0;
	double startTime = millis();

// cutoff to ensure code runs for onyl a period of time
  while((fabs(errorL) > DISTANCE_LEEWAY || fabs(errorR) > DISTANCE_LEEWAY) && millis() - startTime < cutoff) {
		errorL = targL - BL.get_position();
		errorR = targR - BR.get_position();
// declaring the Derivative in PID
    double derivativeL = errorL - prevErrorL;
    double derivativeR = errorR - prevErrorR;
// Letting the code know that the next previous error is the error now
    prevErrorL = errorL;
    prevErrorR = errorR;
// letting the robot know how much the target power is
    double targetPowerL = errorL * kP + derivativeL * kD;
    double targetPowerR = errorR * kP + derivativeR * kD;

// setting the motor to speed up at a certain interval
    double deltaPowerL = targetPowerL - powerL;
    double deltaPowerR = targetPowerR - powerR;
// power cap for the variable deltapower
    powerL += abscap(deltaPowerL, RAMPING_POWER);
    powerR += abscap(deltaPowerR, RAMPING_POWER);
// power cap for the variable power
    powerL = abscap(powerL, MAX_POWER);
    powerR = abscap(powerR, MAX_POWER);
// set motors
    FL.move(powerL);
    BL.move(powerL);
    FR.move(powerR);
		BR.move(powerR);

// Debugging
    Controller master(E_CONTROLLER_MASTER);
   // printf ("Encoder values : %.2f, %.2f\n", BL.get_position()*INCH_PER_DEG, BR.get_position()*INCH_PER_DEG);
    printf ("Encoder values: %.2f\n", (BL.get_position() - BR.get_position())*INCH_PER_DEG / 2 / TO_RAD/ BASE_WIDTH);
		delay(5);
	}
  printf("cutoff");
}


// function overload
void baseMove(double dis, double kP, double kD, double cutoff) {
  baseMove(dis, dis, kP, kD, cutoff);
}

void baseMove(double dis, double cutoff) {
  baseMove(dis, DEFAULT_KP, DEFAULT_KD, cutoff);
}

void timerBase(double l, double r, double cutoff){
  FL.move(l);
  BL.move(l);
  FR.move(r);
  BR.move(r);
}
void baseTurn(double angle, double kP, double kD, double cutoff) {
  double arc = angle * TO_RAD * BASE_WIDTH;
  baseMove(arc, -arc, kP, kD, cutoff);
}

void baseTurn(double angle, double cutoff) {
  baseTurn(angle, TURN_KP, TURN_KD, cutoff);
}


void flywheelMove(double speed){
  Topindexer.move(speed);
}

void intakeMove(double speed){
  Lintake.move(speed);
  Rintake.move(speed);
}


void indexerMove(double speed){
  Btmindexer.move(speed);
}
