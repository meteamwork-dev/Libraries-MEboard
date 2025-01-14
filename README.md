
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
ไว้ด้านบนสุดของหน้าต่าง จะเป็นการเรียกใช้ MEBoard ไลบราลี่

## ฟังก์ชัน
**Pinmode:**
```http
                      pinmode();            ---1.2
```
ให้นำชุดคำสั่ง 1.2 ไปวางใน void setup เพื่อเป็นการประกาศขาที่จำเป็นต่อใช้งานของ MEBoard

**DigitalInput:**
```http
                      ReadDI();            ---1.3
```
ให้นำชุดคำสั่ง 1.3 ไปวางใน void loop เพื่อทำการอ่านค่า DI ทุกแชแนลของ MEBoard ส่วนการนำค่า DI ไปใช้งานให้พิม DI ตามด้วยเลขแชแนล เช่น DI1  

ตารางที่ 1.1 แสดงตัวแปร Digitalinput
| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `DI1` | `uint16_t` | ค่า Digitalinput แชแนลที่ 1  |
| `DI2` | `uint16_t` | ค่า Digitalinput แชแนลที่ 2  |
| `DI3` | `uint16_t` | ค่า Digitalinput แชแนลที่ 3  |
| `DI4` | `uint16_t` | ค่า Digitalinput แชแนลที่ 4  |
| `DI5` | `uint16_t` | ค่า Digitalinput แชแนลที่ 5  |
| `DI6` | `uint16_t` | ค่า Digitalinput แชแนลที่ 6  |
| `DI7` | `uint16_t` | ค่า Digitalinput แชแนลที่ 7  |
| `DI8` | `uint16_t` | ค่า Digitalinput แชแนลที่ 8  |

EX1.1 ตัวอย่างการใช้งาน DI 
```http
#include "MEBoard.h" 
  void setup() {
   pinmode();  //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
   Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600 
  
}

  void loop() {
   ReadDI(); //อ่านค่า DI ทุกแชแนลของ MEBoard
   Serial.println(DI1); //แสดงค่าของ DigitalInput แชแนลที่ 1 
   
}
```
จากนั้น complied และ upload ไปยัง MEBoard จะดูค่า DI1 ได้ใน Serial Monitor 

**Analoginput: **
```http
AISet(channel,input,min,max)
```    
    chennel =>select chennel 1-4
    input =>sensor type  1=0-5VDC , 2=4-20mA 
    min => minimum value of sensor range
    max => maximum value of sensor range  





**DigitalOutput:**

คือ คำสั่งให้รีเลย์ของ MEboard ทำงาน โดยจำเป็นต้องเลือกเเชแนลและตัวแปรค่าสถานะในการสั่งการ
```http 
                DOut(channel,output);        ---2.1
```
chennel => 1 - 4 เลือกเเชแนลของ DigitalOutput   
output => 0 = รีเลย์ไม่ทำงาน, 1 =  รีเลย์ทำงาน

ตัวอย่างเช่น สั่งให้รีเลย์แชแนลที่ 1 ทำงาน
```http 
                    DOut(1,1);              ---2.2
```
หรือจะใช้ค่าตัวแปรตามคำสั่ง 2.3
```http 
                    DOut(1,ON);              ---2.3
```
ซึ่งจำเป็นต้องประกาศตัวแปรก่อนดูได้จาก EX2.1
และยังสามารถอ่านค่าได้จากตัวแปร DO ได้ตามตารางที่ 

ตารางที่ 2.1 แสดงตัวแปร DigitalOutput
| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `DO1` | `uint16_t` | รีเลย์ แชแนลที่ 1  |
| `DO2` | `uint16_t` | รีเลย์ แชแนลที่ 2  |
| `DO3` | `uint16_t` | รีเลย์ แชแนลที่ 3  |
| `DO4` | `uint16_t` | รีเลย์  แชแนลที่ 4  |
| `DO5` | `uint16_t` | รีเลย์  แชแนลที่ 5  |
| `DO6` | `uint16_t` | รีเลย์  แชแนลที่ 6  |
| `DO7` | `uint16_t` | รีเลย์  แชแนลที่ 7  |
| `Do8` | `uint16_t` | รีเลย์  แชแนลที่ 8  |

EX2.1 ตัวอย่างการใช้งาน DO 
```http
#include "MEBoard.h" 

  void setup() {
   pinmode();  //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
   Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600 
  
}

  void loop() {
   DOut(1,1);//สั่งให้รีเลย์แชแนลที่ 1 ของ MEBoard ทำงาน
   Serial.println(DO1); //แสดงค่าของ DigitalOutput แชแนลที่ 1 
   
}
```
หรือจะใช้ค่าตัวแปรในการสั่งสถานะของ DO

EX2.2 ตัวอย่างการใช้งาน DO แบบใช้ตัวแปร
```http
#include "MEBoard.h" 
 int ON = 1;  //ประการค่าตัวแปร ON ให้เท่ากับ 1ง

  void setup() {
   pinmode();  //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
   Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600 
  
}

  void loop() {
   DOut(1,ON);//สั่งให้รีเลย์แชแนลที่ 1 ของ MEBoard ทำงาน
   Serial.println(DO1); //แสดงค่าของ DigitalOutput แชแนลที่ 1 
   
}
```

หรือจะนำ DI กับ DO ใช้ร่วมกัน โดยใช้สถานะของ DI1 มาเป็นตัวกำหนด สถานะของ DO1 ตาม EX2.3

EX2.3 ตัวอย่างการใช้งาน DO ร่วมกับ DI 
```http
#include "MEBoard.h" 
 int ON = 1;  //ประการค่าตัวแปร ON ให้เท่ากับ 1ง

  void setup() {
   pinmode();  //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
   Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600 
  
}

  void loop() {
   ReadDI(); //อ่านค่า DI ทุกแชแนลของ MEBoard
   DOut(1,DI1);  //สั่งให้รีเลย์แชแนลที่ 1 ของ MEBoard ทำงาน
   Serial.print(DI1); //แสดงค่าของ DigitalInput แชแนลที่ 1
   Serial.println(DO1); //แสดงค่าของ DigitalOutput แชแนลที่ 1 
   
}
```
จากนั้น complied และ upload ไปยัง MEBoard จะดูค่า DI1, DO1 ได้ใน Serial Monitor 

**Analogoutput**
```http
AOut(channel,output)
```
    chennel =>select chennel 1-4
    output => 0-10VDC 

**ตัวควบคุม PID**
```http
 PIDAOut1(setpoint,input,kP,kI,kD,min,max)
```
    setpoint => setpoint value for pid control
    input => input feedback for pid control
    direction => pid control type 0 = Forward , 1 = Backward 
    kP = > propotional constant value (0-100%)
    kI = > integral constant value (0-100%)
    kD = > differential constant value (0-100%)
    min => minimum value of pid output 
    max => maximum value of pid output 
