#include <QObject>

class QUdpSocket;
class VideoDecoder;

class VideoWorker : public QObject {
    Q_OBJECT
public:
    VideoWorker();
    VideoDecoder* videoDecoder;
    public slots:
        void endProcess();
        void processPacket();
private:
    bool isRunning;
    QUdpSocket* socket;
};