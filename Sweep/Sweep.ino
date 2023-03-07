
#include <ESP32Servo.h>
#include <math.h>

Servo myservo;  // servo arm 1
Servo myservo2; // servo arm 2
Servo myservo3; // servo arm 3
Servo myservo4; // servo griper
Servo myservo5; // servo base
Servo myservo6; // push servo
// 16 servo objects can be created on the ESP32

int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
int servoPin = 27;
int servoPin2 = 26;
int servoPin3 = 12;
int servoPin4 = 13;
int servoPin5 = 14;
int servoPin6 = 32;

int potpin =39;

int IRsensor = 15;

int count =0;

int arm1_stnd = 108;
int arm2_stnd = 89;
int arm3_stnd = 69;
int base_stnd = 10;
int grip_stnd = 20;
int max_value;

int val;

int count_1 = 0;
int count_2 = 0;
int count_3 = 0;
int count_4 = 0;
int count_5 = 0;
int count_6 = 0;
int count_7 = 0;
int count_8 = 0;
int count_9 = 0;
int count_10 = 0;
int myArray[40];

void setup() {
  Serial.begin(9600);
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
  
	myservo.attach(servoPin); // attaches the servo on pin 18 to the servo object
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);
  myservo4.attach(servoPin4);
  myservo5.attach(servoPin5);
  myservo6.attach(servoPin6);
  
  pinMode( LED_BUILTIN, OUTPUT);
  pinMode( IRsensor, INPUT);
}


void station_1() {
  double angle2 =acos( ( 2*cos( 0 *3.1415/180) - 1) /2) * (180/3.1415) ;
  myservo.write( arm1_stnd - 0*77/90);
  myservo2.write( arm2_stnd - 81 + ( 180- 0 - angle2)*81/90 );
  myservo3.write( arm3_stnd + ( 90- angle2)*97/90 );
  myservo4.write(grip_stnd);
  myservo5.write(base_stnd);
}

void station_2() {  
  for ( int i=0; i<=60; i=i+1) {
    myservo5.write( base_stnd + i);
    delay(15);
  }
  myservo4.write(grip_stnd + 50);
  
  for ( int i=0; i<=40; i=i+1 ) {
    double angle2 =acos( ( 2*cos( i *3.1415/180) - 1) /2) * (180/3.1415) ;
    myservo.write(arm1_stnd - i*77/90);
    myservo2.write( arm2_stnd - 81 + ( 180- i - angle2)*81/90 );
    myservo3.write( arm3_stnd + ( 90- angle2)*97/90 );
    delay(15);
  }

  
  double angle2 =acos( ( 2*cos( 40 *3.1415/180) - 1) /2) * (180/3.1415) ;
  myservo.write( arm1_stnd - 40*77/90);
  myservo2.write( arm2_stnd - 81 + ( 180- 40 - angle2)*81/90 );
  myservo3.write( arm3_stnd + ( 90- angle2)*97/90 );
  myservo4.write(grip_stnd + 50);
  myservo5.write(base_stnd + 60);
}




void moveBy(){
  val = analogRead(potpin);
  val = map(val, 0, 4096, 0,180);
  Serial.println(val);
  myservo4.write(val);

  double angle2 =acos( ( 2*cos( val *3.1415/180) - 1) /2) * (180/3.1415) ;
  Serial.print(113 - val*77/90  );
  Serial.print("-------------------------------------");
  Serial.println( 8 + ( 180 - val - angle2)*81/90 );

    myservo.write(113 - val*77/90);
    myservo2.write(8 + ( 180- val - angle2)*81/90 );
    myservo3.write( 65 + ( 90- angle2)*97/90 );
    
}

void move() {
  count = count +1;
  int arm1_start = arm1_stnd - count/7;
  int arm2_start = 8;
  int arm3_start = arm3_stnd + count/6 ;

  myservo.write(arm1_start);
  myservo2.write(116);
  myservo4.write(20);
  
  for ( int i=0; i<= 50; i=i+1) {
    myservo4.write(i+20);
    delay(15);
  }
  myservo4.write(70);
  
  delay(500);

  for ( int i=0; i<=40; i=i+1 ) {
    double angle2 =acos( ( 2*cos( i *3.1415/180) - 1) /2) * (180/3.1415) ;
    myservo.write(arm1_start - i*77/90);
    myservo2.write(8 + 1 + ( 180- i - angle2)*81/90 );
    myservo3.write( arm3_start + ( 90- angle2)*97/90 );
    delay(15);
  }

//  myservo.write(79);
//  myservo2.write(67);
//  myservo3.write(83);

  myservo4.write(70);
  for ( int i=0; i<= 50; i=i+1) {
    myservo4.write(70-i);
    delay(15);
  }
  myservo4.write(20);

  delay(500);

  for ( int i=40; i>=0; i=i-1 ) {
    double angle2 =acos( ( 2*cos( i *3.1415/180) - 1) /2) * (180/3.1415) ;
    myservo.write(arm1_start - i*77/90);
    myservo2.write(8 + 1 + ( 180- i - angle2)*81/90 );
    myservo3.write( arm3_start + ( 90- angle2)*97/90 );
    delay(15);
  }
    
  delay(1000);
}




