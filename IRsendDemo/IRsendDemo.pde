/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
unsigned int power[68] = {4500,4400,550,1650,550,1650,550,1650,550,550,550,550,550,550,550,550,600,500,600,1600,600,1600,600,1600,600,500,600,500,600,500,600,500,600,500,600,500,600,1600,600,500,600,500,600,500,600,500,600,500,600,500,600,1600,600,500,600,1600,600,1600,600,1600,600,1600,600,1600,600,1600,600,};


IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
      irsend.sendNEC(0x2FD48B7, 32); // Sony TV power code
      //irsend.sendRaw(power,68,38);
      Serial.println("sent");
      delay(100);

}
//////////////////////



