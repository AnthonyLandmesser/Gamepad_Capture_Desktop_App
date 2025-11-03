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

void MainContainer::launchVideo() {
    videoActive = true;
    video = new VideoWindow(this);
    video->show();
    button->setText(closeText);
}

void MainContainer::closeVideo() {
    videoActive = false;
    button->setText(launchText);
}

void MainContainer::changeVideoState() {
    if (videoActive) {
        video->close();
        closeVideo();
    }
    else {
        launchVideo();
    }
}