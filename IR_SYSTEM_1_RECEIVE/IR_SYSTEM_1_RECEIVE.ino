#include <IRremote.h>
#include <LiquidCrystal.h>

int RECV_PIN = 8;
int POS=0;
int SPEED=0;
long SIGNAL = 0;
double DEGREE=0;
double OFFSET = 117;

int POS_0 = 0;
int SPEED_0 = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
//    lcd.begin(16, 2);
//    lcd.print("start");
    Serial.println("start");

}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);

    SIGNAL = results.value;    //SIGNAL = POS | SPEED
    //SIGNAL = 0x119407D0;/////////////TEST
    SPEED = SIGNAL;
    SIGNAL = SIGNAL >> 16;
    POS = SIGNAL;
    DEGREE = (SIGNAL + OFFSET) * 1.8;
//    Serial.println(POS);
//    Serial.println(SPEED);

//    lcd.setCursor(0, 0);
//    lcd.print("SPEED: ");
//    lcd.print(SPEED);
//
//    lcd.setCursor(0,1);
//    lcd.print("POS:   ");
//    lcd.print(POS);

    if(POS_0 != POS || SPEED_0 != SPEED){
        Serial.print("SPEED: ");
        Serial.print(SPEED);

        Serial.print("   ");
        Serial.print("DEGREE:   ");
        Serial.println(DEGREE);

        POS_0 = POS;
        SPEED_0 = SPEED;
    }
//        Serial.print("SPEED: ");
//        Serial.print(SPEED);
//
//        Serial.print("   ");
//        Serial.print("DEGREE:   ");
//        Serial.println(DEGREE);

    irrecv.resume(); // Receive the next value
  }
}
