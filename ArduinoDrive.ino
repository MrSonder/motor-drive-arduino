String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int direction=00;
int counter=0;
int left_en=6;
int left_1=7;
int left_2=8;
int right_en=9;
int right_1=10;
int right_2=11;
int left_fast=200;
int left_slow=150;
int right_fast=200;
int right_slow=150;
int normal_speed=175;
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(20);


  pinMode(left_en, OUTPUT);  //left enable;6
  pinMode(left_1, OUTPUT);  //left1;7
  pinMode(left_2, OUTPUT);  //left2;8
  pinMode(right_en, OUTPUT);  //right enable;9
  pinMode(right_1, OUTPUT);  //10;;r
  pinMode(right_2, OUTPUT);  //11;;R
  analogWrite(left_en, 0);
  analogWrite(right_en, 0);
  digitalWrite(right_2, LOW);
  digitalWrite(left_2, LOW);
  digitalWrite(right_1, HIGH);
  digitalWrite(left_1, HIGH);

}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    counter=0;
    
    Serial.println(inputString);
    // clear the string:


   
    direction=inputString.toInt();
    
    switch (direction) {
     case 11:{
  analogWrite(left_en, normal_speed);
  analogWrite(right_en, normal_speed);
      break;
    }
    case 10:{//left wheel should turn.
  analogWrite(left_en, left_fast);
  analogWrite(right_en, right_slow);
      break;
    }
    case 01:{//right wheel should turn.
  analogWrite(left_en, left_slow);
  analogWrite(right_en, right_fast);
      break;
    }
    case 00:{//error-stop!
  analogWrite(left_en, 0);
  analogWrite(right_en, 0);
    
      break;
    }
    default:{//error-stop!
  analogWrite(left_en, 0);
  analogWrite(right_en, 0);
      break;
    }

  }}
  delay(100);
  inputString = "";
  stringComplete = false;


  
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
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    counter++;
    if (counter == 2) {
     stringComplete = true;}
  }
}
