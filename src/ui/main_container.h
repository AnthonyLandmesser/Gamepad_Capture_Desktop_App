#pragma once
#include <QWidget>
#include <QPushButton>
#include "video/video_window.h"

class MainContainer : public QWidget {
    Q_OBJECT
public:
    MainContainer();
    void launchVideo();
    VideoWindow* video;
    bool videoActive;
public slots:
    void closeVideo();
    void changeVideoState();
private:
    QString launchText;
    QString closeText;
    QPushButton* button;
};