//
// Created by Eliud Garcia on 3/3/26.
//

#ifndef CS460_PROJECT_1_IPARKINGSPOTHARDWARESINK_H
#define CS460_PROJECT_1_IPARKINGSPOTHARDWARESINK_H

class IParkingSpotHardwareSink {
    public:
    ~IParkingSpotHardwareSink() = default;

    virtual void markSpotAvailable() = 0;
    virtual void markSpotOccupied() = 0;
    virtual void markSpotUnavailable() = 0;
};

#endif //CS460_PROJECT_1_IPARKINGSPOTHARDWARESINK_H