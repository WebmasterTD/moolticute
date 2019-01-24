#ifndef MPDEVICEBLEIMPL_H
#define MPDEVICEBLEIMPL_H

#include "MessageProtocol/MessageProtocolBLE.h"
#include "MPDevice.h"

class MPDeviceBleImpl: public QObject
{
    Q_OBJECT
public:
    MPDeviceBleImpl(MessageProtocolBLE *mesProt, MPDevice *dev);
    void getPlatInfo(const MessageHandlerCb &cb);
    QVector<int> calcPlatInfo();

    void flashMCU(QString type, const MessageHandlerCb &cb);
    void uploadBundle(QString filePath, const MessageHandlerCb &cb);

private:
    void checkDataFlash(const QByteArray &data, QElapsedTimer *timer, AsyncJobs *jobs, QString filePath);
    void sendBundleToDevice(QString filePath, AsyncJobs *jobs);

    void dequeueAndRun(AsyncJobs *job);


    MessageProtocolBLE *bleProt;
    MPDevice *mpDev;

    QByteArray platInfo;
};

#endif // MPDEVICEBLEIMPL_H
