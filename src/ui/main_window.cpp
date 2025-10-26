#include "ui/main_window.h"
// #include main_container.h
#include <QLabel>

MainWindow::MainWindow() {
    // setCentralWidget(new MainContainer());
    setCentralWidget(new QLabel("Hello World"));
    setWindowTitle(tr("Wii U Gamepad Monitor"));
    resize(1000, 1000);
}

// MainWindow::~MainWindow() = default;