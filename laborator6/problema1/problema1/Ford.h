#pragma once

#include "Car.h"

class Ford : public Car {
  public:
    Ford() : Car(60, 5.1, "Ford"){};
    unsigned AverageSpeed(Weather weather) override;
    double GetFuelCapacity() override;
    double GetFuelConsumption() override;
    const char* GetName() override;
};