#pragma once

#include"singleton.h"
#include <QObject>
#include <memory>

class UserMgr :public QObject, public Singleton<UserMgr>,
	public std::enable_shared_from_this<UserMgr>
{
	Q_OBJECT
public:
	friend class Singleton<UserMgr>;
	~UserMgr();
	void setName(QString name);
	void setUid(int uid);
	void setToken(QString token);
private:
	UserMgr();
	QString _name;
	QString _token;
	int _uid;
};