#include "RangeRover.h"

const char* RangeRover::GetName() const {
	return "RangeRover";
}

int RangeRover::fuelCapacity() const {
	return 80;
}

int RangeRover::fuelConsumption() const {
	return 20;
}

int RangeRover::averageSpeed(Weather weather) const {
	if (weather == Weather::Rain)
		return 160;
	else if (weather == Weather::Sunny)
		return 180;
	else if(weather == Weather::Snow)
		return 150;
}