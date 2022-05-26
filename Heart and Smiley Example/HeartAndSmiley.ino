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


/*CUSTOM FUNCTIONS */
/*Lights all Led's in a row*/
void OneAtaTime(){
  for(int j = 0; j < 8 ; j++){
    for(int k = 0; k < 8; k++){
       lc.setLed(1,j,k,1);
       delay(1000);
    }   
  }
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
  PrintByte(0,Smiley);  
  PrintByte(1,Heart);
 

  

}
