#include <stdio.h>
//#include "stm32f4xx.h"
//#include "stm32f4xx_conf.h"

#include "accelerometer.h"
#include "filter.h"
#include "timer.h"
#include "led.h"

#define NO_TIMEOUT 0
#define TIMEOUT_OCCURRED 1

short interruptStatus;

int main()
{
	int32_t values[3];
	float tilts[3];
	float pitch, roll;

	initAccelerometer();
	
	movingAverageFilter filterX;
	movingAverageFilter filterY;
	movingAverageFilter filterZ;
	
	initializeFilter(&filterX);
	initializeFilter(&filterY);
	initializeFilter(&filterZ);
	
	initTimer();
	initLeds();

	
	while(1) {
		
		// Wait for a timer 3 event to occur
		while(interruptStatus != TIMEOUT_OCCURRED);
		interruptStatus = NO_TIMEOUT;
		
		getAcceleration(values);
		
		updateFilter(&filterX, values[0]);
		updateFilter(&filterY, values[1]);
		updateFilter(&filterZ, values[2]);
		
		getTilt(values, tilts);
		
		pitch = getPitch(values);
		roll = getRoll(values);
		
		flashLeds(pitch, roll);
		
		
		printf("Pitch: %f\n", pitch);
		printf("Roll: %f\n\n", roll);
	}
	
}


