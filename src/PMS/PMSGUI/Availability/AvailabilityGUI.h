/**
 * this class is to stand in for the availability display driver
 */

#ifndef CS460_PROJECT_1_AVAILABILITYGUI_H
#define CS460_PROJECT_1_AVAILABILITYGUI_H
#include <QGridLayout>
#include <QLabel>
#include <QWidget>

#include "../../PMC/PMCInterfaces/IAvailabilityInstructionSink.h"
#include "../../Initialization.h"
struct InitializationPackage;

class AvailabilityGUI : public QWidget, public IAvailabilityInstructionSink {
public:
    AvailabilityGUI(QWidget* parent, InitializationPackage initPackage);

    InitializationPackage initPackage;

    QGridLayout layout;

    QLabel headerTotalAvail;
    QLabel headerFloor1Avail;
    QLabel headerFloor2Avail;
    QLabel headerInTransit;
    QLabel headerNormalType;
    QLabel headerHandicapType;
    QLabel headerEvType;
    QLabel headerMotorcycleType;
    QLabel headerLog;

    QLabel totalAvailNormal;
    QLabel totalAvailHandicap;
    QLabel totalAvailEv;
    QLabel totalAvailMotorcycle;

    QLabel floor1AvailNormal;
    QLabel floor1AvailHandicap;
    QLabel floor1AvailEv;
    QLabel floor1AvailMotorcycle;

    QLabel floor2AvailNormal;
    QLabel floor2AvailHandicap;
    QLabel floor2AvailEv;
    QLabel floor2AvailMotorcycle;

    QLabel inTransit;

    QLabel log;

    void increaseCount(QLabel& count);
    void decreaseCount(QLabel& countLabel);
    void setStyle();
    void reset();

    // IAvailabilityIntructionSink.h
    void increaseInTransitCount() override;
    void decreaseInTransitCount() override;
    void increaseAvailabilityCount(SpotType spotType, int floor) override;
    bool decreaseAvailabilityCount(SpotType spotType, int floor) override;
    void setLogMsg(std::string) override;

protected:
    QSize sizeHint() const override;
private:
    int getLotTotalAvailable();

};

#endif //CS460_PROJECT_1_AVAILABILITYGUI_H