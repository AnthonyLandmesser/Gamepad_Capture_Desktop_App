#include "video/video_worker.h"
#include <QImage>

VideoWorker::VideoWorker() {
    isRunning = true;
}

void VideoWorker::endProcess() {
    isRunning = false;
}

// emit frame(image);