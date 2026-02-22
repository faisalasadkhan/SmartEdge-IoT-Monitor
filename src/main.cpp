#include <iostream>
#include <thread>
#include <chrono>

#include "Sensor.h"
#include "Database.h"
#include "AlertEngine.h"

int main() {
    std::cout << "Starting SmartEdge IoT Monitor...\n";

    // Initialize components
    Sensor sensor;
    Database db("iot_data.db");
    AlertEngine alertEngine;

    // Initialize database tables
    db.initialize();

    // Simulate multiple sensor readings
    for (int i = 0; i < 5; ++i) {
        std::cout << "\nReading Sensor Data...\n";

        // Read sensor data
        SensorData data = sensor.readData();

        // Display readings
        std::cout << "Temperature: " << data.temperature << " °C\n";
        std::cout << "Humidity: " << data.humidity << " %\n";
        std::cout << "Air Quality: " << data.airQuality << "\n";

        // Store in database
        db.insertSensorData(data);

        // Evaluate alerts
        alertEngine.evaluate(data, db);

        std::cout << "Data stored successfully.\n";

        // Simulate delay (like real IoT device sending data periodically)
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    std::cout << "\nIoT Monitoring Session Complete.\n";
    return 0;
}
