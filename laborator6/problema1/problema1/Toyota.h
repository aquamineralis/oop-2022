#pragma once

#include "Car.h"

class Toyota : public Car {
  public:
    Toyota() : Car(57, 7.3, "Toyota"){};
    unsigned AverageSpeed(Weather weather) override;
    double GetFuelCapacity() override;
    double GetFuelConsumption() override;
    const char* GetName() override;
};
