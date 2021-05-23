#include "main.h"

void blue1(){
  indexerMove(127);
  flywheelMove(127);
  delay(550);
  // first goal
  baseMove(-29,1000);
  flywheelMove(0);
  delay(5);
  baseTurn(71,1000);
  delay(5);
  baseMove(-38.7,2000);
  delay(10);
  // first ball
  baseTurn(96, 1000);
  indexerMove(0);
  delay(5);
  baseMove(-22.8,1000);
  // second goal
  delay(5);
  baseTurn(-38,1000);
  delay(5);
  baseMove(62,2000);
  intakeMove(-127);
  // third goal
  baseMove(-32,1000);
  baseTurn(45, 1000);
  baseMove(-73, 3000);
  baseTurn(-132, 1000);
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
  baseMove(-29.5,1000);
  flywheelMove(0);
  delay(5);
  baseTurn(71,1000);
  delay(5);
  baseMove(-39,2000);
  delay(10);
  // first ball
  indexerMove(0);
  baseTurn(94, 1000);
  delay(5);
  baseMove(-22.8,1000);
  // second goal
  delay(5);
  baseTurn(-40,1000);
  delay(5);
  baseMove(62,2000);
  intakeMove(-127);
  // third goal
  baseMove(-32,1000);
  baseTurn(46, 1000);
  baseMove(-66, 3000);
  intakeMove(0);
  baseTurn(-139, 1000);
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


}
