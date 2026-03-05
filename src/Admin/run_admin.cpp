#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QMessageBox>

#include "AdminUserInterface.h"
#include "AdminActionManager.h"
#include "AdminSocket.h"


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

    AdminSocket* adminSocket = new AdminSocket();
    QString serverHost = "127.0.0.1";
    quint16 serverPort = 12345;
    if (!adminSocket->connectToServer(serverHost, serverPort))
    {
        QMessageBox::warning(nullptr, "Connection Failed", "Could not connect to Server");
        delete adminSocket;
        return 0;
    }

    // Run admin application login
    AdminActionManager mainPage;
    mainPage.show();
    int result = a.exec();

    // Cleanup
    adminSocket->disconnect();
    delete adminSocket;

    return result;
}
