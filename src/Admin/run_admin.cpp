#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>


// driver for admin app, something strange
int run_admin(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget mainWindow;
    QVBoxLayout layout(&mainWindow);
    mainWindow.setLayout(&layout);
    QPushButton button("admin app!", &mainWindow);
    layout.addWidget(&button);
    mainWindow.show();
    return QApplication::exec();
}
