#include "AlertEngine.h"
#include <iostream>

void AlertEngine::evaluate(const SensorData& data, Database& db) {

    if (data.temperature > 35.0) {
        std::cout << "High Temperature Alert Triggered!\n";
        db.insertAlert("High Temperature Detected", "HIGH");
    }

    if (data.airQuality > 150.0) {
        std::cout << "Critical Air Quality Alert Triggered!\n";
        db.insertAlert("Critical Air Quality Level", "CRITICAL");
    }
}
