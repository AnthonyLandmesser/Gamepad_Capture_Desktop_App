#pragma once
#include <QWidget>
#include <QPushButton>
#include "video/video_window.h"

class MainContainer : public QWidget {
    Q_OBJECT
public:
    MainContainer();
    void launchState();
    VideoWindow* video;
    bool videoActive;
public slots:
    void closeState();
    void changeVideoState();
private:
    QString launchText;
    QString closeText;
    QPushButton* button;
};