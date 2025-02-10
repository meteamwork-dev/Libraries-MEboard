
# Libraries-MEboard
## Version 0.1.1 @4/2/2025
- เพิ่มสมการเชิงเส้นในคำสั่ง AIset 
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

ช่องทางการติดต่อสอบถาม email ping.paradon2000@gmail.com

## อธิบายฟังก์ชันและการใช้งานของไลบราลี่ MEboard
ติดตั้ง Arduino IDE version : 2.3.4 

ดาวโหลดไฟล์ external libraries.rar ไลบราลี่จาก https://github.com/meteamwork-dev/Libraries-MEboard

และติดตั้งเพียงไฟล์ด้านใน external libraries.rar ลงไปใน C:\Program Files (x86)\Arduino\libraries
สามารถเขียนโปรแกรมจากไฟล์ "MEboard.ino" ซึ่งเป็นไฟล์ที่ได้เขียนอ่านค่าเซ็นเซอร์ต่างๆไว้แล้วตามตัวอย่างที่  หรือ สามารถเปิดไฟล์ Arduino ใหม่ แล้วให้พิม

                  #include "MEBoard.h"       ---1.1

ไว้ด้านบนสุดของหน้าต่าง จะเป็นการเรียกใช้ MEBoard ไลบราลี่

## ฟังก์ชัน
**Pinmode:**  
โดยใช้ชุดคำสั่งดังนี้

                      pinmode();            ---1.2

ให้นำชุดคำสั่ง 1.2 ไปวางใน void setup เพื่อเป็นการประกาศขาที่จำเป็นต่อใช้งานของ MEBoard

**DigitalInput:**     
โดยใช้ชุดคำสั่งดังนี้

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
    Serial.println(DI1); //แสดงค่าของ DigitalInput แชแนลที่ 1 ใน serial monitor
   
    }

จากนั้น complied และ upload ไปยัง MEBoard จะดูค่า DI1 ได้ใน Serial Monitor 

**Analoginput:**
 
คือชุดคำสั่งเพื่อไว้อ่านค่า AI และ NTC ของ MEboard จะถูกวางใน void ReadSensor() เพื่ออ่านค่าต่อครั้งตามเวลาที่กำหนด โดยใช้ชุดคำสั่งดังนี้

                    ReadAI();              ---1.4

ค่า Analog ของเซ็นเซอร์ชนิด 0-5 vdc จะมีค่าเท่ากับ 0-1024 
ค่า Analog ของเซ็นเซอร์ชนิด 4-20mA จะมีค่าเท่ากับ 205-973
จึงจำเป็นต้องแปลงค่า Analog ให้เป็นหน่วยของเซ็นเซอร์ที่ใช้งาน เช่น PSI โดยมีสมการเชิงเส้น y=mx+c เป็นตัวคำนวณซึ่งจำเป็นต้องหาค่าตัวแปร m และ c ในสมการ สามารถดูวิธีการหาได้จาก.......   
 
           AISet(channel,AIpara1,AIpara2,Min,Max,CalAI )     ---1.5

คือชุดคำสั่งเพื่อไว้ตั้งค่าต่างๆ ดังนี้ 

    chennel => เลือกแชแนล AI 1-4
    m => m in Equation y=mx+c
    c => c in Equation y=mx+c
    min => ค่าต่ำสุดของช่วงเซนเซอร์ที่ต่อใช้งาน
    max => ค่าสูงสุดของช่วงเซนเซอร์ที่ต่อใช้งาน 
    CalAI => สอบเทียบค่า AI โดยใช้ตัวคูณ เช่น 1.35 เมื่อไม่ต้องการสอบเทียบให้ใส่ค่าไว้ 1 
    
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
    TimeSensor.setInterval(3000,ReadSensor);  //ความเร็วในการวนอ่านค่า AI ตั้งค่าไว้ 3000 = 3Sec 
    Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600  
    }

    void ReadSensor(){
    ReadAI(); //อ่านค่า Analoginput
    AISet(2,0.5859,-120.12,0,450,1);//เลือกแชแนลที่ 1, ค่า m = 0.5859, ค่า c = -120.12, ค่าน้อยที่สุดของเซนเซอร์คือ 0, ค่ามากที่สุดคือ 450
    
    }

    void loop() {
    Serial.print(AI1); //แสดงค่าของ AnalogInput แชแนลที่ 1 ใน serial monitor
    Serial.println(NTC1); //แสดงค่าอุณหภูมิของ NTC แชแนลที่ 1 ใน serial monitor
    }

