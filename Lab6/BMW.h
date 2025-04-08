#pragma once
#include "Car.h";
class BMW : public Car
{
public:
	const char* GetName() const override;
	int fuelConsumption() const override;
	int fuelCapacity() const override;
	int averageSpeed(Weather weather) const override;
};

