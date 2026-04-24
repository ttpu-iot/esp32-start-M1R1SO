#include "Arduino.h"

#define BUTTON_PIN    25
#define GREEN_LED_PIN 27

bool greenState = 0;    
bool lastButtonState = 0; 

void setup(void) 
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLDOWN); 
    Serial.begin(115200);
    digitalWrite(GREEN_LED_PIN, greenState);
}   

void loop(void) 
{
    bool currentButtonState = digitalRead(BUTTON_PIN);

    
    if (lastButtonState == 0 && currentButtonState == 1)
    {
        greenState = !greenState; 

        digitalWrite(GREEN_LED_PIN, greenState);

     
        Serial.print("GREEN=");
        Serial.println(greenState ? 1 : 0);

        delay(50); 
    

    lastButtonState = currentButtonState;
}