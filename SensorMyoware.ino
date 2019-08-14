int LED = 13;
int voltageThreshold = 800;




void setup()
{
	Serial.begin(38400);
    pinMode(LED,OUTPUT);
}

void loop() {
  
  int currentVoltage = analogRead(A6);  
  Serial.println(currentVoltage);    
  delay(5);   
   if(currentVoltage > voltageThreshold){
     
    // Serial.println("CONTRACTION!");  
     digitalWrite(LED, HIGH); 
  } else {
     //Serial.println(""); 
     digitalWrite(LED, LOW); 
    
  }
}