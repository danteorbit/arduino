#include <Arduino.h>
#include <Servo.h>

// servo object to control servo 
// max of 12 servo objects can be created on most boards
Servo servo0; 
// position variable
// 0 - 180 degrees +/- 10 degrees
int pos = 0;
// set intial angle (degrees)
int alpha_i = 0;
// set final angle (degrees)
int alpha_f = 180;
// set delay time (ms)
int t = 10;

void setup() {
    // attaches servo on pin 9 to servo object
    servo0.attach(9);
}

void loop() {
    // rotates alpha0 to alpha1 degrees
    // step x degree
    for (pos = alpha_i; pos <= alpha_f; pos += 1) {
        // tell servo what position to go to
        servo0.write(pos);
        // wait t ms
        delay(t);
    }
    // rotates alpha1 to alpha0 degrees
    // step -x degree
    for (pos = alpha_f; pos >= alpha_i; pos -= 1) {
        // tell servo what position to go to
        servo0.write(pos);
        // wait t ms
        delay(t);
    }
}