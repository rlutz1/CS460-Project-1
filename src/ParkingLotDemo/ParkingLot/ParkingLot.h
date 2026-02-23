//
// Created by lutzr on 2/22/2026.
//

#ifndef CS460_PROJECT_1_PARKINGLOT_H
#define CS460_PROJECT_1_PARKINGLOT_H

#include <QObject>
#include <string>
class Mediator;

// namespace ParkingLot {
class ParkingLot : public QObject {

public:
    ParkingLot();
    ParkingLot(Mediator* pmc);

    void add_output_stream(Mediator* pmc);
    void hardware_update(std::string str);
    public slots:
        void send_signal();
private:
    Mediator* mediator;
};
// } // ParkingLot

#endif //CS460_PROJECT_1_PARKINGLOT_H