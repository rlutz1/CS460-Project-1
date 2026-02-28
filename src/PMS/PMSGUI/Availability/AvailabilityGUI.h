//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_AVAILABILITYGUI_H
#define CS460_PROJECT_1_AVAILABILITYGUI_H
#include <QGridLayout>
#include <QLabel>
#include <QWidget>

struct InitializationPackage;

class AvailabilityGUI : QWidget {
public:
    AvailabilityGUI(QWidget* parent, InitializationPackage initPackage);

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

protected:
    QSize sizeHint() const override;

};


#endif //CS460_PROJECT_1_AVAILABILITYGUI_H