#pragma once
#include "Car.h";
class Volvo : public Car
{
public:
	const char* GetName() const override;
	int fuelCapacity() const override;
	int fuelConsumption() const override;
	int averageSpeed(Weather weather) const override;
};

