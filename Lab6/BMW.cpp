#include "BMW.h"

const char* BMW::GetName() const {
	return "BMW";
}

int BMW::fuelCapacity() const {
	return 60;
}

int BMW::fuelConsumption() const {
	return 12;
}

int BMW::averageSpeed(Weather weather) const {
	if (weather == Weather::Rain) {
		return 200;
	}
	else if (weather == Weather::Sunny) {
		return 220;
	}
	else if (weather == Weather::Snow) {
		return 110;
	}
}
