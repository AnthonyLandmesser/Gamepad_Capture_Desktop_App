#include "ui/main_window.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    #ifdef QT_DEBUG
        qDebug() << "Debug build";
    #endif

    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}