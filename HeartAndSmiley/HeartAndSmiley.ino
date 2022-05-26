#include "LedControl.h"

/* Hardware Connection */
int DIN = 12;
int CS = 10;
int CLK = 11;

/* Init LedControl Library */
LedControl lc = LedControl(DIN,CLK,CS,0);


/* INSERT CREATED DESIGNS / BYTE ARRAYS */
//////////////////////////////////////////
byte Smiley[8] = {0x24,0x24,0x24,0x24,0x00,0x81,0x42,0x3c};
byte Heart[8] = {0x66,0xff,0xff,0xff,0xff,0x7e,0x3c,0x18};
byte AllOn[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
byte Cat[8] = {0x88,0xf8,0xa8,0x71,0x21,0x79,0x7d,0xbe};
byte L[8] = {0x00,0x20,0x20,0x20,0x20,0x20,0x3e,0x00};
byte E[8] = {0x3e,0x20,0x20,0x3c,0x20,0x20,0x3e,0x00};
byte D[8] = {0x30,0x28,0x24,0x24,0x24,0x24,0x38,0x00};




/* CUSTOM FUNCTIONS */
/*Lights all Led's in a row*/
void OneAtaTime(){
  for(int j = 0; j < 8 ; j++){
    for(int k = 0; k < 8; k++){
       lc.setLed(1,j,k,1);
       delay(1000);
    }   
  }
}

/*GLOBAL VARIABLES */
int waittime = 2000;

void AroundACircle(int displayNumber){
    int mstime = 50;
  
    for(int i = 0; i < 8; i++){
      lc.setLed(displayNumber,0,i,1);
      delay(mstime);
    } 
    for(int i = 1; i < 8; i++){
      lc.setLed(displayNumber,i,7,1);
      delay(mstime);
    }
    
    for(int i = 6; i >= 0; i--){
      lc.setLed(displayNumber,7,i,1);
      delay(mstime);
    }
    
    for(int i = 6; i >=0; i--){
      lc.setLed(displayNumber,i,0,1);
      delay(mstime);
    }
    
    for(int column = 1; column < 7; column++){
      lc.setLed(displayNumber,1,column,1);
      delay(mstime);
    }
    for(int row = 1; row < 7; row++){
      lc.setLed(displayNumber,row,6,1);
      delay(mstime);
    }
    for(int column = 5; column >=0; column--){
      lc.setLed(displayNumber,6,column,1);
      delay(mstime);
    }
    for(int row = 5; row >=2; row--){
      lc.setLed(displayNumber,row,1,1);
      delay(mstime);
    }
    for(int column = 2; column < 6; column++){
      lc.setLed(displayNumber,2,column,1);
      delay(mstime);
    }
    for(int row = 3; row < 6; row++){
      lc.setLed(displayNumber,row,5,1);
      delay(mstime);
    }
    for(int column = 4; column >= 2;column--){
      lc.setLed(displayNumber,5,column,1);
      delay(mstime);
    }
    lc.setLed(displayNumber,4,2,1);
    delay(mstime);
    lc.setLed(displayNumber,3,2,1);
    delay(mstime);
    lc.setLed(displayNumber,3,3,1);
    delay(mstime);
    lc.setLed(displayNumber,3,4,1);
    delay(mstime);
    lc.setLed(displayNumber,4,4,1);
    delay(mstime);
    lc.setLed(displayNumber,5,4,1);
    delay(mstime);
    lc.setLed(displayNumber,4,3,1);
    delay(mstime);
    
  }


/* Clears all displays on all addresses */
void ClearAllDisplays(){
  for(int i=0; i < lc.getDeviceCount(); i++){
    lc.clearDisplay(i);
  }
}
/* Print byte to display given display addr and byte array */
void PrintByte(int displayNumber,byte character []){
  for(int i = 0; i < 8; i++){
    lc.setRow(displayNumber,i,character[i]);
  }
  
}
void setup() { 
    /* Go through each connected device and set settings for all */
    for(int i=0; i < lc.getDeviceCount(); i++) {
        /* Wake up device from power-saving mode */
        lc.shutdown(i,false); 
        /* Brightness can be changed in 16 steps with 15 being the brightest and 0 being the least bright without shutting the display off */
        lc.setIntensity(0,8);
        ClearAllDisplays();         
    } 
} 
void loop() {
  //Smiley
  PrintByte(0,Smiley);  
  delay(waittime);
  ClearAllDisplays();
  delay(waittime);

  //LED
  PrintByte(0,L);
  delay(300);
  ClearAllDisplays();
  delay(300);
  PrintByte(0,E);
  delay(300);
  ClearAllDisplays();
  delay(300);
  PrintByte(0,D);
  delay(300);
  ClearAllDisplays();
  delay(300);
  
  //Heart
  PrintByte(0,Heart);
  delay(waittime);
  ClearAllDisplays();
  delay(waittime);

  //Cat
  PrintByte(0,Cat);
  delay(waittime);
  ClearAllDisplays();
  delay(waittime);

  //Around A Circle + pulse all on accelerating
  AroundACircle(0);
  delay(waittime);
  ClearAllDisplays();
  delay(waittime);
  PrintByte(0,AllOn);
  delay(1000);
  ClearAllDisplays();
  delay(300);
  PrintByte(0,AllOn);
  delay(300);
  ClearAllDisplays();
  delay(300);
  PrintByte(0,AllOn);
  delay(150);
  ClearAllDisplays();
  delay(300);
  PrintByte(0,AllOn);
  delay(50);
  ClearAllDisplays();
  delay(50);
  PrintByte(0,AllOn);
  delay(50);
  ClearAllDisplays();
  delay(50);
  

}
