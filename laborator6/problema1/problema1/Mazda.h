#pragma once

#include "Car.h"

class Mazda : public Car {
  public:
    Mazda() : Car(55, 7, "Mazda"){};
    unsigned AverageSpeed(Weather weather) override;
    double GetFuelCapacity() override;
    double GetFuelConsumption() override;
    const char* GetName() override;
};
