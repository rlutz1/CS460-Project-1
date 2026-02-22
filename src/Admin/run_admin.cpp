#include <QApplication>
#include <QPushButton>
#include "../run_demo.h"

int run_admin(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("I am the admin application driver.", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}