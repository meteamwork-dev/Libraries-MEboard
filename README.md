
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
- ตัวอย่างการใช้งาน
## อธิบายฟังก์ชันและการใช้งานของไลบราลี่ MEboard
ติดตั้ง Arduino IDE version : 2.3.4 

ดาวโหลดไฟล์ไลบราลี่จาก https://github.com/meteamwork-dev/Libraries-MEboard

และติดตั้ง ลงไปใน C:\Program Files (x86)\Arduino\libraries
สามารถเขียนโปรแกรมจากไฟล์ "MEboard.ino" ซึ่งเป็นไฟล์ที่ได้เขียนอ่านค่าเซ็นเซอร์ต่างๆไว้แล้วตามตัวอย่างที่  หรือ สามารถเปิดไฟล์ Arduino ใหม่ แล้วให้พิม

                  #include "MEBoard.h"       ---1.1

ไว้ด้านบนสุดของหน้าต่าง จะเป็นการเรียกใช้ MEBoard ไลบราลี่

## ฟังก์ชัน
**Pinmode:**

                      pinmode();            ---1.2

ให้นำชุดคำสั่ง 1.2 ไปวางใน void setup เพื่อเป็นการประกาศขาที่จำเป็นต่อใช้งานของ MEBoard

**DigitalInput:**

                      ReadDI();            ---1.3

ให้นำชุดคำสั่ง 1.3 ไปวางใน void loop เพื่อทำการอ่านค่า DI ทุกแชแนลของ MEBoard ส่วนการนำค่า DI ไปใช้งานให้พิม DI ตามด้วยเลขแชแนล เช่น DI1  

ตารางที่ 1.1 แสดงตัวแปรของ Digitalinput
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

    #include "MEBoard.h" 
    void setup() {
    pinmode();  //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
    Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600 
  
    }

    void loop() {
    ReadDI(); //อ่านค่า DI ทุกแชแนลของ MEBoard
    Serial.println(DI1); //แสดงค่าของ DigitalInput แชแนลที่ 1 
   
    }

จากนั้น complied และ upload ไปยัง MEBoard จะดูค่า DI1 ได้ใน Serial Monitor 

**Analoginput:**

คือชุดคำสั่งเพื่อไว้อ่านค่า AI และ NTC ของ MEboard จะถูกวางใน void ReadSensor() เพื่ออ่านค่าต่อครั้งตามเวลาที่กำหนด

                    ReadAI();              ---1.4

เวลาอ่านค่า Analog มาจะมีค่าเท่ากับ 0-1024 จึงจำเป็นต้องแปลงค่าตามคำสั่งที่ 1.5 ให้เป็นหน่วยที่เราต้องการ เช่น PSI เป็นต้น
 
          AISet(channel,input,min,max)     ---1.5

คือชุดคำสั่งเพื่อไว้ตั้งค่าต่างๆ ดังนี้ 

    chennel => เลือกแชแนล AI 1-4
    input => ประเภทของเซนเซอร์  1 คือ 0-5VDC , 2 คือ 4-20mA 
    min => ค่าต่ำสุดของช่วงเซนเซอร์ที่ต่อใช้งาน
    max => ค่าสูงสุดของช่วงเซนเซอร์ที่ต่อใช้งาน 

ส่วนการนำค่า AI, NTC ไปใช้งานให้พิม AI, NTC ตามด้วยเลขแชแนล เช่น AI1, NTC1

ตารางที่ 1.2 แสดงตัวแปรของ Analoginput
| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `AI1` | `uint16_t` | ค่า Analoginput แชแนลที่ 1  |
| `AI2` | `uint16_t` | ค่า Analoginput แชแนลที่ 2  |
| `AI3` | `uint16_t` | ค่า Analoginput แชแนลที่ 3  |
| `AI4` | `uint16_t` | ค่า Analoginput แชแนลที่ 4  |
| `NTC1` | `uint16_t` | ค่าอุณหภูมิของ NTC แชแนลที่ 1  |
| `NTC2` | `uint16_t` | ค่าอุณหภูมิของ NTC แชแนลที่ 2  |
| `NTC3` | `uint16_t` | ค่าอุณหภูมิของ NTC แชแนลที่ 3  |
| `NTC4` | `uint16_t` | ค่าอุณหภูมิของ NTC แชแนลที่ 4  |
| `NTC5` | `uint16_t` | ค่าอุณหภูมิของ NTC แชแนลที่ 5  |
| `NTC6` | `uint16_t` | ค่าอุณหภูมิของ NTC แชแนลที่ 6  |
| `NTC7` | `uint16_t` | ค่าอุณหภูมิของ NTC แชแนลที่ 7  |
| `NTC8` | `uint16_t` | ค่าอุณหภูมิของ NTC แชแนลที่ 8  |
 
