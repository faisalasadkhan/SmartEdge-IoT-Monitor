#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include "Sensor.h"

class Database {
private:
    sqlite3* db;
public:
    Database(const std::string& dbName);
    ~Database();

    void initialize();
    void insertSensorData(const SensorData& data);
    void insertAlert(const std::string& message, const std::string& severity);
};

#endif
