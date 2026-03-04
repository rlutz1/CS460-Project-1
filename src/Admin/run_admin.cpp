#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>

#include "AdminUserInterface.h"
#include "AdminActionManager.h"


// driver for admin app
int run_admin(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Run admin application login
    AdminUserInterface userInterface;
    userInterface.show();
    a.exec();

    // Only continue to admin application if login succesfully
    if (!userInterface.isLoginSuccessful())
    {
        return 0;
    }

    // Run admin application login
    AdminActionManager mainPage;
    mainPage.show();
    return a.exec();
}
