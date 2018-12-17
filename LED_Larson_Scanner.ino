/*
* Larson Scanner
* Uses the six Power Width Modulation ports {3,5,6,9,10,11} on an Arduino Uno 
* to create a simple six LED Larson Scanner. Connect these six ports in order 
* though 220 Ohm resisters to the Anode leg of the LED's.  Connect Cathode leg 
* of LED's to GND port.
* 
* Change cycleWaitTime to speed up or slow down the scan rate. Larger is slower.
* 
* Created by
* petcasdev@gmail.com
*/



const int ledCount = 6; //Number of leds
const int ledPins[6] = {3,5,6,9,10,11};
const int cycleWaitTime = 75;   //the delay in milliseconds between shift
const int ledOff = 0;
const int ledLow = 30;
const int ledMedium = 110;
const int ledHigh = 255;


void setup() {

  //Initialize led's to off
  for(int i=0;i<ledCount;i++){   
    pinMode(ledPins[i],OUTPUT);    
    analogWrite(ledPins[i], 0);
  }  
}

void loop() {

  //scan to Right
  for (int i = 1; i < ledCount + 2; i++){
    
    if (i > 2 && i < 9){
      analogWrite(ledPins[i-3], ledOff);
    }
    if (i > 1 && i < 8){
      analogWrite(ledPins[i-2], ledLow);
    }
    if (i > 0 && i < 7){
      analogWrite(ledPins[i-1], ledMedium);
    }
    if (i > -1 && i < 6){
      analogWrite(ledPins[i], ledHigh);
    }
    if (i>5){
      analogWrite(ledPins[5], ledHigh);
    }
    delay(cycleWaitTime);
  }

  //scan to Left
  for (int i = ledCount + 1; i > 0; i--){

    if (i > 2 && i < 9){
      analogWrite(ledPins[i-3], ledHigh);
    }
    if (i > 1 && i < 8){
      analogWrite(ledPins[i-2], ledMedium);
    }
    if (i > 0 && i < 7){
      analogWrite(ledPins[i-1], ledLow);
    }
    if (i > -1 && i < 6){
      analogWrite(ledPins[i], ledOff);
    }
    if (i<3){
      analogWrite(ledPins[0],ledHigh);
    }
    delay(cycleWaitTime);        
  }
}
