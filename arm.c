#include <Servo.h>
#include <Arduino.h>

// TODO : handle serial calls

#define spinPin 11
#define bigArmPin 10
#define smallArmPin 6
#define gripPin 5

Servo spin, bigArm, smallArm, grip;

int angleSpin = 50, angleBigArm = 30, angleSmallArm = 35, angleGrip = 50;

void armInit(){
    spin.attach(spinPin);
    bigArm.attach(bigArmPin);
    smallArm.attach(smallArmPin);
    grip.attach(gripPin);
}

void arm(int dir){
  if (dir == 20){
    if (angleSmallArm <= 180){
      angleSmallArm += 5;
      smallArm.write(angleSmallArm);
    }
    Serial.println(angleSmallArm);
  }

  if (dir == 21){
    if (angleSmallArm >= 80){
      angleSmallArm -= 5;
      smallArm.write(angleSmallArm);
    }
    Serial.println(angleSmallArm);
  }    

  if (dir == 22){
    Serial.println("\nAngle");
    if (angleSpin >= 5){
      angleSpin -= 5;
      spin.write(angleSpin);
    }
    
    Serial.println(angleSpin);
  }
  
  if (dir == 23){
    Serial.println("\nAngle");
    if (angleSpin <= 175){
      angleSpin += 5;
      spin.write(angleSpin);
    }
    
    Serial.println(angleSpin);
  }

  if (dir == 24){
    Serial.println("\nsmallArm");
    if (angleBigArm <= 60){
      angleBigArm += 5;
      bigArm.write(angleBigArm);
    }
    Serial.println(angleBigArm);
  }

  if (dir == 25){
    Serial.println("\nbigArm");
    if (angleBigArm >= 5){
      angleBigArm -= 5;
      bigArm.write(angleBigArm);
    }  
    Serial.println(angleBigArm);
  }

  if (dir == 26){
    Serial.println("\ngrip off");
    bigArm.write(40);
    Serial.println(40);
  }

  if (dir == 26){
    Serial.println("\ngrip on");
    bigArm.write(60); 
    Serial.println(60);
  }
}