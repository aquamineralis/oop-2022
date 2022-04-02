#include "Circuit.h"
#include <iostream>
#include <algorithm>
#include <float.h>

double Circuit::FinishTime(Car* car) const {
    double distance = car->GetFuelCapacity() / car->GetFuelConsumption() * 100;
    if (distance < length)
        return DBL_MAX;
    return length / car->AverageSpeed(weather);
}

void Circuit::SetLength(double length) {
    this->length = length;
}

void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
}

void Circuit::AddCar(Car* car) {
    Cars.push_back(car);
}

void Circuit::Race() {
    std::sort(Cars.begin(), Cars.end(), [this](Car* a, Car* b) { return FinishTime(a) < FinishTime(b); });
}

void Circuit::ShowFinalRanks() const {
    std::cout << "Final rank:\n";
    for (unsigned i = 0; i < Cars.size() && FinishTime(Cars[i]) != DBL_MAX; i++)
        std::cout << i + 1 << ". " << Cars[i]->GetName() << " finished the circuit in " << FinishTime(Cars[i])
                  << " hours\n";
    std::cout << '\n';
}

void Circuit::ShowWhoDidNotFinish() const {
    std::cout << "Cars that didn't finish the circuit:\n";
    for (unsigned i = 0; i < Cars.size(); i++)
        if (FinishTime(Cars[i]) == DBL_MAX)
            std::cout << i + 1 << ". " << Cars[i]->GetName() << '\n';
    std::cout << '\n';
}
