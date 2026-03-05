#ifndef CS460_PROJECT_1_ADMINUSERINTERFACE_H
#define CS460_PROJECT_1_ADMINUSERINTERFACE_H

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>

class AdminUserInterface : public QMainWindow{
    Q_OBJECT

public:
    explicit AdminUserInterface(QWidget *parent = 0);
    bool isLoginSuccessful() const {return loginSuccessful;};

private slots:
    void handleLogin();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;

    const QString correctUsername = "admin";
    const QString correctPassword = "password";

    bool loginSuccessful = false;
};


#endif //CS460_PROJECT_1_ADMINUSERINTERFACE_H