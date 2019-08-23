
/* Programa para monitorear el comportamiento del prototipo HackBerry (protesís de mano), 
   es el programa final que realicé.

   El programa incluye un archivo .h donde coloqué las definiciones principales para su uso
   Entre los más importantes son valores de desborde de los sensores, definición de estados.

   El código del bucle esta basado en una máquina de estados, la cual contiene 4 estados 

   S_THUMB    Estado cuando el dedo pulgar es accionado
   S_OPEN     Estado inicial, la mano se encuenta totalmente abierta
   S_CLOSE    Estado donde la mano se cierra completamente
   S_INDEX    Estado donde el dedo indice se flexiona

   Las funciones de transición de estado, estan definidas por las señales que emiten los sensores
   de la pulsera estos valores dependen del ajuste de la pulsera, 
   y generalmente deben adecuarse para que su uso sea optimo, los valores donde se determina
   su funcionamiento lo determinan las constantes voltageThreshold y voltageThreshold2s

                Autor: José Luis Cruz Tecocoatzi

*/

#include "Definitions.h"




Servo ServoOther,ServoIndex,ServoThumb;



uint8_t state = S_OPEN; //Estado actual mano abierta 


int pos = 0;
int val1, val2, val3;
char Valores[10];




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
    ServoIndex.write(15);
    ServoThumb.write(135);
}


void RelaxT(){

    ServoOther.write(0);
    ServoIndex.write(150);
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
    
   


        if(currentVoltage2 < voltageThreshold2 && currentVoltage < voltageThreshold ){
            Serial.println(Valores);
            state = S_CLOSE;
            break;
        } 

       if(currentVoltage2 < 916 && currentVoltage > 898){
           Serial.println(Valores);
           state = S_THUMB;
           break;
       }

       if(currentVoltage <= 903 && currentVoltage2 > 895){
           Serial.println(Valores);
           state = S_INDEX;
           break;
       }
    
    

       if(currentVoltage >= voltageThreshold  && currentVoltage2 >= voltageThreshold2  ){
            Serial.println(Valores);
            state = S_OPEN;
            break;
        } 

        
    break;

    case S_THUMB:
    RelaxT();
    //Close();
    //Open();
    Serial.println("Pulgar abierto");
    delay(10);
    
      
       if(currentVoltage2 < voltageThreshold2 && currentVoltage < voltageThreshold ){
            Serial.println(Valores);
            state = S_CLOSE;
            break;
        } 

        if(currentVoltage2 < 916  && currentVoltage > 894){
           Serial.println(Valores);
           state = S_THUMB;
           break;
       }
       
         if(currentVoltage <= 901 && currentVoltage2 > 895){
           Serial.println(Valores);
           state = S_INDEX;
           break;
       }
    

       if(currentVoltage >= voltageThreshold  && currentVoltage2 >= voltageThreshold2  ){
            Serial.println(Valores);
            state = S_OPEN;
            break;
        } 

    
    break;


    case S_CLOSE:
    Close();
    Serial.println("Mano cerrada");
    delay(10);

       if(currentVoltage2 < voltageThreshold2 && currentVoltage < voltageThreshold ){
            Serial.println(Valores);
            state = S_CLOSE;
            break;
        } 

       if(currentVoltage2 < 916  && currentVoltage > 894){
           Serial.println(Valores);
           state = S_THUMB;
           break;
       }

       if(currentVoltage <= 901 && currentVoltage2 > 895){
           Serial.println(Valores);
           state = S_INDEX;
           break;
       }
    

       if(currentVoltage >= voltageThreshold  && currentVoltage2 >= voltageThreshold2  ){
            Serial.println(Valores);
            state = S_OPEN;
            break;
        } 
        
     
    
    break;


    case S_INDEX:
    RelaxI();
    Serial.println("Dedo Indice");
    delay(10);

       if(currentVoltage2 < voltageThreshold2 && currentVoltage < voltageThreshold ){
            Serial.println(Valores);
            state = S_CLOSE;
            break;
        } 

       if(currentVoltage2 < 899){
           Serial.println(Valores);
           state = S_THUMB;
           break;
       }
    
        if(currentVoltage <= 901 && currentVoltage2 > 895){
           Serial.println(Valores);
           state = S_INDEX;
           break;
       }
    
       if(currentVoltage >= voltageThreshold  && currentVoltage2 >= voltageThreshold2  ){
            Serial.println(Valores);
            state = S_OPEN;
            break;
        } 
        
     
    
    break;
      


    
    
    }

}

