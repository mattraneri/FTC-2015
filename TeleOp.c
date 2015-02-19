#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorBL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorLiftLeft, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorLiftRight, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servoCollection,      tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_2,    servoLatch,           tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servoArm,             tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "globals.c"
#include "controllers.c"


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

	threshold = 10;

	//Initialize joystick values
	for(int i = 0; i < 12; i++) {
		controller1_buttons[i] = false;
	}

	for(int i = 0; i < 12; i++) {
		controller2_buttons[i] = false;
	}
  return;
}


void LoadValues() {
	motor[motorFL] = ImotorFL;
	motor[motorFR] = ImotorFR;
	motor[motorBR] = ImotorBR;
	motor[motorBL] = ImotorBL;
	servo[servoLatch] = IservoLatch;
	servo[servoCollection] = IservoCollection;
	servo[servoArm] = IservoArm;
}

bool wasLastPressed = false;

void toggleLatch() {

}

void updateValues() {

	//Movement of the robot.
	if(abs(joystick.joy1_y1) > threshold) {
		ImotorFL = joystick.joy1_y1;
		ImotorBL = joystick.joy1_y1;
	}
	if(abs(joystick.joy1_y2) > threshold) {
		ImotorFR = joystick.joy1_y2;
		ImotorBR = joystick.joy1_y2;
	}

	if(controller1_buttons[0] && wasLastPressed ==  false) {
		wasLastPressed = true;
		toggleLatch();
	} else if(!controller1_buttons[0] && wasLastPressed == true) {
		wasLastPressed = false;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();

  waitForStart();   // wait for start of tele-op phase

  while (true) {
  	//Load controller values into global array for parsing
  	readControllers();

  	//Parse input retrieved from readControllers
  	updateValues();

  	//Load values to set robot into motion
  	LoadValues();
  }
}
