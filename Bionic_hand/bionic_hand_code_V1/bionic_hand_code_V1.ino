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

int P1 = A1; //pushbutton1 attached to pin A1
int P2 = A2; //pushbutton2 attached to pin A2
int P3 = A3; //pushbutton3 attached to pin A3
int P4 = A4; //pushbutton4 attached to pin A4
int P5 = A5; //pushbutton5 attached to pin A5
int P6 = A0; //pushbutton6 attached to pin A0
int P7 = 10; //pushbutton7 attached to pin 10

int Bval1 = 0; //buttonvalue 1
int Bval2; //buttonvalue 2
int Bval3; //buttonvalue 3
int Bval4; //buttonvalue 4
int Bval5; //buttonvalue 5
int Bval6; //buttonvalue 6
int Bval7; //buttonvalue 7

int val1; //cashe value1
int val2; //cashe value2

int val3; //cashe value3
int val4; //cashe value4

int val5; //cashe value5
int val6; //cashe value6

int val7; //cashe value7
int val8; //cashe value8
int val9; //cashe value9


unsigned long previousMillis = 0;
long Time1 = 1000;
long Time2 = 2000; 
long Time3 = 3000;
long Time4 = 4000;
long Time5 = 5000;

long Time11 = 500;
long Time12 = 1000;
long Time13 = 1500;
long Time14 = 2000;
long Time15 = 2500;

int Counter = 0;            
int lastButtonState = 0; 

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
  Servo3.write(140); //startposition Servo3 (index finger servo)
  Servo4.write(44); //startposition Servo4 (middle finger servo)
  Servo5.write(140); //startposition Servo5 (ring finger servo)
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

  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
  pinMode(P3, INPUT_PULLUP);
  pinMode(P4, INPUT_PULLUP);
  pinMode(P5, INPUT_PULLUP);
  pinMode(P6, INPUT_PULLUP);
  pinMode(P7, INPUT_PULLUP);

  val1 = LOW;
  val2 = LOW;
  
  val3 = LOW;
  val4 = LOW;
  
  val5 = LOW;
  val6 = LOW;

  val7 = LOW;
  val8 = LOW;
  val9 = LOW;


  Serial.begin(9600);
}

