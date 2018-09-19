#include "Cos.h"



Cos::Cos(Current &cu, std::vector<Observer*>& obs, MyListModel* model) : cu{ cu }, Observable{ obs }, model{ model }
{
	main->setLayout(mainLayout);
	
	list->setModel(model);
	mainLayout->addWidget(list);
	mainLayout->addWidget(buttonClear);
	mainLayout->addRow(pop,Epop);
	mainLayout->addWidget(buttonPopulate);
	
	connect(buttonClear,&QPushButton::clicked,this,&Cos::clearCos);
	connect(buttonPopulate, &QPushButton::clicked, this, &Cos::populateCos);

	//for (auto i : cu.getMem())
	//{
	//	QString str = QString::fromStdString(i.getTitlu() + " " + i.getDescriere() + " " + i.getTip() + " " + std::to_string(i.getDurata()));
	//	model->addData(str);
	//	//QListWidgetItem* lis = new QListWidgetItem(str, lista);
	//	//lis;
	//}
	main->show();
	

}
void Cos::clearCos()
{
	model->empty();
	cu.deleteAll();
	//for (auto i : cu.getMem())
	//{
	//		QString str = QString::fromStdString(i.getTitlu() + " " + i.getDescriere() + " "+i.getTip() +" "+ std::to_string(i.getDurata()));
	//	QListWidgetItem* lis = new QListWidgetItem(str, lista);
	//	lis;
	//}
	notify();
	//main->show();
}
void Cos::populateCos()
{
	//lista->clear();
	cu.populeaza(Epop->text().toInt());
	for (auto i : cu.getMem())
	{
		QString str = QString::fromStdString(i.getTitlu() + " " + i.getDescriere() +" "+ i.getTip() +" "+ std::to_string(i.getDurata()));
		model->addData(str);
	}
	notify();
	//main->show();
}
//void Cos::update()
//{
//	lista->clear();
//	for (auto i : cu.getMem())
//	{
//		QString str = QString::fromStdString(i.getTitlu() + " " + i.getDescriere() + " " + i.getTip() + " " + std::to_string(i.getDurata()));
//		QListWidgetItem* lis = new QListWidgetItem(str, lista);
//		lis;
//	}
//}
//void Cos::notify()
//{
//	for (auto i : obs)
//	{
//		i->update();
//	}
//}
