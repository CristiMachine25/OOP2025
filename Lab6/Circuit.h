#pragma once
#include "Weather.h"
#include "Car.h"
#include <stdio.h>

class Circuit
{
private:
	static const int MAX_CARS = 10;
	int length;
	Weather weather;
	Car* cars[10];
	int numberOfCars = 0;
	
	double finishTimes[MAX_CARS];
	bool didFinish[MAX_CARS];
	int originalIndex[MAX_CARS];

	void sortIndicesByTime(int indicesToSort[], int count);
public:
	Circuit(); //constructor
	~Circuit(); //destructor
	//functii pentru masini
	void SetLength(int length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void CanRace(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

