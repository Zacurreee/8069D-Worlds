#include "main.h"
#include "functions.hpp"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "aloy kinda sus");
	} else {
		pros::lcd::clear_line(2);
	}
	}

//motor declaration
void initialize() {
	Motor FL (FLmotor, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor BL (BLmotor, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor FR (FRmotor, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor BR (BRmotor, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
  Motor Lintake (Lmotor, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor Rintake (Rmotor, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor Btmindexer (Btmmotor, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES);
	Motor Topindexer (Topmotor, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
	ADIAnalogIn Tsensor (Topsensor);
	ADIAnalogIn Bsensor (Botsensor);
	Btmindexer.set_brake_mode(E_MOTOR_BRAKE_HOLD);

	Imu imu(Imusensor);
  imu.reset();
}




void disabled() {}


void competition_initialize() {}


//auton
void autonomous() {
	int autonNum = 1;
		switch (autonNum){
			case 1: blue1(); break;
			case 2: blue2(); break;
			case 3: red1(); break;
			case 4: red2(); break;

}
}

	//driver control
void opcontrol()
{


	//base motor//
	Motor FL (FLmotor);
	Motor BL (BLmotor);
	Motor FR (FRmotor);
	Motor BR (BRmotor);
	//intakes//
	Motor Lintake(Lmotor);
	Motor Rintake(Rmotor);
	//indexer flywheel//
	Motor Topindexer (Topmotor);
	Motor Btmindexer (Btmmotor);
	//Linesensor
	ADIAnalogIn Tsensor (Topsensor);
  ADIAnalogIn Bsensor (Botsensor);

	bool isTank = true;
	bool isindexer = true;


	Controller master (E_CONTROLLER_MASTER);
	while (true)
	{
		double left, right;
		if(master.get_digital_new_press(DIGITAL_Y)) isTank = !isTank;
		if(isTank)
		{
			// Tank Drive
			left = master.get_analog(ANALOG_LEFT_Y);
			right = master.get_analog(ANALOG_RIGHT_Y);
		}
		else
		{
			// Arcade Drive
			double power = master.get_analog(ANALOG_LEFT_Y);
			printf("Encoder values : %.2f, %.2f\n", BL.get_position()*INCH_PER_DEG, BR.get_position()*INCH_PER_DEG);
			double turn = master.get_analog(ANALOG_RIGHT_X);
			left = power + turn;
			right = power - turn;

		}
		FL.move(left);
		BL.move(left);
		FR.move(right);
		BR.move(right);


		{
			if(master.get_digital(DIGITAL_R1))
			{
			Btmindexer.move(127);
			}
			else if (master.get_digital(DIGITAL_R2) || master.get_digital(DIGITAL_L2))
			{
			if(master.get_digital(DIGITAL_L2))
			{
			Topindexer.move(-127);
			Btmindexer.move(-127);
			}
			else
			{
			Btmindexer.move(-127);
			}
			}
			else if(master.get_digital(DIGITAL_L1))
			{
			Btmindexer.move(115);
			Topindexer.move(127);
			}
			else if(master.get_digital(DIGITAL_B))
			{
			Topindexer.move(100);
			Btmindexer.move(127);
			}
			else
			{
			Btmindexer.move(15);
			Topindexer.move(0);
			}
			}



		//Intakes/Indexer

		Rintake.move((master.get_digital(DIGITAL_R1) - master.get_digital(DIGITAL_R2))* 127);
		Lintake.move((master.get_digital(DIGITAL_R1) - master.get_digital(DIGITAL_R2))* 127);





		// Debugging
	// master.print(2, 0, "%.2f\n", (BL.get_position() - BR.get_position()) * INCH_PER_DEG / 2 / TO_RAD / BASE_WIDTH );
   // master.print(2, 0, "%.2f\n", BL.get_position()*INCH_PER_DEG, BR.get_position()*INCH_PER_DEG);
		delay(5);


		    delay(5);

	}
 }
