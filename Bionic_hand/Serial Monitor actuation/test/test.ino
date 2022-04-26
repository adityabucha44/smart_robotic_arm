#include <Servo.h>

//min value = finger is straight
//max value = finger is bend

Servo Servo1; //thumb rotation servo (min = 110, max = 20)
Servo Servo2; //thumb push pull servo (min = 0, max = 180
Servo Servo3; //index finger servo (min = 140, max = 30)
Servo Servo4; //middle finger servo (min = 44, max = 180)
Servo Servo5; //ring finger servo (min = 140, max = 10)
Servo Servo6; //little finger servo (min = 25, max 145)
Servo Servo7; //all fingers push pull servo (min = 0, max = 180)

int increment = 1; //icrement value for the servo's
int pos1; //position Servo1
int pos2; //position Servo2
int pos3; //position Servo3
int pos4; //position Servo4
int pos5; //position Servo5
int pos6; //position Servo6
int pos7; //position Servo7

int LED1 = 9; //LED1 attached to pin 9
int LED2 = 11; // LED2 attached to pin 11
int ledState1; //state of LED1
int ledState2; //state of LED2






void setup() 
{
  Servo1.attach(2); //attach Servo1 to pin 2
  Servo2.attach(3); //attach Servo2 to pin 3
  Servo3.attach(4); //attach Servo3 to pin 4
  Servo4.attach(5); //attach Servo4 to pin 5
  Servo5.attach(6); //attach Servo5 to pin 6
  Servo6.attach(7); //attach Servo6 to pin 7
  Servo7.attach(8); //attach Servo7 to pin 8

  Servo1.write(110); //startposition Servo1 (thumb rotation servo)
  Servo2.write(0); //startposition Servo2 (thumb push pull servo)
  Servo3.write(180); //startposition Servo3 (index finger servo)
  Servo4.write(20); //startposition Servo4 (middle finger servo)
  Servo5.write(0); //startposition Servo5 (ring finger servo)
  Servo6.write(25); //startposition Servo6 (little finger servo)
  Servo7.write(0); //startposition Servo7 (all fingers push pull servo)

  pos1 = 110; //position Servo1
  pos2 = 0; //position Servo2
  pos3 = 140; //position Servo3
  pos4 = 44; //position Servo4
  pos5 = 140; //position Servo5
  pos6 = 25; //position Servo6
  pos7 = 0; //position Servo7

  pinMode(LED1, OUTPUT); //set LED1 as OUTPUT
  pinMode(LED2, OUTPUT); //set LED2 as OUTPUT


  Serial.begin(9600);
  Serial.println("Welcome!");

}

void loop() 
{
  if(Serial.available()>0){

    int inp=  Serial.parseInt();
    if(inp==2){
      closefist();
    }
  if (inp==1){
    openfist();
  }
  
  }
}
// one by one movement of fingers
void closefist(){
  Serial.println("Closing Fist");
  Servo1.write(20); //startposition Servo1 (thumb rotation servo)
  Servo2.write(180); //startposition Servo2 (thumb push pull servo)
  Servo3.write(60); //startposition Servo3 (index finger servo)
  Servo4.write(120); //startposition Servo4 (middle finger servo)
  Servo5.write(110); //startposition Servo5 (ring finger servo)
  Servo6.write(60); //startposition Servo6 (little finger servo)
  Servo7.write(180); //startposition Servo7 (all fingers push pull servo)
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);

}
void openfist(){
  Serial.println("open fist");
  Servo1.write(110); //startposition Servo1 (thumb rotation servo)
  Servo2.write(0); //startposition Servo2 (thumb push pull servo)
  Servo3.write(180); //startposition Servo3 (index finger servo)
  Servo4.write(30); //startposition Servo4 (middle finger servo)
  Servo5.write(0); //startposition Servo5 (ring finger servo)
  Servo6.write(25); //startposition Servo6 (little finger servo)
  Servo7.write(0); //startposition Servo7 (all fingers push pull servo)
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
}
// simultaneous movement of fingers

// void closefist(){
//   Serial.print("Closing Fist");
//   for(i=1;i<=180;i++){
  
  
//   Servo2.write(i); //max Servo2 (thumb push pull servo)180
//   if((140-i)>=30){
//     Servo3.write(140-i); //max Servo3 (index finger servo)30
//   }
  
//   Servo4.write(44+i); //max Servo4 (middle finger servo)180
//   if((140-i)>=10){
//     Servo5.write(140-i); //max Servo5 (ring finger servo)10

//   }
//   if ((25+i)<=145){
//     Servo6.write(25+i); //max Servo6 (little finger servo)145
    
//   }
  
  

// }
//   digitalWrite(LED1,HIGH);
//   digitalWrite(LED2,LOW);

// }
// void openfist(){
//   Serial.print("check2");
//   for(i=180;i>=0;i--){

//     Servo2.write(i); //startposition Servo2 (thumb push pull servo)
//     if()
//     Servo3.write(140); //startposition Servo3 (index finger servo)
//     Servo4.write(44); //startposition Servo4 (middle finger servo)
//     Servo5.write(140); //startposition Servo5 (ring finger servo)
//     Servo6.write(25); //startposition Servo6 (little finger servo)


//   }
  
  
//   digitalWrite(LED1,LOW);
//   digitalWrite(LED2,HIGH);
// }
