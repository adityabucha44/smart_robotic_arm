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


const int button = A0;            // GPIO 8 for the button
int ledflag=0; 

int LED1 = 9; //LED1 attached to pin 9
int LED2 = 11; // LED2 attached to pin 11


int count;



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

  

  pinMode(LED1, OUTPUT); //set LED1 as OUTPUT
  pinMode(LED2, OUTPUT); //set LED2 as OUTPUT
  pinMode(button, INPUT_PULLUP);


  Serial.begin(9600);
  Serial.println("Welcome!");
  count=0;
  

}

/*void loop() 
{int state=digitalRead(A0);Serial.println(count);
if(state==HIGH){count++;closefist();}
if (count%2==0){openfist();}
else{closefist();}
 
}*/
void loop() {
  if (digitalRead(button)==HIGH){ // if button is pressed
    if (ledflag==0) {             // and the status flag is LOW
      ledflag=1;                  // make status flag HIGH
      closefist();    // and turn on the LED
      }                           // 
    else {                        // otherwise...
      ledflag=0;                  // make status flag LOW
      openfist();      // and turn off the LED
    }
  delay(500);                    // wait a sec for the 
  }                               // hardware to stabilize
} 

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
