#include "video/video_window.h"
#include "ui/main_container.h"
#include <QMouseEvent>
#include <QWindow>
#include <QVBoxLayout>
#include <QLabel>

VideoWindow::VideoWindow(MainContainer* parent) : QWidget(nullptr, Qt::Window | Qt::FramelessWindowHint) {
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(tr("Wii U Gamepad Stream"));
    setFixedSize(854, 480);

    QLabel* label = new QLabel(tr("No video source available"));
    label->resize(854, 480);

    QVBoxLayout* layout = new QVBoxLayout;
    setLayout(layout);
    layout->addWidget(label, 0, Qt::AlignCenter);

    connect(this, &VideoWindow::closed, parent, &MainContainer::closeState);
}

void VideoWindow::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        windowHandle()->startSystemMove();
    }
    QWidget::mousePressEvent(event);
}

void VideoWindow::closeEvent(QCloseEvent* event) {
    emit closed();
}