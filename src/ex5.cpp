#include "Arduino.h"

#define BUTTON_PIN       25
#define LIGHT_SENSOR_PIN 33
#define YELLOW_LED_PIN   12

bool lastButtonState = 0;

void setup(void)
{
	pinMode(BUTTON_PIN, INPUT_PULLDOWN);
	pinMode(YELLOW_LED_PIN, OUTPUT);
	digitalWrite(YELLOW_LED_PIN, LOW);

	Serial.begin(115200);
}

void loop(void)
{
	bool currentButtonState = digitalRead(BUTTON_PIN);

	// Trigger once on press (LOW -> HIGH).
	if (lastButtonState == 0 && currentButtonState == 1)
	{
		int snapshot = analogRead(LIGHT_SENSOR_PIN);

		Serial.print("snapshot=");
		Serial.println(snapshot);

		digitalWrite(YELLOW_LED_PIN, HIGH);
		delay(100);
		digitalWrite(YELLOW_LED_PIN, LOW);
	}

	lastButtonState = currentButtonState;
}
