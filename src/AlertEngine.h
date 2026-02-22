#ifndef ALERTENGINE_H
#define ALERTENGINE_H

#include "Sensor.h"
#include "Database.h"

class AlertEngine {
public:
    void evaluate(const SensorData& data, Database& db);
};

#endif
