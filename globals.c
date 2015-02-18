//Globals.c
//This file contains global values for things like motor position and joystick values
//Controller values are stored globally so they can be accessed easily without making calls
//to the joystick class.

static bool controller1_buttons[12];
static bool controller2_buttons[12];

static int threshold;

static int ImotorFL;
static int ImotorBL;
static int ImotorFR;
static int ImotorBR;
static int IservoCollection;
static int IservoLatch;
static int IservoArm;
