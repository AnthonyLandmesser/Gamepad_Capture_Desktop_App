#pragma once
#include <QWidget>

class VideoWindow : public QWidget {
public:
    VideoWindow(QWidget* parent);
private:
    void mousePressEvent(QMouseEvent *event) override;
};