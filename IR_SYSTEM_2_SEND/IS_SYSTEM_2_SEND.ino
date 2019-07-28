//#include <IRremote.h>
//#include <IRremoteInt.h>

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

void setup() {
    Serial.begin (9600);
    Serial.print("sent: ");
   ///Encoder 1
    pinMode (outputA,INPUT);
    pinMode (outputB,INPUT);

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
    //counter = POS;
    Serial.print("Position: ");
    Serial.println(counter);

///**/SPEED = 200; /*test debug*/
//
//
//
//    SIGNAL = POS
//    SIGNAL = SIGNAL << 16;
//    SIGNAL = SIGNAL | SPEED;
//    irsend.sendNEC(SIGNAL,32);
//    Serial.print("sent: ");
//    Serial.println(SIGNAL,HEX);

}
