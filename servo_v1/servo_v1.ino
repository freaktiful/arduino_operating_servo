#include <Servo.h>

int boton = 3;
Servo servo1;
//Servo servo2;
bool operarcasco = false;
bool cascoabierto = false;

long tiempo_anterior;
long diferencia;

int pos = 180;

void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  servo1.attach(9);
  servo1.write(pos);
  //servo2.attach(10);

  attachInterrupt(digitalPinToInterrupt(boton), pulsacion, FALLING);
}

void loop() {
  if(operarcasco){
    Serial.println("operacasco");
    operarcasco = false;
    operarCasco();
  }
}

void pulsacion(){
  diferencia = millis() - tiempo_anterior;
  tiempo_anterior = millis();
  //Serial.println(diferencia);

  if(diferencia > 500){
    operarcasco = true;
  }
}

void operarCasco(){
  if(cascoabierto == false){
    for (pos = 180; pos >= 45; pos -= 1) {
      servo1.write(pos);
      delay(20);
    }
    //servo1.write(80);
    // Go on turning for the right duration
    //delay(20);
    // Stop turning
  //  servo1.write(90);
    Serial.println("casco abierto");
  } else {
    for (pos = 45; pos <= 180; pos += 1) {
      servo1.write(pos);
      delay(20);
    }
    //servo1.write(180);
    // Go on turning for the right duration
    //delay(20);
    // Stop turning
  //  servo1.write(90);
    Serial.println("casco cerrado");
  }
  cascoabierto = !cascoabierto;
}
