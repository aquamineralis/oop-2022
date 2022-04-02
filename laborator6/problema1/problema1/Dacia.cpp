#include "Dacia.h"

unsigned Dacia::AverageSpeed(Weather weather) {
    switch (weather) {
    case Weather::Rainy:
        return 37;
        break;
    case Weather::Sunny:
        return 59;
        break;
    case Weather::Snowy:
        return 27;
        break;
    default:
        return 0;
        break;
    }
}

double Dacia::GetFuelCapacity() {
    return fuel_capacity;
}

double Dacia::GetFuelConsumption() {
    return fuel_consumption;
}

const char* Dacia::GetName() {
    return name;
}
