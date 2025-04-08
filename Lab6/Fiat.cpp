#include "Fiat.h"

const char* Fiat::GetName() const {
	return "Fiat";
}

int Fiat::fuelCapacity() const {
	return 50;
}

int Fiat::fuelConsumption() const {
	return 5;
}

int Fiat::averageSpeed(Weather weather) const {
	if (weather == Weather::Rain)
		return 90;
	else if (weather == Weather::Sunny)
		return 120;
	else if (weather == Weather::Snow)
		return 60;
}