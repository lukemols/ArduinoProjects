#include "pitches.h"

// pin and value for the photoresistor
int analogInPin = A5;
int sensorValue = 0;

// Loop time
int times = 100;

// notes to play, corresponding to the 7 levels:
int notes[] = { NOTE_A4, NOTE_B4, NOTE_C3, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4 };

void setup()
{
	Serial.begin(9600);
	pinMode( analogInPin, INPUT);
}

void loop() 
{
	// read value from the pin
	sensorValue = analogRead(analogInPin);
	
	// play the tone relative to the actual reading
	playTone();

	// decrement the times left
	times--;
	if(times == 0)
		exit(0); // exit if it reaches the 0
	
	// write value and times on the console
	Serial.print("sensor = " );
	Serial.println(sensorValue);
	Serial.print("times left =");
	Serial.println(times);
	
	// wait 1 second
	delay(1000);
}

void playTone()
{
	// divide the space in 6 parts
	int step = 1001 / 6;
	for(int i = 0; i < 7; i++)
	{
		// select the note relative to the actual value of the reading
		if(sensorValue < step * i)
		{
			tone(8, notes[i], 400);
			break;
		}
	}
}

