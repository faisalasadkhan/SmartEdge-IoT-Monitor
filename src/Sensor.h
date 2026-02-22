#ifndef SENSOR_H
#define SENSOR_H

struct SensorData {
    double temperature;
    double humidity;
    double airQuality;
};

class Sensor {
public:
    Sensor();
    SensorData readData();
};

#endif
