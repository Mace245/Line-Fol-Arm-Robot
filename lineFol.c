#include <Arduino.h>

#define motRF A2
#define motRR A3
#define motLF A4
#define motLR A5
#define sensL 27
#define sensR 14
#define spd 3
#define pot A0

bool linefol;

void movInit(){
    pinMode(motRF, OUTPUT);
    pinMode(motRR, OUTPUT);
    pinMode(motLF, OUTPUT);
    pinMode(motLR, OUTPUT);
    pinMode(sensL, INPUT);
    pinMode(sensR, INPUT);
    pinMode(spd, OUTPUT);
}

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