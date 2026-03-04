#include "AdminActionManager.h"

#include <QWidget>
#include <QProcess>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>

AdminActionManager::AdminActionManager(QWidget* parent) : QMainWindow(parent)
{
    setWindowTitle("Main Page");
    setFixedSize(600, 300);
    QWidget* mainWindow = new QWidget();
    QVBoxLayout* confirmLayout = new QVBoxLayout(mainWindow);

    // Admin Actions for parking lot
    options = new QComboBox();
    options -> addItem("Make Unavailable");
    options -> addItem("Make Available");
    parking = new QComboBox();
    parking -> addItem("ID001");
    parking -> addItem("ID002");
    parking -> addItem("ID003");

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
    if (optionSelected == "Make Available")
    {
        actionReporter -> append("Made " + parking -> currentText() + " Available");
    }
    else if (optionSelected == "Make Unavailable")
    {
        actionReporter -> append("Made " + parking -> currentText() + " Unavailable");
    }
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
