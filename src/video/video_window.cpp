#include "video/video_window.h"
#include <QVBoxLayout>
#include <QWindow>
#include <QPixmap>
#include <Qt>
#include <QThread>
#include <QLabel>
#include <QImage>
#include <QMouseEvent>
#include <QCloseEvent>
#include "ui/main_container.h"
#include "video/video_worker.h"

VideoWindow::VideoWindow(MainContainer* parent) : QWidget(nullptr, Qt::Window | Qt::FramelessWindowHint) {
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(tr("Wii U Gamepad Stream"));
    setFixedSize(854, 480);

    label = new QLabel(tr("No video source available"));
    label->resize(854, 480);

    QVBoxLayout* layout = new QVBoxLayout;
    setLayout(layout);
    layout->addWidget(label, 0, Qt::AlignCenter);

    connect(this, &VideoWindow::closed, parent, &MainContainer::closeState);

    thread = new QThread(this);
    videoWorker = new VideoWorker;
    videoWorker->moveToThread(thread);
    connect(videoWorker, &VideoWorker::frame, this, &VideoWindow::updateFrame);
    connect(this, &VideoWindow::closed, videoWorker, &VideoWorker::endProcess);
    thread->start();
}

VideoWindow::~VideoWindow() {
    thread->quit();
    thread->wait();
    delete videoWorker;
    qDebug() << "deleted thread";
}

void VideoWindow::updateFrame(const QImage& frame) {
    label->setPixmap(QPixmap::fromImage(frame));
}

void VideoWindow::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        QWindow* window = windowHandle();
        window->startSystemMove();
    }
    QWidget::mousePressEvent(event);
}

void VideoWindow::closeEvent(QCloseEvent* event) {
    emit closed();
    QWidget::closeEvent(event);
}