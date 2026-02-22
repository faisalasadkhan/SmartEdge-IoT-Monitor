#include "Sensor.h"
#include <cstdlib>
#include <ctime>

Sensor::Sensor() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

SensorData Sensor::readData() {
    SensorData data;

    // Simulated realistic environmental values
    data.temperature = 15 + (std::rand() % 2000) / 100.0;   // 15°C – 35°C
    data.humidity = 30 + (std::rand() % 6000) / 100.0;      // 30% – 90%
    data.airQuality = 50 + (std::rand() % 200);             // AQI simulation

    return data;
}
