#include "AdminActionManager.h"

#include <QWidget>
#include <QProcess>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>

#include "../PMS/Definitions/Identifiers.h"
#include "../PMS/Initialization.h"
#include "../PMS/run_demo.h"
#include <vector>
using std::vector;


AdminActionManager::AdminActionManager(QWidget* parent) : QMainWindow(parent)
// AdminActionManager::AdminActionManager(QWidget* parent, AdminSocket* adminSoc) : QMainWindow(parent), adminSocket(adminSoc)
{
    setWindowTitle("Main Page");
    setFixedSize(600, 300);
    QWidget* mainWindow = new QWidget();
    QVBoxLayout* confirmLayout = new QVBoxLayout(mainWindow);

    // Admin Actions for parking lot
    options = new QComboBox();
    options -> addItem("Make Available");
    options -> addItem("Make Unavailable");

    // Parking spots list
    InitializationPackage initPackage = genInitPackage();
    parking = new QComboBox();
    for (SpotId id : initPackage.spotIds)
    {
        if (id.uniqueId.find("spot") != std::string::npos)
        activities.push_back({id, true});
    }
    for (SpotActivity id : activities)
    {
        parking -> addItem(id.spotId.uniqueId.data());
    }
    // parking -> addItem("ID001");
    // parking -> addItem("ID002");
    // parking -> addItem("ID003");

    // Buttons to confirm actions or logout
    confirmButton = new QPushButton("Confirm");
    connect(confirmButton, &QPushButton::clicked, this, &AdminActionManager::handleAvailability);
    logoutButton = new QPushButton("Logout");
    connect(logoutButton, &QPushButton::clicked, this, &AdminActionManager::handleLogout);

    // Message recording admin actions
    actionReporter = new QTextEdit(this);
    actionReporter -> setReadOnly(true);

    // Organizing the entire window
    QHBoxLayout* minorLayout = new QHBoxLayout();
    minorLayout -> addWidget(options);
    minorLayout -> addWidget(parking);
    minorLayout -> addWidget(confirmButton);
    minorLayout -> addWidget(logoutButton);
    confirmLayout -> addLayout(minorLayout);
    confirmLayout -> addWidget(actionReporter);
    setCentralWidget(mainWindow);
}

/**
 * Upon confirming admin action, will update associated items
 */
void AdminActionManager::handleAvailability()
{
    QString optionSelected = options->currentText();
    QString selectedParking = parking->currentText();
    std::vector<SpotActivity>::iterator it = std::find_if(activities.begin(),
        activities.end(), [&](const SpotActivity &a)
        {
            return a.spotId.uniqueId.data() == selectedParking;
        });
    // QString message;
    if (optionSelected == "Make Available")
    {
        if (it->isAvailable == false)
        {
            actionReporter -> append("Made " + selectedParking + " Available");
            it->isAvailable = true;
        }
        else
        {
            actionReporter -> append(selectedParking + " is already Available");
        }
        // message = "Made " + selectedParking + " Available";
    }
    else if (optionSelected == "Make Unavailable")
    {
        if (it->isAvailable == true)
        {
            actionReporter -> append("Made " + selectedParking + " Unavailable");
            it->isAvailable = false;
        }
        else
        {
            actionReporter -> append(selectedParking + " is already Unavailable");
        }
        // message = "Made " + selectedParking + " Available";
    }
    // if (adminSocket && adminSocket->isConnected())
    // {
    //     adminSocket -> sendMessage(message);
    // }
}

/**
 * Handles admin logging out. If confirmed, then admin application
 * will close. Otherwise, return to application.
 */
void AdminActionManager::handleLogout()
{
    QMessageBox::StandardButton response;
    response = QMessageBox::question(this, "Logout?",
        "Are you sure you want to logout?",
        QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::Yes)
    {
        close();
    }
}
