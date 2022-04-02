#pragma once

#include "Car.h"

class Dacia : public Car {
  public:
    Dacia() : Car(47, 4.9, "Dacia"){};
    unsigned AverageSpeed(Weather weather) override;
    double GetFuelCapacity() override;
    double GetFuelConsumption() override;
    const char* GetName() override;
};
