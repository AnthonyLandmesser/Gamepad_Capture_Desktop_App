#include "video/video_decoder.h"
#include <QImage>
#include "wels/codec_api.h"
#include <QDebug>
// #include "video/nal_unit.h"
// #include "video/video_packet.h"

VideoDecoder::VideoDecoder(QObject* parent) : QObject(parent) {
    ISVCDecoder* decoder;
    WelsCreateDecoder(&decoder);
    SDecodingParam param = {0};
    param.sVideoProperty.eVideoBsType = VIDEO_BITSTREAM_AVC;
    param.bParseOnly = true;
    decoder->Initialize(&param);


}

void addPacket(const QByteArray& packet) {
    if (packet.size() > 0) {
        qDebug() << "addPacket";
    }
}