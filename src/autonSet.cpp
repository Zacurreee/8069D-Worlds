#include "main.h"

void blue1(){
  indexerMove(127);
  flywheelMove(127);
  delay(550);
  // first goal
  baseMove(-31,1000);
  flywheelMove(0);
  delay(5);
  baseTurn(65,1000);
  delay(5);
  baseMove(-38,2000);
  baseMove(1.5,1000);
  delay(10);
  // first ball
  baseTurn(92, 1000);
  indexerMove(0);
  delay(5);
  baseMove(-23,1000);
  // second goal
  delay(5);
  baseTurn(-44,1000);
  delay(5);
  baseMove(62,2000);
  intakeMove(-127);
  // third goal
  baseMove(-30,1000);
  baseTurn(43, 1000);
  baseMove(-73, 3000);
  baseTurn(-134, 1000);
  baseMove(33, 1000);
  intakeMove(-60);
  indexerMove(127);
  flywheelMove(127);
  delay(500);
  flywheelMove(0);
  indexerMove(0);
  // fourth goal
}

void red1(){
  indexerMove(127);
  flywheelMove(127);
  delay(550);
  // first goal
  baseMove(-30,1000);
  flywheelMove(0);
  delay(5);
  baseTurn(67,1000);
  delay(5);
  baseMove(-37.5,2000);
  delay(10);
  // first ball
  indexerMove(0);
  baseTurn(93, 1000);
  delay(5);
  baseMove(-23,1000);
  // second goal
  delay(5);
  baseTurn(-43,1000);
  delay(5);
  baseMove(62,2000);
  intakeMove(-127);
  // third goal
  baseMove(-32,1000);
  baseTurn(46, 1000);
  baseMove(-72, 3000);
  intakeMove(0);
  baseTurn(-141, 1000);
  baseMove(32, 1000);
  intakeMove(-127);
  indexerMove(127);
  flywheelMove(127);
  delay(500);
  flywheelMove(0);
  indexerMove(0);
  // fourth goal
}
void blue2(){
}

void red2(){
  timerBase(115, 127, 100);
  delay(700);
  intakeMove(-127);
  baseMove(-29, 1000);
  delay(10);
  baseTurn(-52, 1000);
  // first goal
  indexerMove(127);
  baseMove(-32, 1000);
  delay(10);
  baseTurn(88, 1000);
  indexerMove(0);
  baseMove(-23, 1000);
  // timerBase();
  // baseMove();
  // flywheelMove(127);
  // indexerMove(127);
  // delay(700);
  // flywheelMove(0);
  // indexerMove(0);
  // baseMove();
  // intakeMove(127);
  // indexerMove(127);
  // delay(100);
  // intakeMove(0);
  // baseTurn();
  // baseMove();
  // flywheelMove(127);
  // delay(550);
  // flywheelMove(0);
  // indexereMove(0);
  // baseMove();
  // intakeMove(127);
  // indexerMove(127);
  // delay(100);
  // indexerMove(0);
  // baseTurn();
  // baseMove();
  // baseTurn();
  // timerBase();
  // intakeMove(-120);
  // baseTurn();
  //indexerMove(-127);

}
