#include "Mazda.h"

unsigned Mazda::AverageSpeed(Weather weather) {
    switch (weather) {
    case Weather::Rainy:
        return 38;
        break;
    case Weather::Sunny:
        return 67;
        break;
    case Weather::Snowy:
        return 35;
        break;
    default:
        return 0;
        break;
    }
}

double Mazda::GetFuelCapacity() {
    return fuel_capacity;
}

double Mazda::GetFuelConsumption() {
    return fuel_consumption;
}

const char* Mazda::GetName() {
    return name;
}