EX1.2 ตัวอย่างโปรแกรม Analoginput

    #include "MEBoard.h"

    void setup() {
    pinmode(); //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
    TimeSensor.setInterval(3000,ReadSensor);  //ตั้ง 10000 = 10Sec 3000
    Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600  
    }

    void ReadSensor(){
    ReadAI(); //อ่านค่า Analoginput
    AISet(1,2,0,450);//เลือกแชแนลที่ 1 ประเภทของเซนเซอร์คือ 4-20mA, ค่าน้อยที่สุดคือ 0, ค่ามากที่สุดคือ 450
    
    }

    void loop() {
    Serial.print(AI1); //แสดงค่าของ AnalogInput แชแนลที่ 1
    Serial.println(NTC1); //แสดงค่าอุณหภูมิของ NTC แชแนลที่ 1
    }

**DigitalOutput:**

คือ คำสั่งให้รีเลย์ของ MEboard ทำงาน โดยจำเป็นต้องเลือกเเชแนลและตัวแปรค่าสถานะในการสั่งการ
 
                DOut(channel,output);        ---2.1

chennel => 1 - 4 เลือกเเชแนลของ DigitalOutput   
output => 0 = รีเลย์ไม่ทำงาน, 1 =  รีเลย์ทำงาน

ตัวอย่างเช่น สั่งให้รีเลย์แชแนลที่ 1 ทำงาน

                    DOut(1,1);              ---2.2

หรือจะใช้ค่าตัวแปรตามคำสั่ง 2.3 โดยที่ต้องกำหนดค่าของตัวแปรก่อนดูได้จากตัวอย่าง EX2.2

                    DOut(1,ON);              ---2.3

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
| `DO8` | `uint16_t` | รีเลย์  แชแนลที่ 8  |

EX2.1 ตัวอย่างการใช้งาน DO 

    #include "MEBoard.h" 

    void setup() {
    pinmode();  //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
    Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600 
  
    }

    void loop() {
    DOut(1,1); //สั่งให้รีเลย์แชแนลที่ 1 ของ MEBoard ทำงาน
    Serial.println(DO1); //แสดงค่าของ DigitalOutput แชแนลที่ 1 
   
    }


EX2.2 ตัวอย่างการใช้งาน DO แบบใช้ตัวแปรสั่งงาน
    
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


ตัวอย่างนำ DI กับ DO ใช้ร่วมกัน โดยใช้สถานะของ DI1 มาเป็นตัวกำหนด สถานะของ DO1 ตาม EX2.3

EX2.3 ตัวอย่างการใช้งาน DO ร่วมกับ DI 

    #include "MEBoard.h" 
    int ON = 1;  //ประการค่าตัวแปร ON ให้เท่ากับ 1

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

จากนั้น complied และ upload ไปยัง MEBoard จะดูค่า DI1, DO1 ได้ใน Serial Monitor 

**Analogoutput**
คือ คำสั่งให้จ่ายไฟ 0-10VDC ที่แชนวล AO1-AO4 ของ MEboard 

                  AOut(channel,output)         ---2.4
            
    chennel => เลือกแชแนล 1-4
    output => ใส่ค่าตัวแปรหรือตัวเลข 0-10VDC 
ตัวอย่างคำสั่งจ่าย 5 VDC ที่ Analogout แชแนลที่1              

                       AOut(1,5)               ---2.5
หรือจะใช้ค่าตัวแปรตามคำสั่ง 2.6 โดยที่ต้องกำหนดค่าของตัวแปรดูได้จากตัวอย่าง EX2.5

                       AOut(1,value)               ---2.6

ยังสามารถอ่านค่าได้จากตัวแปร AO ได้ตามตารางที่ 

ตารางที่ 2.2 แสดงตัวแปร AnalogOutput
| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `AO1` | `uint16_t` | Analogoutput แชแนลที่ 1  |
| `AO2` | `uint16_t` | Analogoutput แชแนลที่ 2  |
| `AO3` | `uint16_t` | Analogoutput แชแนลที่ 3  |
| `AO4` | `uint16_t` | Analogoutput  แชแนลที่ 4  |

EX2.4 ตัวอย่างการใช้งาน AO

    #include "MEBoard.h" 

    void setup() {
    pinmode();  //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
    Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย  baud-rate 9600 

    }

    void loop() {
    AOut(1,2); //สั่งให้จ่าย 2 VDC แชแนลที่ 1 ของ MEBoard 
    Serial.println(AO1); //แสดงค่าของ AnalogOutput แชแนลที่ 1 

    }

EX2.5 ตัวอย่างการใช้งาน DO แบบใช้ตัวแปร

    #include "MEBoard.h" 
    int value = 7;  //ประการค่าตัวแปร value ให้เท่ากับ 7

    void setup() {
    pinmode();  //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
    Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย    baud-rate 9600 

    }

    void loop() {
    AOut(1,value);//สั่งให้จ่าย 7 VDC ตามค่าของตัวแปร Value  Analogoutput แชแนลที่ 1 ของ MEBoard 
    Serial.println(AO1); //แสดงค่าของ AnalogOutput แชแนลที่ 1 

    }

**ตัวควบคุม PID**

            PIDAOut1(setpoint,input,kP,kI,kD,min,max)

    setpoint => setpoint value for pid control
    input => input feedback for pid control
    direction => pid control type 0 = Forward , 1 = Backward 
    kP = > propotional constant value (0-100%)
    kI = > integral constant value (0-100%)
    kD = > differential constant value (0-100%)
    min => minimum value of pid output 
    max => maximum value of pid output 
