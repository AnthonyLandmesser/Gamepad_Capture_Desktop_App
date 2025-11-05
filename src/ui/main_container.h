#pragma once
#include <QWidget>
#include <QString>

class QPushButton;
class VideoWindow;

class MainContainer : public QWidget {
    Q_OBJECT
public:
    MainContainer();
    VideoWindow* video;
    bool isVideoActive;
public slots:
    void launchState();
    void closeState();
    void changeVideoState();
private:
    QString launchText;
    QString closeText;
    QPushButton* button;
};