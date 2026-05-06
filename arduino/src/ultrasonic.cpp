#include <Arduino.h>

long microsecondsToCentimeters(long microseconds)
{
    // speed of sound is 343 m/s or 29.15 microseconds per cm
    // ping travels out and back, to find distance of object
    // take 1/2 of distance traveled
    return microseconds / 29.15 / 2;
}

// trigger and echo pins sensor
const int trigPin = 7;
const int echoPin = 8;
// led pins
const int led0 = 3;
const int led1 = 4;
const int led2 = 5;
const int led3 = 6;
// set threshold
const int threshold = 10;

void setup() {
    // initialize serial communication
    Serial.begin(9600);
    // set output
    pinMode(trigPin, OUTPUT);
    // set led pins
    pinMode(led0, OUTPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    // set input
    pinMode(echoPin, INPUT);
}

void loop() {
    // set variables for duration of ping and distance
    // centimeters
    long duration, cm;
    // PING))) is triggered by HIGH pulse of 2 or more microseconds
    // give short LOW pulse beforehand to ensure clean HIGH pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // time (microseconds) from sending ping to reception of its echo off an object
    duration = pulseIn(echoPin, HIGH);

    // convert time into distance
    cm = microsecondsToCentimeters(duration);

    // led thresholds

    if (cm < threshold) {
        digitalWrite(led0, HIGH);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
    } else if (cm >= threshold && cm < threshold + 10) {
        digitalWrite(led0, LOW);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
    } else if (cm >= threshold + 10 && cm < threshold + 20) {
        digitalWrite(led0, LOW);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
    } else if (cm >= threshold + 20 && cm < threshold + 30) {
        digitalWrite(led0, LOW);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
    } else {
        digitalWrite(led0, LOW);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
    }

        Serial.print(cm);
        Serial.print("cm");
        Serial.println();

        delay(100);
    }