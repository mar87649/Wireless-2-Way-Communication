#include <IRremote.h>
#include <IRremoteInt.h>
#include <Servo.h>
#include <Stepper.h>


const int stepsPerRevolution = 200;
int DIR;    //direction of joystick
int VAL;    //value of joystick
const int UP    = 0xD86B;  //UP
const int DOWN  = 0xD0FF;  //DOWN
const int LEFT  = 0xD48C;  //LEFT
const int RIGHT = 0xD6FD;   //RIGHT
long      SIGNAL;

int RECV_PIN = 12;
int servo_pin = 14;
int InitialServPos = 90;  //Initial position of the servo is 90 degrees

Stepper myStepper(stepsPerRevolution, 7,8,9,10);
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo;

void setup()
{
  Serial.begin(9600);
  Serial.println("start");
  irrecv.enableIRIn(); // Start the receiver  pinMode(Pin1, OUTPUT);
  servo.attach(servo_pin);
  servo.write(InitialServPos);
}

void loop() {

    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        SIGNAL = results.value;
        VAL = SIGNAL;
        SIGNAL = SIGNAL >> 16;
        DIR = SIGNAL;
//////////////Servo Motor
        if(DIR == LEFT && InitialServPos > 0){
            InitialServPos = InitialServPos-1;
            servo.write(InitialServPos);
            Serial.println(InitialServPos);

        }
        else if(DIR == RIGHT && InitialServPos < 180){
            InitialServPos = InitialServPos+1;
            servo.write(InitialServPos);
            Serial.println(InitialServPos);

        }
        else{
            InitialServPos = InitialServPos;
        }
////////////////STEPPER MOTOR
        if(DIR == UP){
            myStepper.step(stepsPerRevolution/10);
            myStepper.setSpeed(100);///change to variable joystick
            delay(1);
        }
        else if(DIR == DOWN){
            myStepper.step(-stepsPerRevolution/10);
            myStepper.setSpeed(100);///change to variable joystick
            delay(1);
        }
        else{
            myStepper.step(0);
            myStepper.setSpeed(100);
            delay(1);
        }
        irrecv.resume(); // Receive the next value
    }
}
