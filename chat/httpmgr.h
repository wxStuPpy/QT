#ifndef HTTPMGR_H
#define HTTPMGR_H

#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonArray>
#include <QJsonDocument>

class HttpMgr:public Singleton<HttpMgr>,public QObject
{
    Q_OBJECT
public:
    HttpMgr();
};

#endif // HTTPMGR_H
