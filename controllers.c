//Controllers.c
//This is used for handling the buttons for each contoller
//These functions are called in the main thread while loop for driver control.
//The joysticks are not handled the same way- just use joystick class
//#include "globals.c"

//Read controller 1 button values and react
void readController1Btn() {
	for(int i = 0; i < 12; i++) {
		controller1_buttons[i] = joy1Btn(i);
	}
}
//Read controller 2 button values and react
void readController2Btn() {
	for(int i = 0; i < 12; i++) {
		controller2_buttons[i] = joy2Btn(i);
	}
}

//This  is the main call, to clean up the main loop
void readControllers() {
	readController1Btn();
	readController2Btn();
}
