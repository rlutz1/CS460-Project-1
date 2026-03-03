#include "PMS/Definitions"

#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>


// driver for admin app, something strange
int run_admin(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget mainWindow;
    QComboBox *options = new QComboBox();
    options -> addItem("Make Unavailable");
    options -> addItem("Make Available");
    QString optionSelected = options->currentText();
    // QComboBox *parking = new QComboBox();
    // for (const std::string& spot : spotIds)
    // {
    //     parking->addItem(spot.uniqueId, QVariant::fromValue(spot));
    // }
    QPushButton confirmButton("confirm");
    QHBoxLayout confirmLayout;
    confirmLayout.addWidget(options);
    // confirmLayout.addWidget(parking);
    confirmLayout.addWidget(&confirmButton);
    mainWindow.setLayout(&confirmLayout);
    mainWindow.show();
    return QApplication::exec();
}
