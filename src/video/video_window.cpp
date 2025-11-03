#include "video/video_window.h"
#include <QMouseEvent>
#include <QWindow>

VideoWindow::VideoWindow(QWidget* parent) : QWidget(parent, (Qt::Window | Qt::FramelessWindowHint) & ~Qt::WindowStaysOnTopHint) {
    setWindowTitle(tr("Wii U Gamepad Stream"));
    setFixedSize(854, 480);
}

void VideoWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        windowHandle()->startSystemMove();
    }
}