#include <QObject>

class QImage;

class VideoWorker : public QObject {
    Q_OBJECT
public:
    VideoWorker();
    public slots:
        void endProcess();
    signals:
        void frame(const QImage& image);
private:
    bool isRunning;
};