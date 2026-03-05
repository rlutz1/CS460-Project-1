#include "AdminUserInterface.h"

#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QWidget>

AdminUserInterface::AdminUserInterface(QWidget* parent) : QMainWindow(parent)
{
    setFixedSize(300, 75);
    setWindowTitle("Admin Login");
    QWidget* centralWidget = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(centralWidget);
    loginSuccessful = false;

    // Username section for login
    QVBoxLayout* user = new QVBoxLayout;
    QLabel *userLabel = new QLabel("Username");
    userLabel -> setGeometry(20, 20, 80, 20);
    usernameEdit = new QLineEdit;
    usernameEdit -> setGeometry(110, 20, 160, 20);
    user -> addWidget(userLabel);
    user -> addWidget(usernameEdit);

    // Password section for login
    QVBoxLayout* password = new QVBoxLayout;
    QLabel *passwordLabel = new QLabel("Password");
    passwordLabel -> setGeometry(20, 60, 80, 20);
    passwordEdit = new QLineEdit;
    passwordEdit -> setGeometry(110, 60, 160, 20);
    passwordEdit -> setEchoMode(QLineEdit::Password);
    password->addWidget(passwordLabel);
    password->addWidget(passwordEdit);

    // Login confirmation with current credentials using ENTER or Login Button
    loginButton = new QPushButton("Login");
    connect(passwordEdit, &QLineEdit::returnPressed, this, &AdminUserInterface::handleLogin);
    connect(loginButton, &QPushButton::clicked, this, &AdminUserInterface::handleLogin);

    // Organize Layouts
    layout->addLayout(user);
    layout->addLayout(password);
    layout->addWidget(loginButton);
    setCentralWidget(centralWidget);
}

/**
 * Handles inputs from entry boxes and checks if credentials inputted
 * match system's known authorized credentials. Close login screen and
 * continue to application if successful. Otherwise, return to login
 * screen.
 */
void AdminUserInterface::handleLogin()
{
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (username == correctUsername && password == correctPassword)
    {
        QMessageBox::information(this, "Login", "Login Successful");
        loginSuccessful = true;
        usernameEdit->clear();
        passwordEdit->clear();
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Login Failed");
        passwordEdit->clear();
        passwordEdit->setFocus();
    }
}