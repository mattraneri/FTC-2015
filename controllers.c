//Controllers.c
//This is used for handling the buttons and joysticks for each contoller
//These functions are called in the main thread while loop for driver control.


//Read controller 1 button values and react
void readController1Btn() {

}

//Read controller 2 button values and react
void readController2Btn() {

}

//Read controller 1 joystick values and react
void readController1Joystick() {

}

//Read controller 2 joystick values and react
void readController2Joystick() {

}

//This  is the main call, to clean up the main loop
void readControllers() {
	readController1Btn();
	readController2Btn();
	readController1Joystick();
	readController2Joystick();
}
