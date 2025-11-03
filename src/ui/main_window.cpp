#include "ui/main_window.h"

MainWindow::MainWindow() {
    container = new MainContainer;
    setCentralWidget(container);
    setWindowTitle(tr("Wii U Gamepad Monitor"));
    resize(1000, 1000);
}

void MainWindow::closeEvent(QCloseEvent* event) {
    if (container->videoActive) {
        container->changeVideoState();
    }
    QMainWindow::closeEvent(event);
}