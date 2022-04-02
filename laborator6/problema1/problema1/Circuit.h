#pragma once

#include "Weather.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"
#include <vector>

class Circuit {
  private:
    double length;
    Weather weather;
    std::vector<Car*> Cars;

    double FinishTime(Car* car) const;

  public:
    void SetLength(double length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);

    void Race();
    void ShowFinalRanks() const;
    void ShowWhoDidNotFinish() const;
};