**DigitalOutput:**

คือ คำสั่งให้รีเลย์ของ MEboard ทำงาน โดยจำเป็นต้องเลือกเเชแนลและตัวแปรค่าสถานะในการสั่งการ โดยใช้ชุดคำสั่งดังนี้
 
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
    Serial.println(DO1); //แสดงค่าของ DigitalOutput แชแนลที่ 1 ใน serial monitor
   
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
    Serial.println(DO1); //แสดงค่าของ DigitalOutput แชแนลที่ 1 ใน serial monitor
   
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
    Serial.println(DO1); //แสดงค่าของ DigitalOutput แชแนลที่ 1 ใน serial monitor
   
    }

จากนั้น complied และ upload ไปยัง MEBoard จะดูค่า DI1, DO1 ได้ใน Serial Monitor 

**Analogoutput :**

คือ คำสั่งให้จ่ายไฟ 0-10VDC ที่แชนวล AO1-AO4 ของ MEboard โดยใช้ชุดคำสั่งดังนี้

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
    Serial.println(AO1); //แสดงค่าของ AnalogOutput แชแนลที่ 1 ใน serial monitor

    }

EX2.5 ตัวอย่างการใช้งาน AO แบบใช้ตัวแปร

    #include "MEBoard.h" 
    int value = 7;  //ประการค่าตัวแปร value ให้เท่ากับ 7

    void setup() {
    pinmode();  //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
    Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย    baud-rate 9600 

    }

    void loop() {
    AOut(1,value);//สั่งให้จ่าย 7 VDC ตามค่าของตัวแปร Value  Analogoutput แชแนลที่ 1 ของ MEBoard 
    Serial.println(AO1); //แสดงค่าของ AnalogOutput แชแนลที่ 1 ใน serial monitor

    }

**ตัวควบคุม PID :**

คือ ตัวควบคุมที่นำมาคำนวณค่า Output ของ AO แต่ละแชแนล เพื่อให้ค่า Output เปลี่ยนแปลงตามที่เราต้องการเช่น ปรับเปลี่ยนตำแหน่งวาล์วน้ำ เป้นต้น โดยใช้ชุดคำสั่งดังนี้

            PIDAOut1(setpoint,input,kP,kI,kD,min,max)    ---2.7

    setpoint => ค่าเซ็ตพอยต์สำหรับการควบคุม PID
    input => อินพุตผลการตอบสนองสำหรับการควบคุม PID
    kP = > ค่าคงที่ตามสัดส่วน (0-100%)
    kI = > ค่าคงที่ปริพันธ์ (0-100%)
    kD = > ค่าคงที่อนุพันธ์ (0-100%)
    min => ค่าต่ำสุดของเอาท์พุต pid 
    max => ค่าสูงสุดของเอาท์พุต pid 

สามารถเปลี่ยนแชแนลของ AO ได้โดยเปลี่ยนเลขหลัง PIDAOut เช่น

          PIDAOut2(setpoint,input,kP,kI,kD,min,max)    ---2.8

โดยที่สามารถเลือกทิศทางได้ จากการแก้ในไฟล์ MEBoard.h บรรทัดที่ 93-96  ให้แก้คำว่า DIRECT เป็น REVERSE 

           PID myPID4(&Input4, &Output4, &Setpoint4, kp4, ki4, kd4, DIRECT);        ---2.9

โดยที่มีตัวแปรที่สามารถเรียกใช้งานได้ตามตารางที่ 2.3

