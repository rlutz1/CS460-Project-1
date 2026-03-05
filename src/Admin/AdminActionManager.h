#ifndef CS460_PROJECT_1_ADMINACTIONMANAGER_H
#define CS460_PROJECT_1_ADMINACTIONMANAGER_H

#include <QPushButton>
#include <QComboBox>
#include <QMainWindow>
#include <QTextEdit>
#include <vector>
#include "../PMS/run_demo.h"
using std::vector;

struct SpotActivity
{
    SpotId spotId;
    bool isAvailable;
};

#include "AdminSocket.h"

class AdminActionManager : public QMainWindow{
    Q_OBJECT

public:
    explicit AdminActionManager(QWidget *parent = 0);
    // explicit AdminActionManager(QWidget *parent = 0, AdminSocket* adminSoc = 0);

private slots:
    void handleAvailability();
    void handleLogout();

private:
    QComboBox *options;
    QComboBox *parking;
    QPushButton *confirmButton;
    QPushButton *logoutButton;
    QTextEdit *actionReporter;
    std::vector<SpotActivity> activities;

    // AdminSocket* adminSocket;
};


#endif //CS460_PROJECT_1_ADMINACTIONMANAGER_H