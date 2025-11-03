#include "video/video_window.h"
#include "ui/main_container.h"
#include <QMouseEvent>
#include <QWindow>

VideoWindow::VideoWindow(MainContainer* parent) : QWidget(nullptr, Qt::Window | Qt::FramelessWindowHint) {
    setWindowTitle(tr("Wii U Gamepad Stream"));
    setFixedSize(854, 480);

    connect(this, &VideoWindow::destroyed, parent, &MainContainer::closeVideo);
}

void VideoWindow::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        windowHandle()->startSystemMove();
    }
    QWidget::mousePressEvent(event);
}

void VideoWindow::closeEvent(QCloseEvent* event) {
    emit destroyed();
}