void run() {

  max_value = 87;

  myservo4.write( grip_stnd);  
  
  move_forward();
  
  for ( int i=0; i<= 50; i=i+1) {
    myservo4.write( grip_stnd +i);
    delay(10);
  }
  myservo4.write( grip_stnd +50);
//  delay(500);

  move_back();

  myservo5.write( base_stnd);
  for ( int i=0; i<=max_value; i=i+1) {
    myservo5.write( base_stnd + i);
    myservo6.write(180 - i*90/max_value);    
    delay(10);
  }
  myservo5.write( base_stnd + max_value);

  move_forward();

  for ( int i=0; i<= 50; i=i+1) {
    myservo4.write( grip_stnd + 50 - i);
    delay(10);
  }
  myservo4.write( grip_stnd);
//  delay(500);

  move_back();

  for ( int i=0; i<=max_value; i=i+1) {
    myservo5.write( base_stnd +max_value - i);
    myservo6.write(90 + i*90/max_value);    
    delay(10);
  }
  myservo5.write( base_stnd);
  
  myservo4.write( grip_stnd);
  myservo3.write( 65);
  delay(15);
  myservo3.write( 35);
  delay(15);
  myservo3.write( 0);
//  delay(500);
  
}



void loop() {

  Serial.println("---------------Options----------");

  while (Serial.available() == 0) {
  }

  int menuChoice = Serial.parseInt();
  
  myservo.write(arm1_stnd);
  myservo2.write(116);
  myservo3.write(arm3_stnd);
  myservo4.write(grip_stnd);
  myservo5.write(base_stnd);

  delay(1000); 
  
  if ( menuChoice == 1) {
    while(1) {
      arm1_test();
    }
  }
  else if ( menuChoice == 2) {
    while(1) {
      arm2_test();
    }
  }
  else if ( menuChoice == 3) {
    while(1) {
      arm3_test();
    }
  }
  else if ( menuChoice == 4) {
    while(1) {
      griper_test();
    }
  }
  else if ( menuChoice == 5) {
    while(1) {
      base_test();
    }
  }
  else if ( menuChoice == 6) {
    while(1) {
      push_test();
    }
  }
  else if ( menuChoice == 7) {
    while(1) {
      station_1();      
    }
  }
  else if ( menuChoice == 8) {
    station_2();
    while(1) {      
    }    
  }
  else if ( menuChoice == 9) {
    Serial.println("arm 1 reading");

    while(Serial.available() > 0){
        byte dumpByte = Serial.read();
    }

    while (Serial.available() == 0) {
    }
    int arm_1_value = Serial.parseInt();
    arm1_stnd = arm_1_value;  
    
    random_number();
    for ( int i=0; i<30; i=i+1 ) {
      Serial.println( myArray[i]);
      
      int sensorRead = digitalRead ( IRsensor);  
      if ( sensorRead == 0) {
        digitalWrite( LED_BUILTIN, HIGH);
        random_move( myArray[i]);
      }
      else {
        i=i-1;
      }
    }

    
  }
  else if ( menuChoice == 0) {
    
    Serial.println("arm 1 reading");

    while(Serial.available() > 0){
        byte dumpByte = Serial.read();
    }

    while (Serial.available() == 0) {
    }
    int arm_1_value = Serial.parseInt();
    arm1_stnd = arm_1_value;    
    
//    double angle2 =acos( ( 2*cos( 0 *3.1415/180) - 1) /2) * (180/3.1415) ;
//    myservo.write( arm1_start - 0*77/90);
//    myservo2.write( 8 + ( 180- 0 - angle2)*81/90);
//    myservo3.write( arm3_start + ( 90- angle2)*97/90);
//    myservo4.write( grip_stnd);
    
    while(1) {
      int sensorRead = digitalRead ( IRsensor);  
      if ( sensorRead == 0) {
        digitalWrite( LED_BUILTIN, HIGH);
        run();
      }
    }
  }
  
///////// stationary////////////
//  myservo.write(83);//////////
//  myservo2.write(87);/////////
//  myservo3.write(0);//////////
////////////////////////////////

}
