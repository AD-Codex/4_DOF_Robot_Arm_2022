

void random_move( int value) {
  
  double angle2 =acos( ( 2*cos( 40 *3.1415/180) - 1) /2) * (180/3.1415) ;
  myservo.write( arm1_stnd - 40*77/90);
  myservo2.write( arm2_stnd - 81 + ( 180- 40 - angle2)*81/90 );
  myservo3.write( arm3_stnd + ( 90- angle2)*97/90 );
  myservo4.write(grip_stnd + 50);

  myservo5.write( 0);
  for ( int i=0; i<= value *10 +30; i=i+1) {
    myservo5.write( 0 + i);    
    delay(10);
  }
  myservo5.write( value *10 +30 );

  delay(1000);

  
  for ( int i=0; i<= value *10 +30; i=i+1) {
    myservo5.write( value *10 +30 - i);    
    delay(10);
  }

  myservo5.write( 0);

  delay(2000);

  
    
}
