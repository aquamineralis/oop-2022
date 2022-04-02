#include "Toyota.h"

unsigned Toyota::AverageSpeed(Weather weather) {
    switch (weather) {
    case Weather::Rainy:
        return 45;
        break;
    case Weather::Sunny:
        return 60;
        break;
    case Weather::Snowy:
        return 30;
        break;
    default:
        return 0;
        break;
    }
}

double Toyota::GetFuelCapacity() {
    return fuel_capacity;
}

double Toyota::GetFuelConsumption() {
    return fuel_consumption;
}

const char* Toyota::GetName() {
    return name;
}
