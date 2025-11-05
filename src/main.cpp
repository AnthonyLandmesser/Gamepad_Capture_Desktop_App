#include <QApplication>
#include <QDebug>
#include "ui/main_window.h"

int main(int argc, char *argv[]) {
    #ifdef QT_DEBUG
        qDebug() << "Debug build";
    #endif

    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}