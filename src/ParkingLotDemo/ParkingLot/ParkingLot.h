//
// Created by lutzr on 2/22/2026.
//

#ifndef CS460_PROJECT_1_PARKINGLOT_H
#define CS460_PROJECT_1_PARKINGLOT_H


#include <QPushButton>
#include <QGraphicsView>
#include <string>
#include <vector>


class DemoManager;
class Mediator;
class ParkingSpot;

// namespace ParkingLot {
class ParkingLot : public QGraphicsView {
    Q_OBJECT
public:
    ParkingLot(QWidget *parent);

    void add_output_stream(Mediator* pmc);
    void hardware_update(std::string str);
    void add_component(void* component);
    void send_signal(std::string update);
    void add_to_scene(QGraphicsWidget* widget);

    public slots: // slots for signals to send to!
        void run_demo();
        void stop_demo();
        void trigger_vehicle_parked(std::string spotId, bool vehicle_detected);
        void trigger_vehicle_left(std::string spotId, bool vehicle_detected);
private:
    Mediator* mediator;
    DemoManager* demo_manager;
    QLayout *layout;
    QGraphicsScene *scene;
    std::list<ParkingSpot*> parking_spots; // TODO: sizeof issue?
public:

    [[nodiscard]] std::list<ParkingSpot *> get_parking_spots() const {
        return parking_spots;
    }

protected:
    QSize sizeHint() const override; // this is for controlling basic size of animation view
};

class DemoManager {
public:
    DemoManager(ParkingLot* parent);

    void run(int n_vehicles);
    void stop();
    void init();
private:
    ParkingLot* parent;
};

#endif //CS460_PROJECT_1_PARKINGLOT_H