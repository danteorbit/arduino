#include <Arduino.h>

// joystick pins
const int xPin = A0;
const int yPin = A1;
const int buttonPin = A2;

// variables for analog readings
// 0 <= pos <= 1023
int xPos;
int yPos;
int buttonPos;
// centering readings for calibration
int x_center;
int y_center;

// LED pins
const int redPin = 8;
const int greenPin = 9;
const int yellowPin = 10;
const int bluePin = 11;

// LED brightness
int R;
int Y;
int G;
int B;

// deadzone
const int deadzone = 10;

void setup() {
    // initialize serial communication
    Serial.begin(9600);
    // get centered readings for calibration
    // assume JOYSTICK NOT MOVED AT START
    x_center = analogRead(xPin);
    y_center = analogRead(yPin);
}

void loop() {
    // read analog pins
    xPos = analogRead(xPin);
    yPos = analogRead(yPin);
    buttonPos = analogRead(buttonPin);

    if (yPos >= y_center + deadzone) {
        // joystick +y
        // blue LED off
        B = 0;
        // green LED
        G = map(yPos, y_center, 1023, 0, 255);
    } else if (yPos <= y_center - deadzone) {
        // joystick -y
        // green LED off
        G = 0;
        // blue LED
        B = map(yPos, y_center, 0, 0, 255);
    } else {
        G = B = 0;
    }

    if (xPos >= x_center + deadzone) {
        // joystick +x
        // yellow LED off
        Y = 0;
        // yellow LED
        R = map(xPos, x_center, 1023, 0, 255);
    } else if (xPos <= x_center - deadzone) {
        // joystick -x
        // yellow LED off
        R = 0;
        // red LED
        Y = map(xPos, x_center, 0, 0, 255);
    } else {
        R = Y = 0;
    }

    if (buttonPos < deadzone && 
        yPos >= y_center - deadzone && 
        yPos <= y_center + deadzone && 
        xPos >= x_center - deadzone && 
        xPos <= x_center + deadzone) {
        // joystick button pressed (calibrated for accidental mechanical press)
        // all LEDs on
        G = B = Y = R = 255;
    }

    analogWrite(redPin, R);
    analogWrite(greenPin, G);
    analogWrite(yellowPin, Y);
    analogWrite(bluePin, B);

    // print values
    // Serial.print("xPos: ");
    // Serial.print(xPos);
    // Serial.print(" yPos: ");
    // Serial.print(yPos);
    // Serial.print(" buttonPos: ");
    // Serial.println(buttonPos);
}