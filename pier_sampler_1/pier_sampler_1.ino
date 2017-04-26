//ARDUINO PIN ASSIGNMENT FOR SOLENOID CONTROLS
//assign digital pins for solenoids A,B,C,D
int sol_B = 2; 
int sol_C = 4;  
int sol_D = 3; 
int sol_A = 12; 

//initialize timer for intervals
unsigned long time_since_last_reset =0;

//set normal normal operation length in ms
int interval_one = 5000;

//set sampling operation length in ms
int interval_two = 8000;

//set fixative operation length in ms
int interval_three = 4000;

//debugging logic(irrelevant for operation)
boolean check_normal =true;
boolean check_sampling = true;
boolean check_fix = true;


void setup() {
  
//Initialize serial monitor for data display compatibility if required
Serial.begin(1200);
delay(2000);

//INITIALIZE PINS AS OUTPUTS
//set non sampling solenoids as outputs to system
pinMode(sol_A, OUTPUT);
pinMode(sol_B, OUTPUT);
pinMode(sol_D, OUTPUT);
pinMode(sol_C, OUTPUT);

//loop through and initialize solenoid pins 
for(int solX_Pin = 5; solX_Pin < 12; solX_Pin++)//solenoid pins are assigned from pin 5 to 11 
{
  pinMode(solX_Pin, OUTPUT);  //pins set as output 
}
}


//OPERATION LOOP
void loop() {

//loop to next solenoid at the end of each cycle  
for(int solX_Pin = 5; solX_Pin < 12 ; solX_Pin++){

//Check for looping operation of sampling solenoids   
Serial.println(solX_Pin);

//set up timing 
//get last reset time from millis function
time_since_last_reset = millis();

//normal operation
//while time elapsed is less than interval set, begin normal operation
while((millis()-time_since_last_reset)<interval_one){
 digitalWrite(sol_C, LOW);
 digitalWrite(sol_A, HIGH);
 digitalWrite(sol_B, HIGH);
 digitalWrite(sol_D, HIGH);
 Serial.println("normal");  //print normal to serial monitor
}
//exit loop after set time has elapsed

//check time again
time_since_last_reset = millis();

//while time elapsed is less than sampling interval, enter sampling mode
while((millis()-time_since_last_reset)<interval_two){
 digitalWrite(solX_Pin, HIGH);
 digitalWrite(sol_B, LOW);
 digitalWrite(sol_D, LOW);
 Serial.println("sampling");   //print sampling to serial monitor

}


time_since_last_reset = millis();
//enter fixative operation
while((millis()-time_since_last_reset)<interval_three){
 digitalWrite(sol_A, LOW);
  digitalWrite(sol_C, HIGH);
digitalWrite(solX_Pin, LOW);
Serial.println("fixative");
}
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
 
 
 
 


