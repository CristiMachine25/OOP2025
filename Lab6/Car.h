#pragma once
#include "Weather.h"
class Car
{
public:
	virtual ~Car() {};
	const virtual char* GetName() const = 0;
	virtual int fuelCapacity() const = 0;
	virtual int fuelConsumption() const = 0;
	virtual int averageSpeed(Weather weather) const = 0;
};
