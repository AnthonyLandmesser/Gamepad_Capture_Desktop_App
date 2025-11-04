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

    connect(button, &QPushButton::clicked, this, &MainContainer::changeVideoState);
    
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout(layout);
    layout->addWidget(button, 0, Qt::AlignCenter);
}

void MainContainer::launchState() {
    videoActive = true;
    button->setText(closeText);
}

void MainContainer::closeState() {
    videoActive = false;
    button->setText(launchText);
}

void MainContainer::changeVideoState() {
    if (videoActive) {
        video->close();
        // closeState();
    }
    else {
        video = new VideoWindow(this);
        video->show();
        launchState();
    }
}