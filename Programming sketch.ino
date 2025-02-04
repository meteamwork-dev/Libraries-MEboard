#include "MEBoard.h"
//Version 0.1.1
void setup() {
   
  pinmode();
  TimeSensor.setInterval(3000,ReadSensor);  //10000 = 10Sec 3000
  Serial.begin(19200);  // for debug
  slave.begin(9600); // baud-rate at 9600  RS485(1)  
  slave2.begin(9600); // baud-rate at 9600  RS485(2) 
}
void ReadSensor(){
  ReadAI();
/////////////forAIset///////////////////////

//////////////////////////////////////////
}
void loop() {
   TimeSensor.run();
   ReadDI();
   modbusread();
   Eeprom(); 
 /////////////programing here//////////////////
    
    
 /////////////////////////////////////////////  
  Register();
}
