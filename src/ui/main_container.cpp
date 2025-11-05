#include "ui/main_container.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "video/video_window.h"

MainContainer::MainContainer() {
    launchText = tr("Launch Gamepad Stream");
    closeText = tr("Close Gamepad Stream");
    isVideoActive = false;

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
    isVideoActive = true;
    button->setText(closeText);
}

void MainContainer::closeState() {
    isVideoActive = false;
    button->setText(launchText);
}

void MainContainer::changeVideoState() {
    if (isVideoActive) {
        video->close();
    }
    else {
        video = new VideoWindow(this);
        video->show();
        launchState();
    }
}