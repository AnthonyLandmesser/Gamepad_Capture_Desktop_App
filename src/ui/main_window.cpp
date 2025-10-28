#include "ui/main_window.h"
#include "ui/main_container.h"

MainWindow::MainWindow() {
    setCentralWidget(new MainContainer());
    setWindowTitle(tr("Wii U Gamepad Monitor"));
    resize(1000, 1000);
}