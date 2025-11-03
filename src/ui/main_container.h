#pragma once
#include <QWidget>
#include <QPushButton>

class MainContainer : public QWidget {
    Q_OBJECT
public:
    MainContainer();
private slots:
    void launchVideo();
private:
    QString launchText;
    QString closeText;
    QPushButton* button;
    bool videoActive;
};