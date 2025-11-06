#include "video/video_worker.h"
#include <QByteArray>
#include <QImage>
#include <QNetworkDatagram>
#include <QUdpSocket>
#include "video/video_decoder.h"

VideoWorker::VideoWorker() {
    isRunning = true;

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress("10.8.0.1"), 50120);
    connect(socket, &QUdpSocket::readyRead, this, &VideoWorker::processPacket);

    videoDecoder = new VideoDecoder(this);
}

void VideoWorker::endProcess() {
    isRunning = false;
}

void VideoWorker::processPacket() {
    while (isRunning && socket->hasPendingDatagrams()) {
        const QByteArray& videoPacket = socket->receiveDatagram().data();
        // videoDecoder->addPacket(videoPacket);
    }
}