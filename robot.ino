
#include <AFMotor.h>
#include <Servo.h>

Servo leftservo;
Servo rightservo;

//initial motors pin

int speedlim = 155 ;

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


char command; 

int state;
void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
leftservo.attach(9);
rightservo.attach(10);
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Serial.println(command);
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   

     


   switch(command){
    case 'F':  
      forward();
      Stop();
      break;
    case 'B':  
       back();
       Stop();
      break;
    case 'R':  
      left();
      Stop();
      break;
    case 'L':
      right();
      Stop();
      break;
//custom 
case 'Q':
    leftServo();
      break;

case 'W':
   rightServo();
      break; 
case 'I':
    leftServo();
      break;

case 'O':
    leftDownServo();
      break; 
case 'Z':
    rightDownServo();
      break;
case 'X':
    allDownServo();
      break;
  
////////////////////////voice 

 case 'f':  
      forward();
     // Stop();
      break;
    case 'b':  
       back();
      // Stop();
      break;
    case 'l':  
      left();
    //  Stop();
      break;
    case 'r':
      right();
    //  Stop();
      break;

      
  case 's':
      Stop();
      break;

      
      
    
      
    }
  } 
}

void forward()
{
  motor1.setSpeed(speedlim); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(speedlim); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(speedlim);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(speedlim);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
   delay(500);
}

void back()
{
  motor1.setSpeed(speedlim); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(speedlim); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(speedlim); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(speedlim); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
  delay(500); 
}

void left()
{
  motor1.setSpeed(speedlim); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(speedlim); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(speedlim); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(speedlim); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
  delay(500);
}

void right()
{
  motor1.setSpeed(speedlim); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(speedlim); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(speedlim); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(speedlim); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
  delay(500);
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button

}
void leftServo(){
   Serial.println("LS");
 leftservo.write(45);
 delay(100); 
 Stop();
  }
  
void leftDownServo(){
   Serial.println("LDS");
 leftservo.write(0);
 delay(100);
  
  }

void rightServo(){
   Serial.println("RS");
 rightservo.write(45);
 delay(100); 
  }
 void rightDownServo(){
   Serial.println("RSD");
 rightservo.write(0);
 delay(100); 
  }


  void  allDownServo(){
    
  rightservo.write(0);
  leftservo.write(0);
  delay(100); 
    
    }





 
