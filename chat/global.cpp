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

std::vector<QString>  strs = { "hello world !",
							 "nice to meet u",
							 "New year,new life",
							"You have to love yourself",
							"My love is written in the wind ever since the whole world is you" };
std::vector<QString> heads = {
	":/res/head_1.jpg",
	":/res/head_2.jpg",
	":/res/head_3.jpg",
	":/res/head_4.jpg",
	":/res/head_5.jpg"
};
std::vector<QString> names = {
	"llfc",
	"zack",
	"golang",
	"cpp",
	"java",
	"nodejs",
	"python",
	"rust"
};