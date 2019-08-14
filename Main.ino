
#include "Definitions.h"


/* Programa para monitorear el comportamiento del prototipo HackBerry (protesís de mano)

                Autor: José Luis Cruz Tecocoatzi

*/


Servo ServoOther,ServoIndex,ServoThumb;



uint8_t state = S_OPEN; //Estado actual lo colocamos en paro


int pos = 0;
int val1, val2, val3;
char Posicion[10];


uint8_t leds[4]{
  12,
  13,
  7,
  6
 };


//Funciones para los movimientos de la mano

void Close(){
  ServoOther.write(120);
  ServoIndex.write(10);
  ServoThumb.write(135);  



}

void Open(){

    ServoOther.write(0);
    ServoIndex.write(150);
    ServoThumb.write(115);
}


void Relax(){

    ServoThumb.write(10);
}







void setup() {
  state = S_OPEN;
  Serial.begin(9600);
  Serial.println();

//Iniciar Servomotores
  ServoOther.attach(9);  //Servo other
  ServoIndex.attach(10); //Servo index
  ServoThumb.attach(11); //Servo thumb

 
  pinMode(SENSOR,OUTPUT);
  
 

}

void loop() {
  
  int currentVoltage = analogRead(A1);  

  switch(state){

    case S_OPEN:
    Open();
    Serial.println("Mano abierta");
    delay(10);
    
   
    
       if(currentVoltage > voltageThreshold){
            Serial.println(currentVoltage);
            state = S_CLOSE;
            break;
        } 

          
       if (currentVoltage > 200 && currentVoltage < 600){
          Serial.println(currentVoltage);
          state = S_RELAX;
          break;
       }  

       if(currentVoltage < 200 ){
            Serial.println(currentVoltage);
            state = S_OPEN;
            break;
        } 

        
    break;

    case S_RELAX:
    Relax();
    Serial.println("Mano Relajada");
    delay(10);
    
      
       if(currentVoltage > voltageThreshold){
            Serial.println(currentVoltage);
            state = S_CLOSE;
            break;
        } 

          
       if (currentVoltage > 200 && currentVoltage < 600){
          Serial.println(currentVoltage);
          state = S_RELAX;
          break;
       }  

       if(currentVoltage < 200 ){
            Serial.println(currentVoltage);
            state = S_OPEN;
            break;
        } 
        

    
    break;


    case S_CLOSE:
    Close();
    Serial.println("Mano cerrada");
    delay(10);

        
       if(currentVoltage > voltageThreshold){
            Serial.println(currentVoltage);
            state = S_CLOSE;
            break;
        } 

          
       if (currentVoltage > 200 && currentVoltage < 600){
          Serial.println(currentVoltage);
          state = S_RELAX;
          break;
       }  

       if(currentVoltage < 200 ){
            Serial.println(currentVoltage);
            state = S_OPEN;
            break;
        } 
         
        
     
    
    break;
      
    
    
    }

}

