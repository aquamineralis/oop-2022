#include "Ford.h"

unsigned Ford::AverageSpeed(Weather weather) {
    switch (weather) {
    case Weather::Rainy:
        return 43;
        break;
    case Weather::Sunny:
        return 74;
        break;
    case Weather::Snowy:
        return 42;
        break;
    default:
        return 0;
        break;
    }
}

double Ford::GetFuelCapacity() {
    return fuel_capacity;
}

double Ford::GetFuelConsumption() {
    return fuel_consumption;
}

const char* Ford::GetName() {
    return name;
}
