#include "List_view.h"

MyListModel::MyListModel(QObject* parent) :QAbstractListModel{ parent } {}

int MyListModel::rowCount(const QModelIndex & /* parent */ ) const
{
	return Lista.count();
}

QVariant MyListModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();
	if (index.row() >= Lista.size())
		return QVariant();
	if (role == Qt::DisplayRole) {
		return Lista.at(index.row());
	}
	return QVariant();
}

void MyListModel::addData(QString data)
{
	Lista << data;

	QModelIndex model = index(0);
	QModelIndex model2 = index(this->rowCount());
	emit(dataChanged(model, model2));
}

void MyListModel::empty()
{
	Lista = QStringList();

	QModelIndex model = index(0);
	QModelIndex model2 = index(this->rowCount());
	emit(dataChanged(model, model2));
}