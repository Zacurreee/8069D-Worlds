#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#define DISTANCE_LEEWAY 5
#define MAX_POWER 100
#define RAMPING_POWER 10

#define DEFAULT_KP 0.83
#define DEFAULT_KD 0.2
#define TURN_KP 0.65
#define TURN_KD 0.3

#define INCH_PER_DEG 0.0353563596126047
#define BASE_WIDTH 7.4683412361978
#define TO_RAD  0.0174532925199432957692369076849

void baseMove(double targL, double targR, double kP, double kD, double cutoff);
void baseMove(double dis, double kP, double kD, double cutoff);
void baseMove(double dis, double cutoff);
void timerBase(double l, double r, double cutoff);
void baseTurn(double angle, double kP, double kD, double cutoff);
void baseTurn(double angle, double cutoff);

void flywheelMove(double speed);
void intakeMove(double speed);
// void indexerMove(void * ignore);
void indexerMove(double speed);
#endif
