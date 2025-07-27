#pragma once
#include "singleton.h"
#include <QTcpSocket>
#include "global.h"
#include "userdata.h"

class TcpMgr :public QObject, public Singleton<TcpMgr>
{
	Q_OBJECT
		friend class Singleton<TcpMgr>;
public:
	~TcpMgr();
private:
	TcpMgr();
	QTcpSocket _socket;
	QString _host;
	uint16_t _port;
	QByteArray _buffer;
	bool _b_recv_pending;
	quint16 _messageID;
	quint16 _messageLen;
	QMap<ReqID, std::function<void(ReqID id, int len, QByteArray data)>> _handlers;
	void initHandlers();
	void handleMsg(ReqID id, int len, QByteArray data);
public slots:
	void slotTcpConnect(ServerInfo);
	void slotSendData(ReqID ID, QString data);
signals:
	void sigConnectSuccess(bool b_success);
	void sigConnectClose();
	void sigSendData(ReqID ID, QString data);
	void sigSwitchChatDialog();
	void sigLoginFailed(int);
	void sigUserSearch(std::shared_ptr<SearchInfo> si);
};