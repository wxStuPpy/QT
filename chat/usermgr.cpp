#include "usermgr.h"

UserMgr::~UserMgr()
{
}

void UserMgr::setName(QString name)
{
	_name = name;
}

void UserMgr::setUid(int uid)
{
	_uid = uid;
}

void UserMgr::setToken(QString token)
{
	_token = token;
}

int UserMgr::getUid()
{
	return _uid;
}

QString UserMgr::getName()
{
	return _name;
}

UserMgr::UserMgr()
{
}

std::vector<std::shared_ptr<ApplyInfo> > UserMgr::getApplyList()
{
	return _apply_list;
}