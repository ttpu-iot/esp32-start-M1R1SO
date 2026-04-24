#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

void setup(void)
{
    pinMode(LIGHT_SENSOR_PIN, INPUT);
    Serial.begin(115200);
}

void loop(void)
{
    int rawValue = analogRead(LIGHT_SENSOR_PIN);
    Serial.print("raw=");
    Serial.println(rawValue);
    delay(500);
}