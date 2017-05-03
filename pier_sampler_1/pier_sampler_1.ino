/******************************************************************************************
Code for pier water sampler, controlled by ARDUINO MEGA
Scripps Institute of Oceanography
Bowman Lab
Note: Refer to operation diagram for solenoid orientation
******************************************************************************************/

//-------------------------------------------------------------------------------------------------------------------------------------//
/*ARDUINO PIN ASSIGNMENT FOR SOLENOID CONTROLS:
In the following block, the control pins for the solenoids are declared. Digital pins on the arduino are used.*/
//-------------------------------------------------------------------------------------------------------------------------------------//
//******************************************************************************************//
//assign digital pins for solenoids A,B,C,D
int sol_A = 12; //assign digital pin number 12 for solenoid A
int sol_B = 2; //assign digital pin number 2 for solenoid B
int sol_C = 4; //assign digital pin number 4 for solenoid C
int sol_D = 3; //assign digital pin number 3for solenoid D
//******************************************************************************************//

//-------------------------------------------------------------------------------------------------------------------------------------//
/*Initialize and set up time keeping mechanism:
In the following block the mechanism for specifying and maintaining time intervals is initialized. 
This is done by first initializing the timer to 0, followed by specifying user-inputted intervals for normal operation, sampling and fixative operation.*/
//-------------------------------------------------------------------------------------------------------------------------------------//
//******************************************************************************************//
unsigned long time_since_last_reset =0; //initialize timer to 0
int normal_op = 5000;//set normal normal operation length in milliseconds
int sampling = 5000;//set sampling operation length in milliseconds
int fixative_op = 5000;//set fixative operation length in milliseconds
//******************************************************************************************//

//debugging logic(irrelevant for operation)
boolean check_normal =true;
boolean check_sampling = true;
boolean check_fix = true;


//-------------------------------------------------------------------------------------------------------------------------------------//
/*The void setup block is used to initialize code that only needs to be ran once. 
For this purpose, all solenoid control pins are set as OUTPUTS to the system.
Furthermore, a serial monitor is initialized to display the state of operation that the system is in.*/
//-------------------------------------------------------------------------------------------------------------------------------------//
//******************************************************************************************//
void setup() {
Serial.begin(1200);//initialize serial monitor
delay(4000);// add delay before starting system

//INITIALIZE PINS AS OUTPUTS
//set non sampling solenoids as outputs to system
pinMode(sol_A, OUTPUT);
pinMode(sol_B, OUTPUT);
pinMode(sol_D, OUTPUT);
pinMode(sol_C, OUTPUT);

//A for loop is used to assign pins 5-11 of the arduino and set them as outputs for the 7 sampling solenoids.
for(int solX_Pin = 5; solX_Pin < 12; solX_Pin++)//solenoid pins are assigned from pin 5 to 11 
  {
pinMode(solX_Pin, OUTPUT);  //pins set as output 
  }
            }
//******************************************************************************************//

