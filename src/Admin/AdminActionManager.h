#ifndef CS460_PROJECT_1_ADMINACTIONMANAGER_H
#define CS460_PROJECT_1_ADMINACTIONMANAGER_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>

class AdminActionManager : public QWidget{
    Q_OBJECT

public:
    explicit AdminActionManager(QWidget *parent = 0);
    QString optionSelected() {return options->currentText();};

private slots:
    void handleAvailability(bool, QString);
    void handleLogout();

private:
    QComboBox *options;
    QComboBox *parking;
    QPushButton *confirmButton;
    QPushButton *logoutButton;
};


#endif //CS460_PROJECT_1_ADMINACTIONMANAGER_H