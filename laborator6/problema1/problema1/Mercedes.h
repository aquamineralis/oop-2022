#pragma once

#include "Car.h"

class Mercedes : public Car {
  public:
    Mercedes() : Car(65, 9.3, "Mercedes"){};
    unsigned AverageSpeed(Weather weather) override;
    double GetFuelCapacity() override;
    double GetFuelConsumption() override;
    const char* GetName() override;
};