void loop() 
{
  
  unsigned long currentMillis = millis();

  Bval1 = digitalRead(P1);
  Bval2 = digitalRead(P2);
  Bval3 = digitalRead(P3);
  Bval4 = digitalRead(P4);
  Bval5 = digitalRead(P5);
  Bval6 = digitalRead(P6);
  Bval7 = digitalRead(P7);

  if (Bval1 != lastButtonState) {
   if (Bval1== LOW) {
       Counter++;
     if(Counter == 5){ 
        Counter = 1;
        }
    } 
  }

 lastButtonState = Bval1;

   if(Counter == 1){
    ledState1 = HIGH;
    ledState2 = LOW;
   }

   if(Counter == 2){
    ledState1 = LOW;
    ledState2 = HIGH;
   }

   if(Counter == 3){
    ledState1 = HIGH;
    ledState2 = HIGH;
   }

   if(Counter == 4){
    ledState1 = LOW;
    ledState2 = LOW;
   }



//************************************************** PROGRAM 01 ***************************************************************
//smooth finger movement from index to little finger then thumb push pull servo then back from index to little finger


  if((Counter == 1) && (Bval7 == LOW))
  {
    previousMillis = currentMillis;  // Remember the time/start counting from 0

    ledState1 = HIGH;

    val1 = HIGH;
  }

  if((val1 == HIGH) && (currentMillis - previousMillis >= Time1) && (pos3 >= 30)) //closing index finger
  {
    pos3 -= increment;
    Servo3.write(pos3); // index finger
  }

  if((val1 == HIGH) && (currentMillis - previousMillis >= Time2) && (pos4 <= 180)) //closing middle finger
  {
    pos4 += increment;
    Servo4.write(pos4); // middle finger
  }

  if((val1 == HIGH) && (currentMillis - previousMillis >= Time3) && (pos5 >= 10)) //closing ring finger
  {
    pos5 -= increment;
    Servo5.write(pos5); // ring finger
  }

  if((val1 == HIGH) && (currentMillis - previousMillis >= Time4) && (pos6 <= 145)) //closing little finger
  {
    pos6 += increment;
    Servo6.write(pos6); // little finger
  }

  if((val1 == HIGH) && (currentMillis - previousMillis >= Time5) && (pos2 <= 180)) //closing thumb
  {
    pos2 += increment;
    Servo2.write(pos2); // thumb push pull

    if(pos2 >= 180)
    {
       previousMillis = currentMillis;  // Remember the time/start counting from 0
       val1 = LOW;
       val2 = HIGH;
    }
  }

  if((val2 == HIGH) && (currentMillis - previousMillis >= Time1) && (pos2 >= 0)) //opening thumb
  {
    pos2 -= increment;
    Servo2.write(pos2); // thumb push pull
  }

  if((val2 == HIGH) && (currentMillis - previousMillis >= Time2) && (pos3 <= 140)) //opening index finger
  {
    pos3 += increment;
    Servo3.write(pos3); // index finger
  }
  
  if((val2 == HIGH) && (currentMillis - previousMillis >= Time3) && (pos4 >= 44)) //opening middle finger
  {
    pos4 -= increment;
    Servo4.write(pos4); // middle finger
  }
  
  if((val2 == HIGH) && (currentMillis - previousMillis >= Time4) && (pos5 <= 140)) //opening ring finger
  
  {
    pos5 += increment;
    Servo5.write(pos5); // ring finger
  }

  if((val2 == HIGH) && (currentMillis - previousMillis >= Time5) && (pos6 >= 25)) //opening little finger
  {
    pos6 -= increment;
    Servo6.write(pos6); // little finger

    if(pos6 <= 25)
    {
       previousMillis = currentMillis;
       val1 = LOW;
       val2 = LOW;
       ledState1 = LOW;
    }
  }



//************************************************** PROGRAM 02 ***************************************************************
//Same program as PROGRAM 01 but not incremental (faster version of PROGRAM 01)


 if((Counter == 2) && (Bval7 == LOW))
  {
    previousMillis = currentMillis;  // Remember the time/start counting from 0

    ledState2 = HIGH;

    val3 = HIGH;
  }
  
  if((val3 == HIGH) && (currentMillis - previousMillis >= Time11))
  {
    pos3 = 30;
    Servo3.write(pos3); // index finger
  }

  if((val3 == HIGH) && (currentMillis - previousMillis >= Time12))
  {
    pos4 = 180;
    Servo4.write(pos4); // middle finger
  }

  if((val3 == HIGH) && (currentMillis - previousMillis >= Time13))
  {
    pos5 = 10;
    Servo5.write(pos5); // ring finger
  }

  if((val3 == HIGH) && (currentMillis - previousMillis >= Time14))
  {
    pos6 = 145;
    Servo6.write(pos6); // ring finger
  }

  if((val3 == HIGH) && (currentMillis - previousMillis >= Time15))
  {
    pos2 = 180;
    Servo2.write(pos2); // thumb push pull
    previousMillis = currentMillis;  // Remember the time/start counting from 0
    val3 = LOW;
    val4 = HIGH;
  }

  if((val4 == HIGH) && (currentMillis - previousMillis >= Time11))
  {
    pos2 = 0;
    Servo2.write(pos2); // thumb push pull
  }

  if((val4 == HIGH) && (currentMillis - previousMillis >= Time12))
  {
    pos3 = 140;
    Servo3.write(pos3); // index finger
  }

  if((val4 == HIGH) && (currentMillis - previousMillis >= Time13))
  {
    pos4 = 44;
    Servo4.write(pos4); // middle finger
  }

  if((val4 == HIGH) && (currentMillis - previousMillis >= Time14))
  {
    pos5 = 140;
    Servo5.write(pos5); // ring finger
  }

  if((val4 == HIGH) && (currentMillis - previousMillis >= Time15))
  {
    pos6 = 25;
    Servo6.write(pos6); // little finger
    val3 = LOW;
    val4 = LOW;
    ledState2 = LOW;
  }



//************************************************** PROGRAM 03 ***************************************************************
//closing little finger, ring finger and thumb leaving index inger and middle finger open


if((Counter == 3) && (Bval7 == LOW))
  {
    previousMillis = currentMillis;  // Remember the time/start counting from 0

    ledState1 = HIGH;
    ledState2 = HIGH;

    val5 = HIGH;
  }

if((val5 == HIGH) && (currentMillis - previousMillis >= Time1)) //closing ring finger, little finger and thumb
  {
    if(pos5 >= 10)
    {
    pos5 -= increment;
    Servo5.write(pos5); // ring finger closing
    }
    
    if(pos6 <= 145)
    {
    pos6 += increment;
    Servo6.write(pos6); // little finger closing
    }

    if(pos2 <= 180)
    {
    pos2 += increment;
    Servo2.write(pos2); // thumb push pull closing
    }
    
    if((pos2 >= 180) && (pos6 >= 145) && (pos5 <= 10))
    {
    previousMillis = currentMillis;  // Remember the time/start counting from 0
    val5 = LOW;
    val6 = HIGH;
    }
  }


if((val6 == HIGH) && (currentMillis - previousMillis >= Time5)) //closing ring finger, little finger and thumb
  {
    if(pos2 >= 0)
    {
    pos2 -= increment;
    Servo2.write(pos2); // thumb push pull closing
    }
    
    if(pos5 <= 140)
    {
    pos5 += increment;
    Servo5.write(pos5); // ring finger closing
    }
    
    if(pos6 >= 25)
    {
    pos6 -= increment;
    Servo6.write(pos6); // little finger closing
    }
    
    if((pos2 <= 0) && (pos5 >= 140) && (pos6 <= 25))
    {
     val5 = LOW;
     val6 = LOW;
    }
  }



//************************************************** PROGRAM 04 ***************************************************************
// all fingers close slowly, middle finger pops up ;-)


if((Counter == 4) && (Bval7 == LOW))
  {
    previousMillis = currentMillis;  // Remember the time/start counting from 0

    ledState1 = LOW;
    ledState2 = LOW;

    val7 = HIGH;
  }

if((val7 == HIGH) && (currentMillis - previousMillis >= Time1)) //closing ring finger, little finger and thumb
  {
    if(pos2 <= 180)
    {
    pos2 += increment;
    Servo2.write(pos2); // thumb push pull closing
    }

    if(pos3 >= 30)
    {
    pos3 -= increment;
    Servo3.write(pos3); // index finger
    }

    if(pos4 <= 180)
    {
    pos4 += increment;
    Servo4.write(pos4); // middle finger
    }

    if(pos5 >= 10)
    {
    pos5 -= increment;
    Servo5.write(pos5); // ring finger closing
    }
    
    if(pos6 <= 145)
    {
    pos6 += increment;
    Servo6.write(pos6); // little finger closing
    }
    
    if((pos2 >= 180) && (pos3 <= 30) && (pos4 >= 180) && (pos5 <= 10) && (pos6 >= 145))
    {
    previousMillis = currentMillis;  // Remember the time/start counting from 0
    val7 = LOW;
    val8 = HIGH;
    }
  }

if((val8 == HIGH) && (currentMillis - previousMillis >= Time1)) //opening middle finger rappidly
    {
    pos4 = 44;
    Servo4.write(pos4); //index finger
    previousMillis = currentMillis;  // Remember the time/start counting from 0
    val7 = LOW;
    val8 = LOW;
    val9 = HIGH;
    }

if ((val9 == HIGH) && (currentMillis - previousMillis >= Time2)) //opening all fingers
    {
    if(pos2 >= 0)
    {
    pos2 -= increment;
    Servo2.write(pos2); // thumb push pull closing
    }

    if(pos3 <= 140)
    {
    pos3 += increment;
    Servo3.write(pos3); // index finger
    }
    
    if(pos5 <= 140)
    {
    pos5 += increment;
    Servo5.write(pos5); // ring finger closing
    }
    
    if(pos6 >= 25)
    {
    pos6 -= increment;
    Servo6.write(pos6); // little finger closing
    }
    
    if((pos2 <= 0) && (pos3 >= 140) && (pos5 >= 140) && (pos6 <= 25))
    {
     val7 = LOW;
     val8 = LOW;
     val9 = LOW;
    }
  }
    




 
 
  /*Serial.print("button= ");
  Serial.print(Bval1);
  Serial.print(" , ");
  Serial.print("CMillis = ");
  Serial.print(currentMillis);
  Serial.print(" , ");
  Serial.print("PMillis = ");
  Serial.print(previousMillis);
  Serial.print(" , ");
  Serial.print("led1 = ");
  Serial.print(ledState1);
  Serial.print(" , ");
  Serial.print("led2 = ");
  Serial.print(ledState2);
  Serial.print(" , ");
  Serial.print("pos2= ");
  Serial.print(pos2);
  Serial.print(" , ");
  Serial.print("pos3= ");
  Serial.print(pos3);
  Serial.print(" , ");
  Serial.print("pos4= ");
  Serial.print(pos4);
  Serial.print(" , ");
  Serial.print("pos5= ");
  Serial.print(pos5);
  Serial.print(" , ");
  */Serial.print("pos6= ");
  Serial.println(pos6);

  digitalWrite(LED1, ledState1);
  digitalWrite(LED2, ledState2);
  
  // val1=analogRead(potpin1);
  // val1=map(val1, 0, 1000, 0, 180);
  // Myservo1.write(val1);


}
