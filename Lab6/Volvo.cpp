#include "Volvo.h"

const char* Volvo::GetName() const {
	return "Volvo";
}

int Volvo::fuelCapacity() const {
	return 60;
}

int Volvo::fuelConsumption() const {
	return 6;
}

int Volvo::averageSpeed(Weather weather) const {
	if (weather == Weather::Rain)
		return 110;
	else if (weather == Weather::Sunny)
		return 150;
	else if (weather == Weather::Snow)
		return 90;
}