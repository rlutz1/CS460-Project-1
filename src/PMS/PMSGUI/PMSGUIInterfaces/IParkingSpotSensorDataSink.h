//
// Created by Eliud Garcia on 3/3/26.
//

#ifndef CS460_PROJECT_1_IPARKINGSPOTSENSORDATASINK_H
#define CS460_PROJECT_1_IPARKINGSPOTSENSORDATASINK_H

struct SpotId;

class IParkingSpotSensorDataSink {
    public:
    ~IParkingSpotSensorDataSink() = default;

    virtual void vehicleParked(SpotId spotId, SensorId sensorId) = 0;
    virtual void vehicleUnparked(SpotId spotId, SensorId sensorId) = 0;
};

#endif //CS460_PROJECT_1_IPARKINGSPOTSENSORDATASINK_H