String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int direction=00;
int counter=-1;
String left_speed ;
String left_direction ;
String right_speed ;
String right_direction ;
String step_or_dc ;
int left_1=5;
int left_2=6;

int right_1=9;
int right_2=10;
// Stepper
int step_dir = 2;
int step_step = 3;

int step_interval = 5;
String step_level;
String up_or_down;
int counter_length = 9;
 
int stepper_neg_enable = 12;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  pinMode(left_1, OUTPUT);  //left1;5
  pinMode(left_2, OUTPUT);  //left2;6
  pinMode(right_1, OUTPUT);  //right1; 9
  pinMode(right_2, OUTPUT);  //right2; 10
  pinMode(step_dir, OUTPUT);
  pinMode(step_step, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(stepper_neg_enable, OUTPUT);
  
  digitalWrite(stepper_neg_enable,HIGH);
  digitalWrite(11,HIGH);
  
  analogWrite(right_2, 0);
  analogWrite(left_2, 0);
  analogWrite(right_1, 0);
  analogWrite(left_1, 0);
  
  stringComplete = false;
  //inputString = "X102F102F";
  // or imputString = "X100U0000";
}

void loop() {
  /*working variables*/
  if (stringComplete == true) {
     step_or_dc = inputString.substring(7,8) ;
     if (step_or_dc == "F" or step_or_dc == "R" ){
       left_speed = inputString.substring(0,3) ;
       left_direction = inputString.substring(3,4) ;
       right_speed = inputString.substring(4,7) ;
       right_direction = inputString.substring(7,8) ;
       if (left_direction == "F") {analogWrite(left_1, left_speed.toInt());analogWrite(left_2, 0);}
       else if (left_direction == "R"){analogWrite(left_2, left_speed.toInt());analogWrite(left_1, 0);}
       
       if (right_direction == "F") {analogWrite(right_1, right_speed.toInt());analogWrite(right_2, 0);}
       else if (right_direction == "R"){analogWrite(right_2, right_speed.toInt());analogWrite(right_1, 0); }
  	stringComplete = false;
         inputString="" ;
     }
     else if (step_or_dc == "1") {
       digitalWrite(stepper_neg_enable, LOW);
       step_level = inputString.substring(0,3) ;
       up_or_down = inputString.substring(3,4) ;
       if (up_or_down == "U") {step_up(step_level.toInt());}
       else if (up_or_down == "D") {step_down(step_level.toInt());}
       stringComplete = false;
       inputString="" ;       
       
     }
     else if (step_or_dc == "0") {digitalWrite(stepper_neg_enable, HIGH);}
    }

  
}



/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // Expected format is X100F100R
    // add it to the inputString:
    inputString += inChar;
    if (inChar == 'X') {counter = -1; inputString="" ;}
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    counter++;
    if (counter == counter_length) {
     stringComplete = true;
     counter = -1;
     //Serial.print(inputString);
   }
  }
}

void step_up(int level){
 digitalWrite(step_dir,LOW);
 for (int i=0; i<level; i++) {
   digitalWrite(step_step,HIGH);
   delayMicroseconds(5000);
   digitalWrite(step_step,LOW);
   delayMicroseconds(5000);
  
  } 
}

void step_down(int level){
 digitalWrite(step_dir,HIGH);
 for (int i=0; i<level; i++) {
   digitalWrite(step_step,HIGH);
   delayMicroseconds(5000);
   digitalWrite(step_step,LOW);
   delayMicroseconds(5000);
  
  } 
}


