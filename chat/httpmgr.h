#ifndef HTTPMGR_H
#define HTTPMGR_H

#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class HttpMgr :public QObject, public Singleton<HttpMgr>,
	public std::enable_shared_from_this<HttpMgr>
{
	Q_OBJECT
		//基类中的getInstance可以调用子类的构造函数
		friend class Singleton<HttpMgr>;
private slots:
	void  httpFinishSlot(ReqID id, QString res, ErrorCodes ec, Modules mod);
public:
	//智能指针释放时 要调用析构 必须设置为公有
	~HttpMgr();
	/**
	 * @brief 发送HTTP POST请求
	 * @param url 请求的目标URL
	 * @param json 请求携带的JSON数据
	 * @param reqID 请求ID，用于标识不同类型的请求
	 * @param mod 请求所属的模块，用于分类管理
	 * @details 异步发送HTTP POST请求，请求结果通过httpFinishSig信号返回
	 * @note 请求超时时间默认为30秒
	 * @see httpFinishSig
	 */
	void postHttpReq(QUrl url, QJsonObject json, ReqID reqID, Modules mod);
private:
	HttpMgr();
	QNetworkAccessManager _manager;

signals:
	/**
	 * @brief HTTP请求完成的信号
	 * @param reqID 对应的请求ID
	 * @param res 服务器返回的响应数据（JSON格式字符串）
	 * @param ec 请求结果的错误码
	 * @param mod 对应的请求模块
	 * @details 当HTTP请求完成（成功或失败）时发出此信号
	 * @note 无论请求成功或失败，此信号都会发出
	 * @see postHttpReq
	 */
	void httpFinishSig(ReqID reqID, QString res, ErrorCodes ec, Modules mod);
	void regModFinishSig(ReqID id, QString res, ErrorCodes ec);
	void resetModFinishSig(ReqID id, QString res, ErrorCodes ec);
};

#endif // HTTPMGR_H
