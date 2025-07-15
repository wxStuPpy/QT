#ifndef GLOBAL_H
#define GLOBAL_H

#include <QWidget>
#include <functional>
#include <QStyle>
#include <QRegularExpression>
#include <memory>
#include <iostream>
#include <mutex>
#include <QByteArray>
#include <QNetworkReply>
#include <QJsonObject>
#include <QDir>
#include <QSettings>

/**
 * @brief rePolish 刷新qss
 */
extern std::function<void(QWidget*)>rePolish;

extern std::function<QString(QString)>xorString;

enum ReqID {
	ID_GET_VERIFY_CODE = 1001,//获取验证码
	ID_REG_USER = 1002,//注册用户
};

enum Modules {
	REGISTERMOD = 0,
};

enum ErrorCodes {
	SUCCESS = 0,
	ERR_JSON = 1,//json解析失败
	ERR_NETWORK = 2,//网络错误
};

extern QString gateURLPrefix;

#endif // GLOBAL_H
