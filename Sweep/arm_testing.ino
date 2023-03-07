




void arm1_test() {
  // vertical 113
  // horizontal 36
  // 90 degres = 77 step
  int lower_value = 70;
  int upper_value = 140;
  
  val = analogRead(potpin);
  val = map(val, 0, 4096, 0,180);
  Serial.println(val);
  
  if ( val >=lower_value && val <= upper_value) {
    myservo.write(val);
  }
  else if ( val < lower_value) {
    myservo.write(lower_value);
  }
  else if ( val > upper_value) {
    myservo.write(upper_value);
  }
  
  myservo2.write( arm2_stnd);
  myservo3.write( arm3_stnd  );
  
}



void arm2_test() {
  // vertical to vertical arm1 8
  // horizontal to vertical arm1 89
  // 90 degres = 81 step
  int lower_value = 0;
  int upper_value = 130;
  
  val = analogRead(potpin);
  val = map(val, 0, 4096, 0,180);
  Serial.println(val);
  
  if ( val >= lower_value && val <= upper_value ) {
    myservo2.write(val);
  }
  else if ( val < lower_value) {
    myservo2.write(lower_value);
  }
  else if ( val > upper_value) {
    myservo2.write(upper_value);
  }
  
  myservo.write( arm1_stnd);
  myservo3.write( arm3_stnd);
}



void arm3_test() {
  // paralell to arm 2 65
  // 90 degree = 97 step
  int lower_value = 0;
  int upper_value = 150;
  
  val = analogRead(potpin);
  val = map(val, 0, 4096, 0,180);
  Serial.println(val);
  
  if ( val >= lower_value && val <= upper_value ) {
    myservo3.write(val);
  }
  else if ( val < lower_value) {
    myservo2.write(lower_value);
  }
  else if ( val > upper_value) {
    myservo2.write(upper_value);
  }
  
  myservo.write( arm1_stnd);
  myservo2.write(116);
  
}



void griper_test() {
  // close 10
  // full open 70
  int lower_value = 10;
  int upper_value = 70;
  
  val = analogRead(potpin);
  val = map(val, 0, 4096, 0,180);
  Serial.println(val);
  
  if ( val >= lower_value && val <= upper_value) {
    myservo4.write(val);
  }
  if ( val < lower_value) {
    myservo4.write(lower_value);
  }
  if ( val > upper_value) {
    myservo4.write(upper_value);
  }
  
  myservo.write( arm1_stnd);
  myservo2.write(116);
  myservo3.write(97);
  
}



void base_test() {
  //155 ---> 65
  int lower_value =0;
  int upper_value = 180;

  double angle2 =acos( ( 2*cos( 20 *3.1415/180) - 1) /2) * (180/3.1415) ;
  myservo.write( arm1_stnd - 20*77/90);
  myservo2.write( arm2_stnd - 81 + ( 180- 20 - angle2)*81/90 );
  myservo3.write( arm3_stnd + ( 90- angle2)*97/90 );
  myservo4.write(grip_stnd + 50);
  
  val = analogRead(potpin);
  val = map(val, 0, 4096, 0,180);
  Serial.println(val);

  if ( val >= lower_value && val <= upper_value) {
    myservo5.write(val);
  }
  if ( val < lower_value) {
    myservo5.write(lower_value);
  }
  if ( val > upper_value) {
    myservo5.write(upper_value);
  }
  
}



void push_test() {
  //155 ---> 65
  int lower_value =0;
  int upper_value = 180;
  
  val = analogRead(potpin);
  val = map(val, 0, 4096, 0,180);
  Serial.println(val);

  if ( val >= lower_value && val <= upper_value) {
    myservo6.write(val);
  }
  if ( val < lower_value) {
    myservo6.write(lower_value);
  }
  if ( val > upper_value) {
    myservo6.write(upper_value);
  }
  
}
