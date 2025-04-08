#include "Cupra.h"

const char* Cupra::GetName() const {
	return "Cupra";
}

int Cupra::fuelCapacity() const
{
	return 55;
}

int Cupra::fuelConsumption() const
{
	return 7;
}

int Cupra::averageSpeed(Weather weather) const
{
	if (weather == Weather::Rain)
	{
		return 190;
	}
	else if (weather == Weather::Sunny)
	{
		return 240;
	}
	else if (weather == Weather::Snow)
	{
		return 140;
	}
}