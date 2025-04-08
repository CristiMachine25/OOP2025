#include "Circuit.h"
#include <stdio.h>
#include <utility>

Circuit::Circuit() : length(0), weather(Weather::Sunny), numberOfCars(0) {
    for (int i = 0; i < MAX_CARS; ++i) {
        cars[i] = nullptr;
        finishTimes[i] = 0.0;
        didFinish[i] = false;
        originalIndex[i] = -1;
    }
}

Circuit::~Circuit() {
    for (int i = 0; i < numberOfCars; ++i) {
        delete cars[i];
        cars[i] = nullptr;
    }
}

void Circuit::SetLength(int len) {
    if (len > 0) {
        this->length = len;
    }
    else {
        this->length = 100;
    }
}

void Circuit::SetWeather(Weather w) {
    this->weather = w;
}

void Circuit::AddCar(Car* car) {
    if (car == nullptr) {
        return;
    }
    if (numberOfCars < MAX_CARS) {
        this->cars[numberOfCars] = car;
        this->finishTimes[numberOfCars] = 0.0;
        this->didFinish[numberOfCars] = false;
        this->originalIndex[numberOfCars] = numberOfCars;
        this->numberOfCars++;
    }
    else {
        delete car;
    }
}

void Circuit::Race() {
    if (this->length <= 0 || this->numberOfCars == 0) {
        return;
    }

    for (int i = 0; i < this->numberOfCars; ++i) {
        Car* currentCar = this->cars[i];
        if (!currentCar) continue;

        int capacity = currentCar->fuelCapacity();
        int consumption = currentCar->fuelConsumption();
        int speed = currentCar->averageSpeed(this->weather);

        this->didFinish[i] = false;
        this->finishTimes[i] = 0.0;

        if (consumption <= 0 || speed <= 0) {
            continue;
        }

        double maxRange = (static_cast<double>(capacity) / static_cast<double>(consumption)) * 100.0;

        if (maxRange >= this->length) {
            this->didFinish[i] = true;
            this->finishTimes[i] = static_cast<double>(this->length) / static_cast<double>(speed);
        }
    }
}

void Circuit::sortIndicesByTime(int indicesToSort[], int count) {
    bool swapped;
    for (int i = 0; i < count - 1; ++i) {
        swapped = false;
        for (int j = 0; j < count - i - 1; ++j) {
            if (finishTimes[indicesToSort[j]] > finishTimes[indicesToSort[j + 1]]) {
                int temp = indicesToSort[j];
                indicesToSort[j] = indicesToSort[j + 1];
                indicesToSort[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}


void Circuit::ShowFinalRanks() {
    printf("Final ranks:\n");

    int finishedCarIndices[MAX_CARS];
    int finishedCount = 0;

    for (int i = 0; i < numberOfCars; ++i) {
        if (this->didFinish[i]) {
            if (finishedCount < MAX_CARS) {
                finishedCarIndices[finishedCount++] = i;
            }
        }
    }

    if (finishedCount == 0) {
        return;
    }

    sortIndicesByTime(finishedCarIndices, finishedCount);

    for (int rank = 0; rank < finishedCount; ++rank) {
        int carIndex = finishedCarIndices[rank];

        const char* name = this->cars[carIndex]->GetName();
        double timeHours = this->finishTimes[carIndex];
        int timeMinutes = static_cast<int>(timeHours * 60.0 + 0.5);

        printf("%s finished in %d minutes\n", name, timeMinutes);
        // printf("Car %d finished in %d minutes\n", this->originalIndices[carIndex] + 1, timeMinutes);
    }
}

void Circuit::ShowWhoDidNotFinish() {
    bool dnfFound = false;
    for (int i = 0; i < numberOfCars; ++i) {
        if (!this->didFinish[i] && this->cars[i] != nullptr) {
            printf("%s did not finish\n", this->cars[i]->GetName());
            // printf("Car %d did not finish\n", this->originalIndices[i] + 1);
            dnfFound = true;
        }
    }
}