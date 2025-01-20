
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
    TimeSensor.setInterval(3000,ReadSensor);  //ความเร็วในการวนอ่านค่า AI ตั้งค่าไว้ 3000 = 3Sec 
    Serial.begin(9600);  //เพื่อดูค่าใน Serial Monitor โดย baud-rate 9600  
    }

    void ReadSensor(){
    ReadAI(); //อ่านค่า Analoginput
    AISet(1,2,0,450);//เลือกแชแนลที่ 1 ประเภทของเซนเซอร์คือ 4-20mA, ค่าน้อยที่สุดคือ 0, ค่ามากที่สุดคือ 450
    
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

EX2.5 ตัวอย่างการใช้งาน DO แบบใช้ตัวแปร

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
    AISet(1,2,0,450); //เลือกแชแนลที่ 1 ประเภทของเซนเซอร์คือ 4-20mA, ค่าน้อยที่สุดคือ 0, ค่ามากที่สุดคือ 450
    }

    void loop() {
    TimeSensor.run();
    PIDAOut1(350,AI1,50,35,10,30,100) //PID ของ AO1 โดย  setpoint = 350 input = AI1 ซึ่งทำการแปลงค่าแล้ว kP = 50%  kI = 35% kD = 10% min = 30% หรือ 3VDC ที่ AO1 max = 100% หรือ 10VDC
    Serial.println(AO1); //แสดงค่า AO แชแนลที่ 1 ใน serial monitor
    }

**EEPROM**

**การสื่อสาร modbus RTU RS485**

โดยใช้ชุดคำสั่งดังนี้

                   Register();           ---4.1
ให้นำชุดคำสั่ง 4.1 ไปวางใน void Loop 
เพื่อใช้งานใช้งานการสื่อสาร RS485 โดยที่มีตัวแปรดังนี้

ตารางที่ 4.1 ตารางตัวแแปรของไลบราลี่ MEBoard
 Parameter | Type     | Addr   | Description  |
