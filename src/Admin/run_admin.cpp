#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>

#include "AdminUserInterface.h"
#include "AdminActionManager.h"


// driver for admin app, something strange
int run_admin(int argc, char *argv[]) {
    QApplication a(argc, argv);

    AdminUserInterface userInterface;
    userInterface.show();

    a.exec();

    if (!userInterface.isLoginSuccessful())
    {
        return 0;
    }

    AdminActionManager mainPage;
    mainPage.show();

    return a.exec();
}
