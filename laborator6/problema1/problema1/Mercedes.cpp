#include "Mercedes.h"

unsigned Mercedes::AverageSpeed(Weather weather) {
    switch (weather) {
    case Weather::Rainy:
        return 60;
        break;
    case Weather::Sunny:
        return 78;
        break;
    case Weather::Snowy:
        return 44;
        break;
    default:
        return 0;
        break;
    }
}

double Mercedes::GetFuelCapacity() {
    return fuel_capacity;
}

double Mercedes::GetFuelConsumption() {
    return fuel_consumption;
}

const char* Mercedes::GetName() {
    return name;
}
