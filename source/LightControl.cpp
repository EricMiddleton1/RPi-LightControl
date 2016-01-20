#define LED_COUNT		300

#include <vector>
#include <iostream>
#include "SPI.h"
#include "StripModes.h"


int main() {
	StripModeSolid strip(LED_COUNT, Color(0, 0, 0));

	//strip.Display();

	while(1) {
		int r, g, b;

		std::cout << "Enter RGB Values:" << std::endl << "R: ";
		std::cin >> r;

		std::cout << "G: ";
		std::cin >> g;

		std::cout << "B: ";
		std::cin >> b;

		std::cout << "Setting lights to (" << r << ", " << g << ", " << b << ")" << std::endl << std::endl;

		strip.SetColor(Color(r, g, b));
	}

	return 0;
}
