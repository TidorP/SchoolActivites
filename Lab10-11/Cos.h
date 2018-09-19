#pragma once
#include <vector>
#include "Observer.h"
#include <QtWidgets>
#include "Service.h"
#include "Current.h"
#include "List_view.h"
#include <QListView>
class Cos:public QObject,public Observable
{
	Q_OBJECT
private:
	MyListModel * model;
	QListView* list = new QListView;
	Current & cu;
	//std::vector<Observer*>& obs;
	QWidget * main = new QWidget;
	QFormLayout* mainLayout = new QFormLayout;
	QListWidget* lista = new QListWidget;
	
	QPushButton* buttonClear = new QPushButton("Clear Cos");
	QPushButton* buttonPopulate = new QPushButton("Populate Cos");
	
	QLabel* pop = new QLabel("Cu cat sa populam?");
	QLineEdit* Epop = new QLineEdit;

public:
	Cos(Current& cu, std::vector<Observer*>& obs,MyListModel* model);
	//void notify();
	private slots:
	void clearCos();
	void populateCos();
	//void update();

};

