#ifndef CS460_PROJECT_1_ADMINACTIONMANAGER_H
#define CS460_PROJECT_1_ADMINACTIONMANAGER_H

#include <QPushButton>
#include <QComboBox>
#include <QMainWindow>
#include <QTextEdit>

class AdminActionManager : public QMainWindow{
    Q_OBJECT

public:
    explicit AdminActionManager(QWidget *parent = 0);

private slots:
    void handleAvailability();
    void handleLogout();

private:
    QComboBox *options;
    QComboBox *parking;
    QPushButton *confirmButton;
    QPushButton *logoutButton;
    QTextEdit *actionReporter;

    bool logout;
};


#endif //CS460_PROJECT_1_ADMINACTIONMANAGER_H