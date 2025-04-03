//Deklarasi I/O
#include <Servo.h>
#include <SoftwareSerial.h>

#define motRF A2
#define motRR A3
#define motLF A4
#define motLR A5
#define sensL 27
#define sensR 14
#define spd 3
#define pot A0

#define spinPin 11
#define bigArmPin 10
#define smallArmPin 6
#define gripPin 5

SoftwareSerial SerialBT(10, 11);
Servo spin, bigArm, smallArm, grip;

bool linefol;

// forward 1 11
// backward 4
// right 2 12
// left 3 13
void mov(int dir){
  if (dir == 10){
    Serial.println("mov Stop");
    digitalWrite(motLF, HIGH);
    digitalWrite(motLR, LOW);
    digitalWrite(motRF, HIGH);
    digitalWrite(motRR, LOW);
  }

  if (dir == 11){
    Serial.println("mov Forward");
    digitalWrite(motLF, HIGH);
    digitalWrite(motLR, LOW);
    digitalWrite(motRF, HIGH);
    digitalWrite(motRR, LOW);
  }

  if (dir == 12){
    Serial.println("mov Right");
    digitalWrite(motLF, HIGH);
    digitalWrite(motLR, LOW);
    digitalWrite(motRF, LOW);
    digitalWrite(motRR, HIGH);
  }

  if (dir == 13){
    Serial.println("mov Left");
    digitalWrite(motLF, LOW);
    digitalWrite(motLR, HIGH);
    digitalWrite(motRF, HIGH);
    digitalWrite(motRR, LOW);
  }

  if (dir == 14) {
    linefol = true;
  }

  if (dir == 14) {
    linefol = false;
  }
}

int angleSpin = 50, angleBigArm = 30, angleSmallArm = 35, angleGrip = 50;

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

void linefowl(){
    if((digitalRead(sensR)==0)&&(digitalRead(sensL)==0)){
  digitalWrite(motLF, HIGH);
  digitalWrite(motLR, LOW);
  digitalWrite(motRF, HIGH);
  digitalWrite(motRR, LOW);
  }
    if((digitalRead(sensR)==1)&&(digitalRead(sensL)==0)){
  digitalWrite(motLF, HIGH);
  digitalWrite(motLR, LOW);
  digitalWrite(motRF, LOW);
  digitalWrite(motRR, HIGH);
  }
    if((digitalRead(sensR)==0)&&(digitalRead(sensL)==1)){
  digitalWrite(motLF, LOW);
  digitalWrite(motLR, HIGH);
  digitalWrite(motRF, HIGH);
  digitalWrite(motRR, LOW);
  }
    if((digitalRead(sensR)==1)&&(digitalRead(sensL)==1)){
  digitalWrite(motLF, LOW);
  digitalWrite(motLR, LOW);
  digitalWrite(motRF, LOW);
  digitalWrite(motRR, LOW);
  }
}

void setup(){
  // Deklarasi mode Pin
  pinMode(motRF, OUTPUT);
  pinMode(motRR, OUTPUT);
  pinMode(motLF, OUTPUT);
  pinMode(motLR, OUTPUT);
  pinMode(sensL, INPUT);
  pinMode(sensR, INPUT);
  pinMode(spd, OUTPUT);

  spin.attach(spinPin);
  bigArm.attach(bigArmPin);
  smallArm.attach(smallArmPin);
  grip.attach(gripPin);

  SerialBT.begin(9600);
}

char character;
int cmd_int;

void loop() {
  String cmd = "";
  analogWrite(spd, analogRead(pot));
  while (SerialBT.available()){
    character = SerialBT.read();
    cmd.concat(character);
    cmd_int = cmd.toInt();
    delay(10);
  }
    if (cmd_int > 9 && cmd_int < 20){
      mov(cmd_int);
      digitalWrite(13, HIGH);
    }

    if (cmd_int > 19 && cmd_int < 30){
      arm(cmd_int);
      digitalWrite(13, LOW);
    }

  if (linefol == true){
    linefowl();
  }

}
