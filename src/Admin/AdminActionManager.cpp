#include "AdminActionManager.h"

#include <QWidget>
#include <QProcess>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>

AdminActionManager::AdminActionManager(QWidget* parent) : QMainWindow(parent)
{
    setWindowTitle("Main Page");
    setFixedSize(600, 200);
    QWidget* mainWindow = new QWidget();
    QHBoxLayout* confirmLayout = new QHBoxLayout(mainWindow);
    options = new QComboBox();
    options -> addItem("Make Unavailable");
    options -> addItem("Make Available");
    parking = new QComboBox();
    parking -> addItem("ID001");
    parking -> addItem("ID002");
    parking -> addItem("ID003");

    confirmButton = new QPushButton("Confirm");
    connect(confirmButton, &QPushButton::clicked, this, &AdminActionManager::handleAvailability);
    logoutButton = new QPushButton("Logout");
    connect(logoutButton, &QPushButton::clicked, this, &AdminActionManager::handleLogout);

    confirmLayout -> addWidget(options);
    confirmLayout -> addWidget(parking);
    confirmLayout -> addWidget(confirmButton);
    confirmLayout -> addWidget(logoutButton);
    setCentralWidget(mainWindow);
}

void AdminActionManager::handleAvailability()
{
}

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