| :--------| :------- | :------| :---------   |
| `DI1`   | `uint16_t`|  `0`   | DigitalInput แชแนลที่1  |
| `DI2`   | `uint16_t`|  `1`   | DigitalInput แชแนลที่2  |
| `DI3`   | `uint16_t`|  `2`   | DigitalInput แชแนลที่3  |
| `DI4`   | `uint16_t`|  `3`   | DigitalInput แชแนลที่4  |
| `DI5`   | `uint16_t`|  `4`   | DigitalInput แชแนลที่5  |
| `DI6`   | `uint16_t`|  `5`   | DigitalInput แชแนลที่6  |
| `DI7`   | `uint16_t`|  `6`   | DigitalInput แชแนลที่7  |
| `DI8`   | `uint16_t`|  `7`   | DigitalInput แชแนลที่8  |
| `AI1`   | `uint16_t`|  `8`   | AnalogInput แชแนลที่1   |
| `AI2`   | `uint16_t`|  `9`   | AnalogInput แชแนลที่2   |
| `AI3`   | `uint16_t`|  `10`  | AnalogInput แชแนลที่3   |
| `AI4`   | `uint16_t`|  `11`  | AnalogInput แชแนลที่4   |
| `NTC1` | `uint16_t` |  `12`  | ค่าอุณหภูมิของ NTC แชแนลที่ 1  |
| `NTC2` | `uint16_t` |  `13`  | ค่าอุณหภูมิของ NTC แชแนลที่ 2  |
| `NTC3` | `uint16_t` |  `14`  | ค่าอุณหภูมิของ NTC แชแนลที่ 3  |
| `NTC4` | `uint16_t` |  `15`  | ค่าอุณหภูมิของ NTC แชแนลที่ 4  |
| `NTC5` | `uint16_t` |  `16`  | ค่าอุณหภูมิของ NTC แชแนลที่ 5  |
| `NTC6` | `uint16_t` |  `17`  | ค่าอุณหภูมิของ NTC แชแนลที่ 6  |
| `NTC7` | `uint16_t` |  `18`  | ค่าอุณหภูมิของ NTC แชแนลที่ 7  |
| `NTC8` | `uint16_t` |  `19`  | ค่าอุณหภูมิของ NTC แชแนลที่ 8  |
| `DO1`  | `uint16_t` |  `20`  | รีเลย์ แชแนลที่ 1  |
| `DO2`  | `uint16_t` |  `21`  | รีเลย์ แชแนลที่ 2  |
| `DO3`  | `uint16_t` |  `22`  | รีเลย์ แชแนลที่ 3  |
| `DO4`  | `uint16_t` |  `23`  | รีเลย์  แชแนลที่ 4  |
| `DO5`  | `uint16_t` |  `24`  | รีเลย์  แชแนลที่ 5  |
| `DO6`  | `uint16_t` |  `25`  | รีเลย์  แชแนลที่ 6  |
| `DO7`  | `uint16_t` |  `26`  | รีเลย์  แชแนลที่ 7  |
| `DO8`  | `uint16_t` |  `27`  | รีเลย์  แชแนลที่ 8  |
| `AO1`  | `uint16_t` |  `28`  | Analogoutput แชแนลที่ 1  |
| `AO2`  | `uint16_t` |  `29`  | Analogoutput แชแนลที่ 2  |
| `AO3`  | `uint16_t` |  `30`  | Analogoutput แชแนลที่ 3  |
| `AO4`  | `uint16_t` |  `31`  | Analogoutput  แชแนลที่ 4  |
|`PIDOutput1`|`uint16_t`|`32`| PID Analogoutput แชแนลที่ 1|
|`PIDOutput2`|`uint16_t`|`33`| PID Analogoutput แชแนลที่ 2|
|`PIDOutput3`|`uint16_t`|`34`| PID Analogoutput แชแนลที่ 3|
|`PIDOutput4`|`uint16_t`|`35`| PID Analogoutput แชแนลที่ 4|
|`setpoint1`|`uint16_t`|`36`|ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 1|
|`kp1`|`int`|`37`|ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 1 |
|`ki1`|`int`|`38`|ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 1|
|`kd1`|`int`|`39`|ค่าคงที่อนุพันธ์ Analogoutput แชแนลที่ 1|
|`outMin1`|`uint16_t`|`40`|ค่าต่ำสุดของเอาท์พุต PID Analogoutput แชแนลที่ 1|
|`outMax1`|`uint16_t`|`41`|ค่าสูงสุดของเอาท์พุต PID Analogoutput แชแนลที่ 1|
|`setpoint2`|`uint16_t`|`42`|ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 2|
|`kp2`| `int` |`43`|ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 2|
|`ki2`| `int` |`44`|ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 2|
|`kd2`| `int` |`45`|ค่าคงที่อนุพันธ์ Analogoutput แชแนลที่ 2|
|`outMin2`|`uint16_t`|`46`|ค่าต่ำสุดของเอาท์พุต PID Analogoutput แชแนลที่ 2|
|`outMax2`|`uint16_t`|`47`|ค่าสูงสุดของเอาท์พุต PID Analogoutput แชแนลที่ 2|
|`setpoint3`|`uint16_t`|`48`|ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 3|
|`kp3`| `int` |`49`|ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 3|
|`ki3`| `int` |`50`|ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 3|
|`kd3`| `int` |`51`|ค่าคงที่อนุพันธ์ Analogoutput แชแนลที่ 3|
|`outMin3`|`uint16_t`|`52`|ค่าต่ำสุดของเอาท์พุต PID Analogoutput แชแนลที่ 3|
|`outMax3`|`uint16_t`|`53`|ค่าสูงสุดของเอาท์พุต PID Analogoutput แชแนลที่ 3|
|`setpoint4`|`uint16_t`|`54`|ค่าเซ็ตพอยต์สำหรับการควบคุม PID Analogoutput แชแนลที่ 4|
|`kp4`| `int` |`55`|ค่าคงที่สัดส่วน Analogoutput แชแนลที่ 4|
|`ki4`| `int` |`56`|ค่าคงที่ปริพันธ์ Analogoutput แชแนลที่ 4|
|`kd4`| `int` |`57`|ค่าคงที่อนุพันธ์ Analogoutput แชแนลที่ 4|
|`outMin4`|`uint16_t`|`58`|ค่าต่ำสุดของเอาท์พุต PID Analogoutput แชแนลที่ 4|
|`outMax2`|`uint16_t`|`59`|ค่าสูงสุดของเอาท์พุต PID Analogoutput แชแนลที่ 4|
|`calAI1`|`int16_t`|`60`| |
|`calAI2`|`int16_t`|`61`| |
|`calAI3`|`int16_t`|`62`| |
|`calAI4`|`int16_t`|`63`| |

**ตัวอย่างการใช้งาน**
