#include "ui/main_container.h"
#include <QPushButton>

MainContainer::MainContainer() {
    QPushButton button = new QPushButton(tr("Launch Gamepad Stream"));
    setLayout(new QVBoxLayout());
    layout()->addWidget(button);
}