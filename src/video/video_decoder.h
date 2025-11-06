#include <QObject>
#include <QByteArray>

class QImage;

class VideoDecoder : public QObject {
    Q_OBJECT
public:
    VideoDecoder(QObject* parent);
    void addPacket(const QByteArray& packet);
    signals:
        void readyFrame(const QImage& image);
private:
};