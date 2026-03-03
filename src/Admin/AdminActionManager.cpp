#include "AdminActionManager.h"

#include <QWidget>
#include <QProcess>
#include <QHBoxLayout>
#include <QPushButton>

AdminActionManager::AdminActionManager(QWidget* parent)
{
    QWidget mainWindow;
    mainWindow.setWindowTitle("Main Page");
    mainWindow.setFixedSize(600, 200);
    options -> addItem("Make Unavailable");
    options -> addItem("Make Available");

    parking -> addItem("ID001");
    parking -> addItem("ID002");
    parking -> addItem("ID003");

    confirmButton = new QPushButton("Confirm");
    // connect(confirmButton, &QPushButton::clicked, this, &AdminActionManager::handleAvailability);
    logoutButton = new QPushButton("Logout");
    // connect(logoutButton, &QPushButton::clicked, this, &AdminActionManager::handleLogout);

    QHBoxLayout confirmLayout;
    confirmLayout.addWidget(options);
    confirmLayout.addWidget(parking);
    confirmLayout.addWidget(&confirmButton);
    confirmLayout.addWidget(&logoutButton);
    mainWindow.setLayout(&confirmLayout);
    mainWindow.show();
}

void handleAvailability(QString freeNotFree, QString spotId)
{
    if (freeNotFree == "Make Available")
    {
        // Call PMC to make spot available
    }
    else if (freeNotFree == "Make Unavailable")
    {
        // Call PMC to make spot unavailable
    }
}

void handleLogout()
{
    // Creates warning window to log out. If yes, then return to log-in screen
    // Else, return to the action manager
}
