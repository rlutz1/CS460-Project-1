#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

#include <QComboBox>
#include <QDebug>


// driver for admin app, something strange
int run_admin(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget mainWindow;
    QVBoxLayout layout(&mainWindow);
    mainWindow.setLayout(&layout);
    QPushButton button("admin app!", &mainWindow);
    layout.addWidget(&button);
    mainWindow.show();

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

    return QApplication::exec();
}
