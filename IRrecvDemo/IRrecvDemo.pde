#include <IRremote.h>
#include <LiquidCrystal.h>

int RECV_PIN = 8;
int POS;
int SPEED;
long SIGNAL;

IRrecv irrecv(RECV_PIN);
decode_results results;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
    lcd.begin(16, 2);
    lcd.print("start");
    Serial.println("start");

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

//    SIGNAL = results.value;    //SIGNAL = POS | SPEED
//    //SIGNAL = 0x119407D0;/////////////TEST
//    SPEED = SIGNAL | SPEED;
//    SIGNAL = SIGNAL >> 16;
//    POS = SIGNAL | POS;
//
//    Serial.println(POS);
//    Serial.println(SPEED);
//
//    lcd.setCursor(0, 0);
//    lcd.print("SPEED: ");
//    lcd.print(SPEED);
//
//    lcd.setCursor(0,1);
//    lcd.print("POS:   ");
//    lcd.print(POS);

    irrecv.resume(); // Receive the next value
  }
}
