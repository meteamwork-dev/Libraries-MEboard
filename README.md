# Libraries-MEboard
--update 14/1/2025--
function
  DOut(channel,output)
    chennel =>select chennel 1-4
    output => 0,1
  
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
