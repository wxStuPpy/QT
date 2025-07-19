#include "httpmgr.h"

void HttpMgr::httpFinishSlot(ReqID id, QString res, ErrorCodes ec, Modules mod)
{
	if (mod == Modules::REGISTERMOD)
	{
		//发送信号通知指定模块http的响应结束了
		emit sigRegModFinish(id, res, ec);
	}

	if (mod == Modules::RESETMOD)
	{
		//发送信号通知指定模块http的响应结束了
		emit sigResetModFinish(id, res, ec);
	}

	if (mod == Modules::LOGINMOD) {
		//发送信号通知指定模块http的响应结束了
		emit sigLoginModFinish(id, res, ec);
	}
}

HttpMgr::~HttpMgr()
{
}

HttpMgr::HttpMgr()
{
	//如果发送的信号是注册模块的响应结束
	connect(this, &HttpMgr::sigHttpFinish, this, &HttpMgr::httpFinishSlot);
}

/*
*@brief 发送HTTP POST请求
* @param url 请求的目标URL
* @param json 请求携带的JSON数据
* @param reqID 请求ID，用于标识不同类型的请求
* @param mod 请求所属的模块，用于分类管理
* @details 异步发送HTTP POST请求，请求结果通过httpFinishSig信号返回
* @note 请求超时时间默认为30秒
* @see httpFinishSig
*/
void HttpMgr::postHttpReq(QUrl url, QJsonObject json, ReqID reqID, Modules mod)
{
	// 将JSON对象转换为UTF-8格式的JSON字节流
	QByteArray data = QJsonDocument(json).toJson();
	// 创建网络请求并设置目标URL
	QNetworkRequest request(url);
	// 设置请求头，指定内容类型为JSON
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	// 设置请求体长度（可选，Qt会自动处理）
	request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));
	// 获取当前对象的shared_ptr，确保在lambda执行期间对象不会被销毁
	// 注意：调用此函数前必须确保对象已由shared_ptr管理
	auto self = shared_from_this();
	// 发送POST请求并获取响应对象
	QNetworkReply* reply = _manager.post(request, data);
	// 连接响应完成信号到lambda回调
	QObject::connect(reply, &QNetworkReply::finished, [self, reply, reqID, mod]() {
		// 检查请求是否有错误
		if (reply->error() != QNetworkReply::NoError) {
			// 打印错误信息（可替换为日志记录）
			qDebug() << "Network error:" << reply->errorString();
			qDebug() << " Error code:" << reply->error();                             // 枚举值
			qDebug() << " Error string:" << reply->errorString();                    // 可读描述
			qDebug() << " HTTP status code:"
				<< reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();  // HTTP 状态码
			// 发送错误信号（错误码为网络错误）
			emit self->sigHttpFinish(reqID, "", ErrorCodes::ERR_NETWORK, mod);
			// 释放响应对象（异步）
			reply->deleteLater();
			return;
		}
		// 请求成功，读取响应数据
		QString res = reply->readAll();
		// 发送成功信号（错误码为SUCCESS）
		emit self->sigHttpFinish(reqID, res, ErrorCodes::SUCCESS, mod);
		// 释放响应对象（异步）
		reply->deleteLater();
		return;
		});
}