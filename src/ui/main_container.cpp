#include "ui/main_container.h"
#include <QVBoxLayout>

MainContainer::MainContainer() {
    launchText = tr("Launch Gamepad Stream");
    closeText = tr("Close Gamepad Stream");
    videoActive = false;

    button = new QPushButton(launchText);
    QFont buttonFont = button->font();
    buttonFont.setPointSize(buttonFont.pointSize()*4);
    button->setFont(buttonFont);

    connect(button, &QPushButton::clicked, this, &MainContainer::launchVideo);
    
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout(layout);
    layout->addWidget(button, 0, Qt::AlignCenter);
}

void MainContainer::launchVideo() {
    if (videoActive) {
        button->setText(launchText);
    }
    else {
        button->setText(closeText);
    }
    videoActive = !videoActive;
}