//-------------------------------------------------------------------------------------------------------------------------------------//
/*The void loop block runs the code in it continously and is used to specify the states of the solenoids in the various operation modes.
//--------------------------------------------------------------------------------------------------------------------------------------//
******************************************************************************************/
void loop() {  
//A for loop is initialized to makes sure that the sampling solenoids are looped through every cycle.
for(int solX_Pin = 5; solX_Pin < 12 ; solX_Pin++){  

  /*The millis function is one specified in the arduino library and that returns the number of milliseconds elapsed since it was previously called.
The time since reset is initialized here*/
 time_since_last_reset = millis();
//******************************************************************************************//

//-------------------------------------------------------------------------------------------------------------------------------------//
//Normal Operation Block:
//In the following block solenoids A,B and D are turned on and every other solenoid is turned off for a user specified time interval.
//-------------------------------------------------------------------------------------------------------------------------------------//
//******************************************************************************************//
while((millis()-time_since_last_reset)<normal_op){  //a while loop is used to set the condition of running in normal operation until the user specified time interval has elapsed.
digitalWrite(sol_C, LOW);    //solenoid C is turned off
digitalWrite(sol_A, HIGH);  //solenoid A is turned on
digitalWrite(sol_B, HIGH);  //solenoid B is turned on
digitalWrite(sol_D, HIGH);  //solenoid D is turned on
//digitalWrite(solX_Pin, LOW); //the sampling pins are turned off
Serial.println("normal");  //The state "normal" is shown on the serial monitor.
}
//******************************************************************************************//



//The time is checked again to make sure that the normal operation interval has passed and initialized for sampling.
time_since_last_reset = millis();

//-------------------------------------------------------------------------------------------------------------------------------------//
//Sampling Operation Block:
//In the following block solenoids B and D are turned off and all the inflow is passed through the sampling solenoid 
//until the user defined sampling interval has passed.
//-------------------------------------------------------------------------------------------------------------------------------------//
//******************************************************************************************//
while((millis()-time_since_last_reset)<sampling){
digitalWrite(solX_Pin, HIGH);  //sampling solenoid is turned on
digitalWrite(sol_B, LOW);  //solenoid B is turned off
digitalWrite(sol_D, LOW);  //solenoid D is turned off
Serial.println("sampling");   //The state "sampling" is shown on the serial monitor.
}
//******************************************************************************************//


//The time is checked again to make sure that the normal operation interval has passed and initialized for fixative operation.
time_since_last_reset = millis();

//-------------------------------------------------------------------------------------------------------------------------------------//
//Fizative Operation Block:
//In the following block all solenoids except sampling and C are turned off for a user defined time interval.
//-------------------------------------------------------------------------------------------------------------------------------------//
//******************************************************************************************//
//enter fixative operation
while((millis()-time_since_last_reset)<fixative_op){
//digitalWrite(solX_Pin, HIGH);  //sampling solenoid is maintained on
digitalWrite(sol_A, LOW);  //inflow valve is turned off
digitalWrite(sol_C, HIGH);  //fixative valve C is opened.
Serial.println("fixative"); //The state "fixative" is shown on the serial monitor
}
//******************************************************************************************//
digitalWrite(solX_Pin, LOW);
//delay(120000);
//time_since_last_reset = millis();
//interval 
}
}

//---------------------------- MISC----------------------------
 
//DEBUGGING FUNCTIONS
// if(check_normal)
 //{
//check A
// int check1_A = digitalRead(sol_A);
//Serial.println(check1_A);
//Serial.println("Sol_A during normal:");
  
  //check B
 /* int check1_B = digitalRead(sol_B);
 Serial.println(check1_B);
 Serial.println("Sol_B during normal:");
 
 //check C
 
  int check1_C = digitalRead(sol_C);
 Serial.println(check1_C);
 Serial.println("Sol_C during normal:");
 
 */
 //check D
  // int check1_D = digitalRead(sol_D);
 //Serial.println(check1_D);
 //Serial.println("Sol_D during normal:");
 
/// int check1_X = digitalRead(solX_Pin);
 //Serial.println(check1_X);
 //Serial.println("Sol_X during normal:"); 
 
 
 //sampling
 
 
//debugging

//if(check_sampling){
//check X
 //int check2_X = digitalRead(solX_Pin);
 //Serial.println(check2_X);
 //Serial.println("Sol_X during Sampling:"); 

  //debugging

 //check A
// int check2_A = digitalRead(sol_A);
 //Serial.println(check2_A);
 //Serial.println("Sol_A during sampling:");
/* 
 
 //check B
  int check2_B = digitalRead(sol_B);
 Serial.println(check2_B);
 Serial.println("Sol_B during sampling:");
 
  //check C
 
  int check2_C = digitalRead(sol_C);
 Serial.println(check2_C);
 Serial.println("Sol_C during sampling:");
 
 */
 //check D
  /* int check2_D = digitalRead(sol_D);
 Serial.println(check2_D);
 Serial.println("Sol_D during sampling:");
 */
 
 
 ///fixative
 
 
 //debugging
 
 
 //check A
// int check3_A = digitalRead(sol_A);
 //Serial.println(check3_A);
 //Serial.println("Sol_A during fix:");
 
 /*
 //check B
  int check3_B = digitalRead(sol_B);
 Serial.println(check3_B);
 Serial.println("Sol_B during fix:");
 
 //check C
 
  int check3_C = digitalRead(sol_C);
 Serial.println(check3_C);
 Serial.println("Sol_C during fix:");
 */
 /*
 //check D
   int check3_D = digitalRead(sol_D);
 Serial.println(check3_D);
 Serial.println("Sol_D during fix:");
 */
 
 
 
 


