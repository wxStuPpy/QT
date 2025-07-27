#pragma once

#include <QListWidget>
#include <QWheelEvent>
#include <QEvent>
#include <QScrollBar>
#include <QDebug>
#include <QDialog>
#include <memory>
#include "userdata.h"
#include "loadingdialog.h"

class SearchList : public QListWidget
{
	Q_OBJECT
public:
	SearchList(QWidget* parent = nullptr);
	void closeFindDlg();
	void setSearchEdit(QWidget* edit);
protected:
	bool eventFilter(QObject* watched, QEvent* event) override;
private:
	void waitPending(bool pending = true);
	bool _send_pending;
	void addTipItem();
	std::shared_ptr<QDialog> _find_dlg;
	QWidget* _search_edit;
	LoadingDialog* _loadingDialog;
private slots:
	void slotItemClicked(QListWidgetItem* item);
	void slotUserSearch(std::shared_ptr<SearchInfo> si);
signals:
};
