

#ifndef Functions_h
#define Functions_h

#include "Arduino.h"
#include <Servo.h>

//Estados de la máquina de estados
#define S_THUMB 0
#define S_OPEN 1
#define S_CLOSE 2
#define S_INDEX 3



#define SENSOR A0
#define SENSOR2 A1
#define LED 13
#define voltageThreshold 895 ///mayor a este valor musculo RELAJADO, MENOr TENSADO
#define voltageThreshold2 890 ///mayor a este valor musculo RELAJADO, MENOr TENSADO






#endif