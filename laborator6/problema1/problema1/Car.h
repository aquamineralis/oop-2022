#pragma once

#include "Weather.h"

class Car {
  protected:
    double fuel_capacity;    // measured in l
    double fuel_consumption; // measured in l / 100 km
    const char* name;

  public:
    Car(unsigned capacity, unsigned consumption, const char* name)
        : fuel_capacity(capacity), fuel_consumption(consumption), name(name){};

    virtual unsigned AverageSpeed(Weather weather) = 0;
    virtual double GetFuelCapacity()               = 0;
    virtual double GetFuelConsumption()            = 0;
    virtual const char* GetName()                  = 0;
};
