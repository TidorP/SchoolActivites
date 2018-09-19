#pragma once

#include <QAbstractListModel>

class
	MyListModel :public QAbstractListModel
{
	Q_OBJECT

private:
	QStringList Lista;

public:
	MyListModel(QObject*parent = 0);
	int rowCount(const QModelIndex &parent = QModelIndex())const;

	QVariant data(const QModelIndex&index, int role = Qt::DisplayRole)const;
	void addData(QString data);
	void empty();
};