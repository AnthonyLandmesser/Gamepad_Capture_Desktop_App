#pragma once
#include <QWidget>

class QLabel;
class QThread;
class Qimage;
class QMouseEvent;
class QCloseEvent;
class MainContainer;
class VideoWorker;

class VideoWindow : public QWidget {
    Q_OBJECT
public:
    VideoWindow(MainContainer* parent);
    ~VideoWindow();
    MainContainer* parent;
    VideoWorker* videoWorker;
    public slots:
        void updateFrame(const QImage& frame);
    signals:
        void closed();
private:
    QLabel* label;
    QThread* thread;
    void mousePressEvent(QMouseEvent* event) override;
    void closeEvent(QCloseEvent* event) override;
};