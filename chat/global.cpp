#include "global.h"

std::function<void(QWidget*)>rePolish = [](QWidget* w) {
	w->style()->unpolish(w);
	w->style()->polish(w);
	};

std::function<QString(QString)>xorString = [](QString str) {
	QString res = str;
	int len = str.length();
	len = len % 255;
	for (int i = 0; i < str.length(); ++i) {
		res[i] = QChar(static_cast<uchar>(str[i].unicode()) ^ static_cast<uchar>(len));
	}
	return res;
	};

QString gateURLPrefix = "";