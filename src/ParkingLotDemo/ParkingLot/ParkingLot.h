//
// Created by lutzr on 2/22/2026.
//

#ifndef CS460_PROJECT_1_PARKINGLOT_H
#define CS460_PROJECT_1_PARKINGLOT_H


#include <QPushButton>
#include <string>
#include <vector>

class Mediator;
class ParkingSpot;

// namespace ParkingLot {
class ParkingLot : public QWidget {

public:
    ParkingLot();
    ParkingLot(Mediator* pmc);

    void add_output_stream(Mediator* pmc);
    void hardware_update(std::string str);
    void add_component(void* component);

    public slots: // slots for signals to send to!
        void send_signal();
private:
    Mediator* mediator;
    // QPushButton* button;
    std::list<ParkingSpot*> parking_spots; // TODO: sizeof issue?

protected:
    QSize sizeHint() const override;
};
// } // ParkingLot

#endif //CS460_PROJECT_1_PARKINGLOT_H