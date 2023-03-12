// servo motor
#include<Servo.h>
Servo myServo;

// potenciometro
const byte pot = A0;
short int valor;

// ldr
const byte ldr = A2;
short int valorLdr = 0;
byte valorLdrMapeado = 0;

// temperatura
const short int sensorTemp = A1;
float sensor;
short int temperatura;

void setup(){
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  myServo.attach(6);
}

void loop(){
  lerPotenciometro();
  lerLdr();
  verificarTemperatura();
  
  myServo.write(valor);
  
  Serial.print("luminosidade:");
  Serial.println(valorLdrMapeado);
               
  Serial.print("temperatura:");
  Serial.println(temperatura);
  
  delay(1000);
}

void lerPotenciometro(){
  valor = analogRead(pot);
  valor = map(valor, 0, 1023, 0, 178);
}

void lerLdr(){
  valorLdr = analogRead(ldr); 
  valorLdrMapeado = map(valorLdr, 49, 969, 0, 255);
}

void verificarTemperatura(){
  sensor = analogRead(sensorTemp)-20;
  sensor = sensor*3.04;
  temperatura = map(sensor,0,1023,-40,125);
}