# Libraries-MEboard
## Version 0.1.0 @14/1/2025
- pinmode
- Input
  - DI, AI, NTC
- Output
  - DO, AO
  - ตัวควบคุม PID  
- การสื่อสาร modbus RTU RS485
- EEPROM

## อธิบายฟังก์ชันและการใช้งานของไลบราลี่ MEboard
ติดตั้ง Arduino IDE version : 2.3.4 

ดาวโหลดไฟล์ไลบราลี่จาก https://github.com/meteamwork-dev/Libraries-MEboard

และติดตั้ง ลงไปใน C:\Program Files (x86)\Arduino\libraries
สามารถเขียนโปรแกรมจากไฟล์ "MEboard.ino" ซึ่งเป็นไฟล์ที่ได้เขียนอ่านค่าเซ็นเซอร์ต่างๆไว้แล้ว หรือ สามารถเปิดไฟล์ Arduino ใหม่ แล้วให้พิม
```http
                #include "MEBoard.h"       ---1.1
```
ไว้ด้านบนสุดของหน้าต่าง

## ฟังก์ชัน
Pinmode:
```http
                      pinmode();            ---1.2
```
ให้นำชุดคำสั่ง 1.2 ไปวางใน void setup เพื่อเป็นการประกาศขาที่จำเป็นต่อใช้งานของ MEBoard

DigitalInput:
```http
                      ReadDI();            ---1.3
```
ให้นำชุดคำสั่ง 1.3 ไปวางใน void loop เพื่อทำการอ่านค่า DI ทุกแชแนลของ MEBoard ส่วนการนำค่า DI ไปใช้งานให้พิม DI ตามด้วยเลขแชแนล เช่น DI1  

ตัวอย่างการใช้งาน DI 
```http
#include "MEBoard.h" 
  void setup() {
   pinmode();  //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
   Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600 
  
}

  void loop() {
   ReadDI(); //อ่านค่า DI ทุกแชแนลของ MEBoard
   Serial.println(DI1); //แสดงค่าของ DigitalInput แชแนล 1 
   
}
```
จากนั้น complied และ upload ไปยัง MEBoard จะดูค่า DI1 ได้ใน Serial Monitor 

DigitalOutput:
```http 
  DOut(channel,output);
```
chennel => 1 - 4 เลือกเเชแนลของ DigitalOutput   
output => 0 = รีเลย์ไม่ทำงาน, 1 =  รีเลย์ทำงาน


  
  AISet(channel,input,min,max)
    chennel =>select chennel 1-4
    input =>sensor type  1=0-5VDC , 2=4-20mA 
    min => minimum value of sensor range
    max => maximum value of sensor range  

  AOut(channel,output)
    chennel =>select chennel 1-4
    output => 0-10VDC 
   
  PIDAOut1(setpoint,input,kP,kI,kD,min,max)
    setpoint => setpoint value for pid control
    input => input feedback for pid control
    direction => pid control type 0 = Forward , 1 = Backward 
    kP = > propotional constant value (0-100%)
    kI = > integral constant value (0-100%)
    kD = > differential constant value (0-100%)
    min => minimum value of pid output 
    max => maximum value of pid output 
