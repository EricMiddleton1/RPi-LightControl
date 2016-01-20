#define LED_COUNT		300

#include <vector>
#include <iostream>
#include <stdint.h>
#include <bcm2835.h>
#include <cmath>
#include "StripModes.h"

uint64_t Millis() {
	return bcm2835_st_read() / 1000;
}

int main() {
	uint64_t nextTime;
	int updateCount = 0;

	StripModeSolid strip(LED_COUNT, Color(0, 0, 0));

	strip.Display();

	nextTime = Millis() + 1000;
	while(1) {
		float hue = std::fmod(36.f * Millis() / 1000.f, 360.f);

		strip.SetColor(Color::HSL(hue, 1.f, 0.5f));

		strip.Display();

		updateCount++;

		uint64_t currentTime = Millis();
		if(currentTime >= nextTime) {
			std::cout << updateCount << " fps" << std::endl;

			updateCount = 0;
			nextTime = currentTime + 1000;
		}
	}

	return 0;
}
