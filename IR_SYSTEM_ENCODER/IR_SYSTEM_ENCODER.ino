#include <IRremote.h>
#include <IRremoteInt.h>

//Encoder 1
#define outputA 12
#define outputB 13
int counter = 0;
int aState;
int aLastState;

//IR  LED
long      SIGNAL;
int       POS;
int       SPEED;
////////////////////////////

IRsend irsend;

void setup() {
   Serial.begin (9600);
   Serial.print("Start: ");
   ///Encoder 1
    pinMode (outputA,INPUT);
    pinMode (outputB,INPUT);

    // Reads the initial state of the outputA
    aLastState = digitalRead(outputA);

}

void loop() {
  ///Encoder 1
    aState = digitalRead(outputA);
    if (aState != aLastState){
        if (digitalRead(outputB) != aState) {
          counter = counter + 1;
        } else {
          counter = counter - 1;
        }
    }
    aLastState = aState;

    Serial.print("Position: ");
    Serial.print(counter);
    //Serial.print(counter,HEX);

    POS = counter;
    SIGNAL = 0;
/**/SPEED = 0;/**/
    SIGNAL = POS;
    SIGNAL = SIGNAL << 16;
    SIGNAL = SIGNAL | SPEED;

    Serial.print("     SIGNAL: ");
    Serial.println(SIGNAL,HEX);

    irsend.sendNEC(SIGNAL,32);


}
