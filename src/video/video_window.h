#pragma once
#include <QWidget>

class MainContainer;

class VideoWindow : public QWidget {
    Q_OBJECT
public:
    VideoWindow(MainContainer* parent);
    MainContainer* parent;
signals:
    void destroyed();
private:
    void mousePressEvent(QMouseEvent* event) override;
    void closeEvent(QCloseEvent* event) override;
};