ตารางที่ 2.3 ตัวแปรของชุดคำสั่ง PID
| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
|`setpoint1`|`uint16_t`|ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 1|
| `kp1` | `int` |ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 1|
| `ki1` | `int` |ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 1|
| `kd1` | `int` |ค่าคงที่อนุพันธ์ Analogoutput  แชแนลที่ 1|
|`outMin1`|`uint16_t`|ค่าต่ำสุดของเอาท์พุต PID Analogoutput  แชแนลที่ 1|
|`outMax1`|`uint16_t`| ค่าสูงสุดของเอาท์พุต PID Analogoutput  แชแนลที่ 1|
|`PIDOutput1`|`uint16_t`|ค่า PID Analogoutput แชแนลที่ 1  |
|`setpoint2`|`uint16_t`| ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 2|
|`kp2`|`int`|ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 2  |
|`ki2`|`int`| ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 2  |
|`kd2`|`int`| ค่าคงที่อนุพันธ์ Analogoutput  แชแนลที่ 2  |
|`outMin2`|`uint16_t`|  ค่าต่ำสุดของเอาท์พุต PID Analogoutput  แชแนลที่ 2|
|`outMax2`|`uint16_t`| ค่าสูงสุดของเอาท์พุต PID Analogoutput  แชแนลที่ 2|
|`PIDOutput2`|`uint16_t`|ค่า PID Analogoutput แชแนลที่ 2|
|`setpoint3`|`uint16_t`| ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 3  |
|`kp3`|`int`| ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 3  |
|`ki3`|`int`| ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 3  |
|`kd3`|`int`| ค่าคงที่อนุพันธ์ Analogoutput  แชแนลที่ 3  |
|`outMin3`|`uint16_t`|ค่าต่ำสุดของเอาท์พุต PID Analogoutput  แชแนลที่ 3|
|`outMax3`|`uint16_t`|ค่าสูงสุดของเอาท์พุต PID Analogoutput  แชแนลที่ 3|
|`PIDOutput3`|`uint16_t`|ค่า PID Analogoutput  แชแนลที่ 3|
|`setpoint4`|`uint16_t`|ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 4|
|`kp4`|`int`|ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 4|
|`ki4`|`int`|ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 4|
|`kd4`|`int`|ค่าคงที่อนุพันธ์ Analogoutput แชแนลที่ 4|
|`outMin4`|`uint16_t`|ค่าต่ำสุดของเอาท์พุต PID Analogoutput  แชแนลที่ 4|
|`outMax4`|`uint16_t`|ค่าสูงสุดของเอาท์พุต PID Analogoutput  แชแนลที่ 4|
|`PIDOutput4`|`uint16_t`|ค่า PID Analogoutput แชแนลที่ 4|

EX2.6 ตัวอย่างการใช้งานชุดคำสั่ง PID เพื่อควบคุม AO1 โดยจะใช้ AI1 เป็น input 

    #include "MEBoard.h"

    void setup() {
  
    pinmode();
    TimeSensor.setInterval(3000,ReadSensor);  //ความเร็วในการวนอ่านค่า AI ตั้งค่าไว้ 3000 = 3Sec 
    Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600 
    }

    void ReadSensor(){
    ReadAI(); //อ่านค่า Analoginput
    AISet(2,0.5859,-120.12,0,450,1);//เลือกแชแนลที่ 1, ค่า m = 0.5859, ค่า c = -120.12, ค่าน้อยที่สุดของเซนเซอร์คือ 0, ค่ามากที่สุดคือ 450
    }

    void loop() {
    TimeSensor.run(); //เปิดใช้งานฟังก์ชั่นเวลา
    PIDAOut1(350,AI1,50,35,10,30,100) //PID ของ AO1 โดย  setpoint = 350 input = AI1 ซึ่งทำการแปลงค่าแล้ว kP = 50%  kI = 35% kD = 10% min = 30% หรือ 3VDC ที่ AO1 max = 100% หรือ 10VDC
    Serial.println(AO1); //แสดงค่า AO แชแนลที่ 1 ใน serial monitor
    }

**EEPROM**

คือการจดจำค่าตัวแปรในตารางที่ 4.1 เมื่อบอร์ดไม่มีไฟเลี้ยง โดยใช้ชุดคำสั่ง 3.1 ไปวางใน void Loop 

                   Eeprom();           ---3.1

