// If one keypress results in multiple codes being output, then
// change in IRremoteInt.h:
// #define _GAP 50000

#include <IRremote.h>

int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

int c = 1;

void dump(decode_results *results) {
  int count = results->rawlen;
  Serial.println(c);
  c++;
  Serial.println("For IR Scope: ");
  for (int i = 1; i < count; i++) {

    if ((i % 2) == 1) {
      Serial.print("+");
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    }
    else {
      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println("");
  Serial.println("For Arduino sketch: ");
  Serial.print("unsigned int raw[");
  Serial.print(count, DEC);
  Serial.print("] = {");
  for (int i = 1; i < count; i++) {

    if ((i % 2) == 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    }
    else {
      Serial.print((int)results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(",");
  }
  Serial.print("};");
  Serial.println("");
  Serial.print("irsend.sendRaw(raw,");
  Serial.print(count, DEC);
  Serial.print(",38);");
  Serial.println("");
  Serial.println("");
}

void loop() {
  if (irrecv.decode(&results)) {
    dump(&results);
    irrecv.resume(); // Receive the next value
  }
}


















///*
// * IRremote: IRrecvDump - dump details of IR codes with IRrecv
// * An IR detector/demodulator must be connected to the input RECV_PIN.
// * Version 0.1 July, 2009
// * Copyright 2009 Ken Shirriff
// * http://arcfn.com
// */
//
//#include <IRremote.h>
//
//int RECV_PIN = 12;
//
//IRrecv irrecv(RECV_PIN);
//
//decode_results results;
//
//void setup()
//{
//  Serial.begin(9600);
//  irrecv.enableIRIn(); // Start the receiver
//}
//
//// Dumps out the decode_results structure.
//// Call this after IRrecv::decode()
//// void * to work around compiler issue
//void dump(void *v) {
//  decode_results *results = (decode_results *)v;
////void dump(decode_results *results) {
//  int count = results->rawlen;
//  if (results->decode_type == UNKNOWN) {
//    Serial.println("Could not decode message");
//  }
//  else {
//    if (results->decode_type == NEC) {
//      Serial.print("Decoded NEC: ");
//    }
//    else if (results->decode_type == SONY) {
//      Serial.print("Decoded SONY: ");
//    }
//    else if (results->decode_type == RC5) {
//      Serial.print("Decoded RC5: ");
//    }
//    else if (results->decode_type == RC6) {
//      Serial.print("Decoded RC6: ");
//    }
//    Serial.print(results->value, HEX);
//    Serial.print(" (");
//    Serial.print(results->bits, DEC);
//    Serial.println(" bits)");
//  }
//  Serial.print("Raw (");
//  Serial.print(count, DEC);
//  Serial.print("): ");
//
//  for (int i = 0; i < count; i++) {
//    if ((i % 2) == 1) {
//      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
//    }
//    else {
//      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
//    }
//    Serial.print(" ");
//  }
//  Serial.println("");
//}
//
//
//void loop() {
//  if (irrecv.decode(&results)) {
//    Serial.println(results.value, HEX);
//    dump(&results);
//    irrecv.resume(); // Receive the next value
//  }
//}
