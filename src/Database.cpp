#include "Database.h"
#include <iostream>

Database::Database(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Error: Cannot open database\n";
    }
}

Database::~Database() {
    sqlite3_close(db);
}

void Database::initialize() {
    const char* sqlSensor =
        "CREATE TABLE IF NOT EXISTS sensor_data ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "temperature REAL,"
        "humidity REAL,"
        "air_quality REAL,"
        "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);";

    const char* sqlAlert =
        "CREATE TABLE IF NOT EXISTS alerts ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "message TEXT,"
        "severity TEXT,"
        "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);";

    char* errMsg = nullptr;

    sqlite3_exec(db, sqlSensor, nullptr, nullptr, &errMsg);
    sqlite3_exec(db, sqlAlert, nullptr, nullptr, &errMsg);
}

void Database::insertSensorData(const SensorData& data) {
    std::string sql =
        "INSERT INTO sensor_data (temperature, humidity, air_quality) VALUES (" +
        std::to_string(data.temperature) + "," +
        std::to_string(data.humidity) + "," +
        std::to_string(data.airQuality) + ");";

    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}

void Database::insertAlert(const std::string& message, const std::string& severity) {
    std::string sql =
        "INSERT INTO alerts (message, severity) VALUES ('" +
        message + "','" + severity + "');";

    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}
