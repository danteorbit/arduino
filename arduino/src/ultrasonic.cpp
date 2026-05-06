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

void setup() {
    // initialize serial communication
    Serial.begin(9600);
    // set output
    pinMode(trigPin, OUTPUT);
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

    Serial.print(cm);
    Serial.print("cm");
    Serial.println();

    delay(100);
}