**การสื่อสาร modbus RTU RS485**

คือชุดคำสั่งใช้งานการสื่อสารผ่าน RS485 โดยใช้ชุดคำสั่งที่ 4.1 วางใน void setup  นำชุดคำสั่ง 4.2 และ 4.3 ไปวางใน void Loop 

                slave.begin(9600);       ---4.1
                  modbusread();          ---4.2
                   Register();           ---4.3


 โดยที่มีตัวแปรดังตารางที่ 4.1

ตารางที่ 4.1 ตารางตัวแแปรของไลบราลี่ MEBoard
 Parameter | Type     | Addr   |  feature  | Description  |
| :--------| :------- | :------| :---------   | :---------   |
| `DI1`   | `uint16_t`|  `0`   | Read Only | DigitalInput แชแนลที่1  |
| `DI2`   | `uint16_t`|  `1`   | Read Only | DigitalInput แชแนลที่2  |
| `DI3`   | `uint16_t`|  `2`   | Read Only | DigitalInput แชแนลที่3  |
| `DI4`   | `uint16_t`|  `3`   | Read Only | DigitalInput แชแนลที่4  |
| `DI5`   | `uint16_t`|  `4`   | Read Only | DigitalInput แชแนลที่5  |
| `DI6`   | `uint16_t`|  `5`   | Read Only | DigitalInput แชแนลที่6  |
| `DI7`   | `uint16_t`|  `6`   | Read Only | DigitalInput แชแนลที่7  |
| `DI8`   | `uint16_t`|  `7`   | Read Only | DigitalInput แชแนลที่8  |
| `FAI1`  | `uint16_t`|  `-`   | Read Only | AnalogInput แชแนลที่1 ยังไม่ได้ Set ค่า|
| `FAI2`  | `uint16_t`|  `-`   | Read Only | AnalogInput แชแนลที่2 ยังไม่ได้ Set ค่า|
| `FAI3`  | `uint16_t`|  `-`   | Read Only | AnalogInput แชแนลที่3 ยังไม่ได้ Set ค่า|
| `FAI4`  | `uint16_t`|  `-`   | Read Only | AnalogInput แชแนลที่4 ยังไม่ได้ Set ค่า|
| `AI1`   | `uint16_t`|  `8`   | Read Only | AnalogInput แชแนลที่1 Set ค่าแล้ว |
| `AI2`   | `uint16_t`|  `9`   | Read Only | AnalogInput แชแนลที่2 Set ค่าแล้ว |
| `AI3`   | `uint16_t`|  `10`  | Read Only | AnalogInput แชแนลที่3 Set ค่าแล้ว |
| `AI4`   | `uint16_t`|  `11`  | Read Only | AnalogInput แชแนลที่4 Set ค่าแล้ว |
| `NT1` | `uint16_t` |  `-`  | Read Only | ค่า Analog ของเซ็นเซอร์ NTC แชแนลที่ 1  |
| `NT2` | `uint16_t` |  `-`  | Read Only | ค่า Analog ของเซ็นเซอร์ NTC แชแนลที่ 2  |
| `NT3` | `uint16_t` |  `-`  | Read Only | ค่า Analog ของเซ็นเซอร์ NTC แชแนลที่ 3  |
| `NT4` | `uint16_t` |  `-`  | Read Only | ค่า Analog ของเซ็นเซอร์ NTC แชแนลที่ 4  |
| `NT5` | `uint16_t` |  `-`  | Read Only | ค่า Analog ของเซ็นเซอร์ NTC แชแนลที่ 5  |
| `NT6` | `uint16_t` |  `-`  | Read Only | ค่า Analog ของเซ็นเซอร์ NTC แชแนลที่ 6  |
| `NT7` | `uint16_t` |  `-`  | Read Only | ค่า Analog ของเซ็นเซอร์ NTC แชแนลที่ 7  |
| `NT8` | `uint16_t` |  `-`  | Read Only | ค่า Analog ของเซ็นเซอร์ NTC แชแนลที่ 8  |
| `NTC1` | `uint16_t` |  `12`  | Read Only | ค่าอุณหภูมิของ NTC แชแนลที่ 1  |
| `NTC2` | `uint16_t` |  `13`  | Read Only | ค่าอุณหภูมิของ NTC แชแนลที่ 2  |
| `NTC3` | `uint16_t` |  `14`  | Read Only | ค่าอุณหภูมิของ NTC แชแนลที่ 3  |
| `NTC4` | `uint16_t` |  `15`  | Read Only | ค่าอุณหภูมิของ NTC แชแนลที่ 4  |
| `NTC5` | `uint16_t` |  `16`  | Read Only | ค่าอุณหภูมิของ NTC แชแนลที่ 5  |
| `NTC6` | `uint16_t` |  `17`  | Read Only | ค่าอุณหภูมิของ NTC แชแนลที่ 6  |
| `NTC7` | `uint16_t` |  `18`  | Read Only | ค่าอุณหภูมิของ NTC แชแนลที่ 7  |
| `NTC8` | `uint16_t` |  `19`  | Read Only | ค่าอุณหภูมิของ NTC แชแนลที่ 8  |
| `DO1`  | `uint16_t` |  `20`  | Read Only | รีเลย์ แชแนลที่ 1  |
| `DO2`  | `uint16_t` |  `21`  | Read Only | รีเลย์ แชแนลที่ 2  |
| `DO3`  | `uint16_t` |  `22`  | Read Only | รีเลย์ แชแนลที่ 3  |
| `DO4`  | `uint16_t` |  `23`  | Read Only | รีเลย์  แชแนลที่ 4  |
| `DO5`  | `uint16_t` |  `24`  | Read Only | รีเลย์  แชแนลที่ 5  |
| `DO6`  | `uint16_t` |  `25`  | Read Only | รีเลย์  แชแนลที่ 6  |
| `DO7`  | `uint16_t` |  `26`  | Read Only | รีเลย์  แชแนลที่ 7  |
| `DO8`  | `uint16_t` |  `27`  | Read Only | รีเลย์  แชแนลที่ 8  |
| `AO1`  | `uint16_t` |  `28`  | Read Only | Analogoutput แชแนลที่ 1  |
| `AO2`  | `uint16_t` |  `29`  | Read Only | Analogoutput แชแนลที่ 2  |
| `AO3`  | `uint16_t` |  `30`  | Read Only | Analogoutput แชแนลที่ 3  |
| `AO4`  | `uint16_t` |  `31`  | Read Only | Analogoutput  แชแนลที่ 4  |
|`PIDOutput1`|`uint16_t`|`32`| Read Only | PID Analogoutput แชแนลที่ 1|
|`PIDOutput2`|`uint16_t`|`33`| Read Only | PID Analogoutput แชแนลที่ 2|
|`PIDOutput3`|`uint16_t`|`34`| Read Only | PID Analogoutput แชแนลที่ 3|
|`PIDOutput4`|`uint16_t`|`35`| Read Only | PID Analogoutput แชแนลที่ 4|
|`setpoint1`|`uint16_t`|`36`| Read and Write | ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 1|
|`kp1`|`int`|`37`| Read and Write | ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 1 |
|`ki1`|`int`|`38`| Read and Write | ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 1|
|`kd1`|`int`|`39`| Read and Write | ค่าคงที่อนุพันธ์ Analogoutput แชแนลที่ 1|
|`outMin1`|`uint16_t`|`40`| Read and Write | ค่าต่ำสุดของเอาท์พุต PID Analogoutput แชแนลที่ 1|
|`outMax1`|`uint16_t`|`41`| Read and Write | ค่าสูงสุดของเอาท์พุต PID Analogoutput แชแนลที่ 1|
|`setpoint2`|`uint16_t`|`42`| Read and Write | ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 2|
|`kp2`| `int` |`43`| Read and Write | ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 2|
|`ki2`| `int` |`44`| Read and Write | ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 2|
|`kd2`| `int` |`45`| Read and Write | ค่าคงที่อนุพันธ์ Analogoutput แชแนลที่ 2|
|`outMin2`|`uint16_t`|`46`| Read and Write | ค่าต่ำสุดของเอาท์พุต PID Analogoutput แชแนลที่ 2|
|`outMax2`|`uint16_t`|`47`| Read and Write | ค่าสูงสุดของเอาท์พุต PID Analogoutput แชแนลที่ 2|
|`setpoint3`|`uint16_t`|`48`| Read and Write | ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 3|
|`kp3`| `int` |`49`| Read and Write | ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 3|
|`ki3`| `int` |`50`| Read and Write | ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 3|
|`kd3`| `int` |`51`| Read and Write | ค่าคงที่อนุพันธ์ Analogoutput แชแนลที่ 3|
|`outMin3`|`uint16_t`|`52`| Read and Write | ค่าต่ำสุดของเอาท์พุต PID Analogoutput แชแนลที่ 3|
|`outMax3`|`uint16_t`|`53`| Read and Write | ค่าสูงสุดของเอาท์พุต PID Analogoutput แชแนลที่ 3|
|`setpoint4`|`uint16_t`|`54`| Read and Write | ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 4|
|`kp4`| `int` |`55`| Read and Write | ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 4|
|`ki4`| `int` |`56`| Read and Write | ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 4|
|`kd4`| `int` |`57`| Read and Write | ค่าคงที่อนุพันธ์ Analogoutput แชแนลที่ 4|
|`outMin4`|`uint16_t`|`58`| Read and Write | ค่าต่ำสุดของเอาท์พุต PID Analogoutput แชแนลที่ 4|
|`outMax2`|`uint16_t`|`59`| Read and Write | ค่าสูงสุดของเอาท์พุต PID Analogoutput แชแนลที่ 4|
|`calAI1`|`int16_t`|`60`| Read and Write | ค่าตัวแปรสำหรับสอบเทียบ AI วิธีใช้งานนำไปใส่คำสั่ง AISet |
|`calAI2`|`int16_t`|`61`| Read and Write | ค่าตัวแปรสำหรับสอบเทียบ AI วิธีใช้งานนำไปใส่คำสั่ง AISet |
|`calAI3`|`int16_t`|`62`| Read and Write | ค่าตัวแปรสำหรับสอบเทียบ AI วิธีใช้งานนำไปใส่คำสั่ง AISet |
|`calAI4`|`int16_t`|`63`| Read and Write | ค่าตัวแปรสำหรับสอบเทียบ AI วิธีใช้งานนำไปใส่คำสั่ง AISet |
|`ps1`|`int16_t`|`64`| Read and Write | ตัวแปรที่ 1 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps2`|`int16_t`|`65`| Read and Write | ตัวแปรที่ 2 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps3`|`int16_t`|`66`| Read and Write | ตัวแปรที่ 3 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps4`|`int16_t`|`67`| Read and Write | ตัวแปรที่ 4 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps5`|`int16_t`|`68`| Read and Write | ตัวแปรที่ 5 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps6`|`int16_t`|`69`| Read and Write | ตัวแปรที่ 6 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps7`|`int16_t`|`70`| Read and Write | ตัวแปรที่ 7 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps8`|`int16_t`|`71`| Read and Write | ตัวแปรที่ 8 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps9`|`int16_t`|`72`| Read and Write | ตัวแปรที่ 9 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps10`|`int16_t`|`73`| Read and Write | ตัวแปรที่ 10 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps11`|`int16_t`|`74`| Read and Write | ตัวแปรที่ 11 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps12`|`int16_t`|`75`| Read and Write | ตัวแปรที่ 12 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps13`|`int16_t`|`76`| Read and Write | ตัวแปรที่ 13 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps14`|`int16_t`|`77`| Read and Write | ตัวแปรที่ 14 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps15`|`int16_t`|`78`| Read and Write | ตัวแปรที่ 15 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps16`|`int16_t`|`79`| Read and Write | ตัวแปรที่ 16 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps17`|`int16_t`|`80`| Read and Write | ตัวแปรที่ 17 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps18`|`int16_t`|`81`| Read and Write | ตัวแปรที่ 18 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps19`|`int16_t`|`82`| Read and Write | ตัวแปรที่ 19 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps20`|`int16_t`|`83`| Read and Write | ตัวแปรที่ 20 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps21`|`int16_t`|`84`| Read and Write | ตัวแปรที่ 21 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps22`|`int16_t`|`85`| Read and Write | ตัวแปรที่ 22 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps23`|`int16_t`|`86`| Read and Write | ตัวแปรที่ 23 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps24`|`int16_t`|`87`| Read and Write | ตัวแปรที่ 24 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps25`|`int16_t`|`88`| Read and Write | ตัวแปรที่ 25 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps26`|`int16_t`|`89`| Read and Write | ตัวแปรที่ 26 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps27`|`int16_t`|`90`| Read and Write | ตัวแปรที่ 27 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps28`|`int16_t`|`91`| Read and Write | ตัวแปรที่ 28 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps29`|`int16_t`|`92`| Read and Write | ตัวแปรที่ 29 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps30`|`int16_t`|`93`| Read and Write | ตัวแปรที่ 30 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps31`|`int16_t`|`94`| Read and Write | ตัวแปรที่ 31 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps32`|`int16_t`|`95`| Read and Write | ตัวแปรที่ 32 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps33`|`int16_t`|`96`| Read and Write | ตัวแปรที่ 33 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps34`|`int16_t`|`97`| Read and Write | ตัวแปรที่ 34 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps35`|`int16_t`|`98`| Read and Write | ตัวแปรที่ 35 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps36`|`int16_t`|`99`| Read and Write | ตัวแปรที่ 36 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps37`|`int16_t`|`100`| Read and Write | ตัวแปรที่ 37 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps38`|`int16_t`|`101`| Read and Write | ตัวแปรที่ 38 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps39`|`int16_t`|`102`| Read and Write | ตัวแปรที่ 39 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps40`|`int16_t`|`103`| Read and Write | ตัวแปรที่ 40 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps41`|`int16_t`|`104`| Read and Write | ตัวแปรที่ 41 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps42`|`int16_t`|`105`| Read and Write | ตัวแปรที่ 42 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps43`|`int16_t`|`106`| Read and Write | ตัวแปรที่ 43 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps44`|`int16_t`|`107`| Read and Write | ตัวแปรที่ 44 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps45`|`int16_t`|`108`| Read and Write | ตัวแปรที่ 45 จองไว้สำหรับการสื่อสารผ่าน rs485|
|`ps46`|`int16_t`|`109`| Read and Write | ตัวแปรที่ 46 จองไว้สำหรับการสื่อสารผ่าน rs485|




			
**ตัวอย่างการใช้งาน**

