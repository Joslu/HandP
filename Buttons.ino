
 int pinButtonCalib = A1;
 int pinButtonTBD = A2;
 int pinButtonThumb = A3;
 int pinButtonOther = A4;

void setup()
{
    Serial.begin(9600);
    pinButtonCalib = A1;
    pinButtonTBD = A2;
    pinButtonThumb = A3;
    pinButtonOther = A4;

    pinMode(pinButtonCalib, INPUT_PULLUP);
    pinMode(pinButtonTBD,   INPUT_PULLUP);
    pinMode(pinButtonThumb, INPUT_PULLUP);
    pinMode(pinButtonOther, INPUT_PULLUP);
}

void loop()
{
	Serial.println(readButton(pinButtonCalib));
    Serial.print(analogRead(A0));
    delay(100);

}



boolean isDigitalPin(const int pin){
    return (pin >= 0) && (pin <= 19) ? true: false;

}

boolean readButton(const int pin){
    if (isDigitalPin(pin)){
        return digitalRead(pin);
    } else{
        if (analogRead(pin) > 512) return HIGH;
        else return LOW;
    }


}