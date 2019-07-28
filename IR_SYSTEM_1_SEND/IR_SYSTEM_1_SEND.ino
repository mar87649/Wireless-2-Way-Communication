#include <IRremote.h>
#include <Joystick.h>


const int xPin = 2;
const int yPin = 6;
const int pushPin = 5;
const int analogRes = 4095;

const int UP    = 0xD86B;  //UP
const int DOWN  = 0xD0FF;  //DOWN
const int LEFT  = 0xD48C;  //LEFT
const int RIGHT = 0xD6FD;   //RIGHT
long      SIGNAL;

//const int BUTTON = 0xF4BA2988;  //BUTTON

IRsend irsend;
Joystick joy(xPin, yPin, pushPin, analogRes);

void setup()
{
    joy.begin();
    Serial.begin(9600);
    Serial.println("start");
}

void loop() {
    SIGNAL = 0;

    if(joy.readX() < 200){
        SIGNAL = UP;
        SIGNAL = SIGNAL << 16;
        SIGNAL = SIGNAL | joy.readX();
        irsend.sendNEC(SIGNAL,32); //UP
        Serial.print("sent: ");
        Serial.println(SIGNAL,HEX);
        delay(100);
    }
    else if(joy.readX() > 700){
        SIGNAL = DOWN;
        SIGNAL = SIGNAL << 16;
        SIGNAL = SIGNAL | joy.readX();
        irsend.sendNEC(SIGNAL,32); //DOWN
        Serial.print("sent: ");
        Serial.println(SIGNAL,HEX);
        delay(100);
    }
    else if(joy.readY() < 200){
        SIGNAL = LEFT;
        SIGNAL = SIGNAL << 16;
        SIGNAL = SIGNAL | joy.readY();
        irsend.sendNEC(SIGNAL,32); //LEFT
        Serial.print("sent: ");
        Serial.println(SIGNAL,HEX);
        delay(100);
    }
    else if(joy.readY() > 700){
        SIGNAL = RIGHT;
        SIGNAL = SIGNAL << 16;
        SIGNAL = SIGNAL | joy.readY();
        irsend.sendNEC(SIGNAL,32);
        Serial.print("sent: ");
        Serial.println(SIGNAL,HEX);
        delay(100);
    }
}
//////////////////////
