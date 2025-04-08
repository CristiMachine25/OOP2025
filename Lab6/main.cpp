#include <stdlib.h>
#include <stdio.h>
#include "Circuit.h";
#include "Car.h";
#include "Volvo.h"
#include "BMW.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Cupra.h"
#include "Weather.h"

int main()
{
	Circuit c;
	c.SetLength(600); ///km
	c.SetWeather(Weather::Rain);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Cupra());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}
