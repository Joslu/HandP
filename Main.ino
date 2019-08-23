
/* Programa para monitorear el comportamiento del prototipo HackBerry (protesís de mano)

                Autor: José Luis Cruz Tecocoatzi

*/

#include "Definitions.h"




Servo ServoOther,ServoIndex,ServoThumb;



uint8_t state = S_OPEN; //Estado actual mano abierta 


int pos = 0;
int val1, val2, val3;
char Valores[10];


uint8_t leds[4]{
  12,
  13,
  7,
  6
 };


//Funciones para los movimientos de la mano

void Close(){
  ServoOther.write(180);
  ServoIndex.write(15);
  ServoThumb.write(50);  
}

void Open(){

    ServoOther.write(0);
    ServoIndex.write(150);
    ServoThumb.write(135);
}

void RelaxI(){

    ServoOther.write(0);
    ServoIndex.write(80);

}


void RelaxT(){

    ServoOther.write(0);
    ServoIndex.write(150);
    ServoThumb.write(40);  
}


void setup() {
  state = S_OPEN;
  Serial.begin(9600);
  Serial.println();

//Iniciar Servomotores
  ServoOther.attach(9);  //Servo other
  ServoIndex.attach(10); //Servo index
  ServoThumb.attach(11); //Servo thumb

 
  
  
 

}

void loop() {
  
  int currentVoltage = analogRead(SENSOR);  
  int currentVoltage2 = analogRead(SENSOR2); 
  sprintf(Valores, "%d:%d", currentVoltage, currentVoltage2);

  switch(state){

    case S_OPEN:
    Open();
    Serial.println("Mano abierta");
    delay(10);
    
   
    
       if(currentVoltage > voltageThreshold){
            Serial.println(Valores);
            state = S_CLOSE;
            break;
        } 

        if(currentVoltage2 > voltageThreshold2){
            Serial.println(Valores);
            state = S_THUMB;
            break;
        } 

          
       if (currentVoltage > 200 && currentVoltage < 500){
          Serial.println(Valores);
          state = S_THUMB;
          break;
       }  

        if (currentVoltage > 500 && currentVoltage < voltageThreshold){
          Serial.println(Valores);
          state = S_INDEX;
          break;
       }  

       if(currentVoltage < 200 ){
            Serial.println(Valores);
            state = S_OPEN;
            break;
        } 

        
    break;

    case S_THUMB:
    //RelaxT();
    Close();
    //Open();
    Serial.println("Pulgar abierto");
    delay(10);
    
      
       if(currentVoltage > voltageThreshold){
            Serial.println(Valores);
            state = S_CLOSE;
            break;
        } 

        if(currentVoltage2 > voltageThreshold2){
            Serial.println(Valores);
            state = S_THUMB;
            break;
        } 

          
       if (currentVoltage > 200 && currentVoltage < 500){
          Serial.println(Valores);
          state = S_THUMB;
          break;
       }  

        if (currentVoltage > 500 && currentVoltage < voltageThreshold){
          Serial.println(Valores);
          state = S_INDEX;
          break;
       }  

       if(currentVoltage < 200 ){
            Serial.println(Valores);
            state = S_OPEN;
            break;
        } 
        

    
    break;


    case S_CLOSE:
    Open();
    //Close();
    Serial.println("Mano cerrada");
    delay(10);

        
       if(currentVoltage > voltageThreshold){
            Serial.println(Valores);
            state = S_CLOSE;
            break;
        } 

        if(currentVoltage2 > voltageThreshold2){
            Serial.println(Valores);
            state = S_THUMB;
            break;
        } 


          
       if (currentVoltage > 200 && currentVoltage < 500){
          Serial.println(Valores);
          state = S_OPEN;
          break;
       }  

        if (currentVoltage > 500 && currentVoltage < voltageThreshold){
          Serial.println(Valores);
          state = S_OPEN;
          break;
       }  

       if(currentVoltage < 200 ){
            Serial.println(Valores);
            state = S_OPEN;
            break;
        } 
         
        
     
    
    break;
      

    case S_INDEX:
    //Open();
    Close();
    //RelaxI();
    Serial.println("Dedo indice ");
    delay(10);

        
       if(currentVoltage > voltageThreshold){
            Serial.println(Valores);
            state = S_CLOSE;
            break;
        } 

        if(currentVoltage2 > voltageThreshold2){
            Serial.println(Valores);
            state = S_THUMB;
            break;
        } 

          
       if (currentVoltage > 200 && currentVoltage < 500){
          Serial.println(Valores);
          state = S_THUMB;
          break;
       }  

       if (currentVoltage > 500 && currentVoltage < voltageThreshold){
          Serial.println(Valores);
          state = S_INDEX;
          break;
       }  

       if(currentVoltage < 200 ){
            Serial.println(Valores);
            state = S_OPEN;
            break;
        } 
         
        
     
    
    break;  
    
    
    }

}

