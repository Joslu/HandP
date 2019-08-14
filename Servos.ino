#include <Servo.h>

int pos = 0;
int val1, val2, val3;
char Posicion[10];
int LED = 13;
int voltageThreshold = 890;

Servo ServoOther,ServoIndex,ServoThumb;

void setup()
{
    Serial.begin(9600);
    ServoOther.attach(9);  //Servo other
    ServoIndex.attach(10); //Servo index
    ServoThumb.attach(11); //Servo thumb
    
}

void loop()
{

   
     
    //ServoOther.write(0);
    //ServoIndex.write(150);
    //ServoThumb.write(135);
   // delay(2000);
   
   /* 
    Serial.println("Dedo Pulgar");
    sweepThumb(ServoThumb);
    Serial.println("Dedo Indice");
    sweepIndex(ServoIndex);
    Serial.println("Dedos restantes");
    sweepOther(ServoOther);  
   
 */


//sprintf(Posicion, "%d:%d:%d", val1, val2, val3);
//Serial.println(Posicion);

//moveThumb();
//moveIndex();
//moveOthers();

//Secuencia();

//Close();

 int currentVoltage = analogRead(A6);  
  Serial.println(currentVoltage);    
  delay(5);   
   if(currentVoltage > voltageThreshold){
     
     Serial.println("CONTRACTION!");  
     digitalWrite(LED, HIGH); 
     Close();
  } 

  else if(currentVoltage > 80 && currentVoltage < 600){
        ServoThumb.write(25);


  }
  
  else {
     Serial.println(""); 
     digitalWrite(LED, LOW); 
     Open();
  }
 
}

void sweepThumb(Servo myServo){
     myServo.write(135); //Inicia abierto

    for(pos = 135; pos >= 25; pos--){
        myServo.write(pos);
        Serial.println(pos);
        delay(10);
    }
	

     for(pos = 25; pos <= 135; pos++){
        myServo.write(pos);
        Serial.println(pos);
        delay(10);
    }

    


}

void sweepOther(Servo myServo){
     myServo.write(10); //Inician extendidos
     for(pos = 10; pos <= 120; pos++){
        myServo.write(pos);
        Serial.println(pos);
        delay(10);
    }

    for(pos = 120; pos >= 10; pos--){
        myServo.write(pos);
        Serial.println(pos);
        delay(10);
    }
	


}


void sweepIndex(Servo myServo){
     myServo.write(150); //Inicia extendido

    for(pos = 150; pos >= 10; pos--){
        myServo.write(pos);
        Serial.println(pos);
        delay(10);
    }

     for(pos = 10; pos <= 150; pos++){
        myServo.write(pos);
        Serial.println(pos);
        delay(10);
    }

 
	


}


void moveIndex(){
    val1 = analogRead(A2);
    val1 = map(val1, 0, 1023, 12, 150);
    ServoIndex.write(val1);
}

void moveThumb(){
    val2 = analogRead(A1);
    val2 = map(val2, 0, 1023, 25, 135);
    ServoThumb.write(val2);
}

void moveOthers(){
    val3 = analogRead(A3);
    val3 = map(val3, 0, 1023, 10, 120);
    ServoOther.write(val3);
}

void Secuencia(){
    ServoThumb.write(135); //Inicia abierto
    ServoIndex.write(150);
    ServoOther.write(10);

    for(pos = 10; pos <= 80; pos++){
        ServoOther.write(pos);
        delay(20);
    }


    for(pos = 135; pos >= 25; pos--){
        ServoThumb.write(pos);
        
        delay(10);
    }
    delay(500);
    
    for(pos = 150; pos >= 62; pos--){
        ServoIndex.write(pos);
        delay(10);
    }
	
    delay(3000);

    for(pos = 62; pos <= 150; pos++){
        ServoIndex.write(pos);
        delay(5);
    }

    for(pos = 25; pos <= 130; pos++){
        ServoThumb.write(pos);
    
        delay(5);
    }

    

}

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