ex5.1 ตัวอย่างการใช้งานไลบราลี่ อธิบายทีละบรรทัด

    #include "MEBoard.h"

    void setup() {
      pinmode(); //ประกาศขาที่จำเป็นต่อใช้งานของ MEBoard
      TimeSensor.setInterval(3000,ReadSensor);  //ความเร็วในการวนอ่านค่าเซ็นเซอร์ ตั้งค่าไว้ 3000 = 3Sec 
      Serial.begin(9600); //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600  
      slave.begin(9600); //สื่อสาร RS485 ช่องที่ 1 เลือก baud rate 9600  
      slave2.begin(9600); //สื่อสาร RS485 ช่องที่ 2 เลือก baud rate 9600   
    }

    void ReadSensor(){
      ReadAI(); //อ่านค่า Analoginput
    /////////////สำหรับAIset///////////////////////

    //////////////////////////////////////////

    void loop() {
      TimeSensor.run(); //เปิดใช้งานฟังก์ชั่นเวลา
      ReadDI(); ///อ่านค่า DI ทุกแชแนลของ MEBoard 
      Register(); //ประกาศตำแหน่ง RS485 แต่ละตัวแปร
      modbusread(); //อ่านค่าจาก RS485
      Eeprom(); //จดจำค่าตัวแปรเมื่อบอร์ดไม่มีไฟเลี้ยง
      /////////////////////////////////////////////
      //เขียนโปรแกรมที่นี้
   
      /////////////////////////////////////////////  
    }


