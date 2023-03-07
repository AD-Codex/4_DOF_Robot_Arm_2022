




void move_forward() {
  count = count +1;
  int arm1_start = arm1_stnd - count/40;
  int arm2_start = 8;
  int arm3_start = arm3_stnd - count/60;

  double angle2 =acos( ( 2*cos( 0 *3.1415/180) - 1) /2) * (180/3.1415) ;
  myservo.write( arm1_start - 0*77/90);
  myservo2.write( arm2_stnd - 81 + ( 180- 0 - angle2)*81/90 );
  myservo3.write( arm3_start + ( 90- angle2)*97/90 );
 
//  delay(500);

  for ( int i=0; i<=40; i=i+1 ) {
    double angle2 =acos( ( 2*cos( i *3.1415/180) - 1) /2) * (180/3.1415) ;
    myservo.write(arm1_start - i*77/90);
    myservo2.write(arm2_stnd - 81 + ( 180- i - angle2)*81/90 );
    myservo3.write( arm3_start + ( 90- angle2)*97/90 );
    delay(15);
  }

//  double angle2 =acos( ( 2*cos( 40 *3.1415/180) - 1) /2) * (180/3.1415) ;
//  myservo.write(arm1_start - 40*77/90);
//  myservo2.write(8 + ( 180- 40 - angle2)*81/90 );
//  myservo3.write( arm3_start + ( 90- angle2)*97/90 );

//  delay(500);
  
}

void move_back() {
  count = count +1;
  int arm1_start = arm1_stnd - count/40;
  int arm2_start = 8;
  int arm3_start = arm3_stnd - count/60;

  double angle2 =acos( ( 2*cos( 40 *3.1415/180) - 1) /2) * (180/3.1415) ;
  myservo.write(arm1_start - 40*77/90);
  myservo2.write(arm2_stnd - 81 + 1 + ( 180- 40 - angle2)*81/90 );
  myservo3.write( arm3_start + ( 90- angle2)*97/90 );

//  delay(500);

  for ( int i=40; i>=0; i=i-1 ) {
    double angle2 =acos( ( 2*cos( i *3.1415/180) - 1) /2) * (180/3.1415) ;
    myservo.write(arm1_start - i*77/90);
    myservo2.write(arm2_stnd - 81 + ( 180- i - angle2)*81/90 );
    myservo3.write( arm3_start + ( 90- angle2)*97/90 );
    delay(15);
  }
  
//  double angle2 = acos( ( 2*cos( 0 *3.1415/180) - 1) /2) * (180/3.1415) ;
//  myservo.write( arm1_start - 0*77/90);
//  myservo2.write( 8 + ( 180- 0 - angle2)*81/90 );
//  myservo3.write( arm3_start + ( 90- angle2)*97/90 );
    
//  delay(500);

}
