#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setOrganizationName("CoreOfDevelop");
    QApplication::setApplicationName("DataBaseStore");

    MainWindow w;
    w.show();
    return a.exec();
}
