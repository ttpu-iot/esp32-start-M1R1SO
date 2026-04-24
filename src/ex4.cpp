#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33
#define BLUE_LED_PIN     14
#define GREEN_LED_PIN    27
#define YELLOW_LED_PIN   12
#define RED_LED_PIN      26

void setup(void)
{
	pinMode(BLUE_LED_PIN, OUTPUT);
	pinMode(GREEN_LED_PIN, OUTPUT);
	pinMode(YELLOW_LED_PIN, OUTPUT);
	pinMode(RED_LED_PIN, OUTPUT);

	Serial.begin(115200);
}

void loop(void)
{
	int raw = analogRead(LIGHT_SENSOR_PIN);

	const char *band = "";

	// Exactly one LED is HIGH in each range.
	if (raw <= 1023)
	{
		digitalWrite(BLUE_LED_PIN, HIGH);
		digitalWrite(GREEN_LED_PIN, LOW);
		digitalWrite(YELLOW_LED_PIN, LOW);
		digitalWrite(RED_LED_PIN, LOW);
		band = "BLUE";
	}
	else if (raw <= 2047)
	{
		digitalWrite(BLUE_LED_PIN, LOW);
		digitalWrite(GREEN_LED_PIN, HIGH);
		digitalWrite(YELLOW_LED_PIN, LOW);
		digitalWrite(RED_LED_PIN, LOW);
		band = "GREEN";
	}
	else if (raw <= 3071)
	{
		digitalWrite(BLUE_LED_PIN, LOW);
		digitalWrite(GREEN_LED_PIN, LOW);
		digitalWrite(YELLOW_LED_PIN, HIGH);
		digitalWrite(RED_LED_PIN, LOW);
		band = "YELLOW";
	}
	else
	{
		digitalWrite(BLUE_LED_PIN, LOW);
		digitalWrite(GREEN_LED_PIN, LOW);
		digitalWrite(YELLOW_LED_PIN, LOW);
		digitalWrite(RED_LED_PIN, HIGH);
		band = "RED";
	}

	Serial.print("band=");
	Serial.println(band);

	delay(500);
}
