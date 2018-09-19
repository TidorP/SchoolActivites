#include "GUI.h"



GUI::GUI(Service& service, Current &current) :serv{ service }, cu{ current }
{
	
	box->addWidget(buttonPrint);
	box->addWidget(buttonAdd);
	box->addWidget(buttonDel);
	box->addWidget(buttonUpd);
	box->addWidget(buttonFilter);
	box->addWidget(buttonSort);
	box->addWidget(buttonAddCos);
	box->addWidget(buttonClearCos);
	box->addWidget(buttonPopulateCos);
	box->addWidget(buttonPrintCos);
	box->addWidget(buttonUndo);
	box->addWidget(buttonExport2HTML);
	box->addWidget(buttonForme);

	w->setLayout(box);
	w->setMinimumWidth(200);
	w->setMaximumWidth(200);

	e->setLayout(empty);
	e->setMinimumWidth(500);

	principal->addWidget(w);
	principal->addWidget(e);
	principal->addWidget(Add);
	//principal->addWidget(PrintCos);
	principal->addWidget(scrollArea);
	principal->addWidget(Delete);
	principal->addWidget(Update);
	principal->addWidget(Filter);
	principal->addWidget(Sort);
	principal->addWidget(AddCos);
	principal->addWidget(Populate);

	main->setLayout(principal);
	main->setMinimumWidth(700);

	add->addRow(addTitlu, EaddTitlu);
	add->addRow(addDescriere, EaddDescriere);
	add->addRow(addTip, EaddTip);
	add->addRow(addDurata, EaddDurata);
	add->addWidget(buttonExeAdd);

	del->addRow(delTitlu, DaddTitlu);
	del->addRow(delDescriere, DaddDescriere);
	del->addRow(delTip, DaddTip);
	del->addRow(delDurata, DaddDurata);
	del->addWidget(buttonExeDel);

	upd->addRow(oldTitlu, UaddTitlu);
	upd->addRow(oldDescriere, UaddDescriere);
	upd->addRow(oldTip, UaddTip);
	upd->addRow(oldDurata, UaddDurata);
	upd->addRow(newTitlu, UaddNTitlu);
	upd->addRow(newDescriere, UaddNDescriere);
	upd->addRow(newTip, UaddNTip);
	upd->addRow(newDurata, UaddNDurata);
	upd->addWidget(buttonExeUpd);

	filter->addRow(filter1,Efilter1);
	filter->addRow(filter2, Efilter2);
	filter->addWidget(buttonExeFilter);

	sort->addRow(sort1, Esort1);
	sort->addWidget(buttonExeSort);

	print->addRow(printList);
	list->addRow(printLIST);
	sortedList->addRow(printSorted);
	printCos->addRow(showCos);
	printException->addRow(exception);

	istoric->addRow(istoric_data,istoric_line);
	istoric->addWidget(button_istoric);
	istoric->addWidget(lista);

	addCos->addRow(addTitluCos, EaddTitluCos);
	addCos->addWidget(buttonExeAddCos);

	populate->addRow(populateCos, EaddPopulateCos);
	populate->addWidget(buttonExePopulateCos);

	Istoric->setLayout(istoric);
	Add->setLayout(add);
	Delete->setLayout(del);
	Update->setLayout(upd);
	Filter->setLayout(filter);
	Sort->setLayout(sort);
	Print->setLayout(print);
	LIST->setLayout(list);
	SORTEDLIST->setLayout(sortedList);
	AddCos->setLayout(addCos);
	PrintCos->setLayout(printCos);
	Populate->setLayout(populate);
	PrintException->setLayout(printException);
	
	hideALL();


	EaddDurata->setValidator(new QIntValidator(0, INT_MAX, this));

	connect(buttonAdd,&QPushButton::clicked,this,&GUI::clickAdd);
	connect(buttonDel, &QPushButton::clicked, this, &GUI::clickDel);
	connect(buttonUpd, &QPushButton::clicked, this, &GUI::clickUpd);
	connect(buttonPrint,&QPushButton::clicked, this, &GUI::clickPrint);
	connect(buttonFilter, &QPushButton::clicked, this, &GUI::clickFilter);
	connect(buttonSort, &QPushButton::clicked, this, &GUI::clickSort);
	connect(buttonAddCos, &QPushButton::clicked, this, &GUI::clickAddCos);
	connect(buttonPrintCos, &QPushButton::clicked, this, &GUI::clickPrintCos);
	connect(buttonClearCos, &QPushButton::clicked, this, &GUI::clickClearCos);
	connect(buttonPopulateCos, &QPushButton::clicked, this, &GUI::clickPopulateCos);
	connect(buttonUndo, &QPushButton::clicked, this, &GUI::clickUndo);
	connect(buttonExport2HTML, &QPushButton::clicked, this, &GUI::clickExport2HTML);

	connect(buttonExeAdd, &QPushButton::clicked, this, &GUI::clickExeAdd);
	connect(buttonExeDel, &QPushButton::clicked, this, &GUI::clickExeDel);
	connect(buttonExeUpd, &QPushButton::clicked, this, &GUI::clickExeUpd);
	connect(buttonExeUpd, &QPushButton::clicked, this, &GUI::clickShowIstoric);
	connect(buttonExeFilter, &QPushButton::clicked, this, &GUI::clickExeFilter);
	connect(buttonExeSort, &QPushButton::clicked, this, &GUI::clickExeSort);
	connect(buttonExeAddCos, &QPushButton::clicked, this, &GUI::clickExeAddCos);
	connect(buttonExePopulateCos, &QPushButton::clicked, this, &GUI::clickExePopulateCos);
	connect(buttonForme, &QPushButton::clicked, this, &GUI::clickForme);
	connect(button_istoric, &QPushButton::clicked, this, &GUI::clickExeIstoric);

	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scrollArea->setWidget(Print);
	//scrollArea->setWidget(PrintCos);
	scrollArea->setWidgetResizable(true);

	on_button();
	printList->setStyleSheet("QLabel { background-color : red; color : blue; }");
	w->setStyleSheet("background-color:rgb(176,224,230)");
	main->setStyleSheet("background-color:rgb(95,158,160)");
}
void GUI::hideALL()
{
	//PrintCos->hide();
	Istoric->hide();
	scrollArea->hide();
	e->hide();
	Add->hide();
	AddCos->hide();
	Delete->hide();
	Update->hide();
	Filter->hide();
	Sort->hide();
	Populate->hide();
}
void GUI::showMenu()
{
	main->show();
}
void GUI::clickAdd()
{
	hideALL();
	Add->show();
}
void GUI::clickAddCos()
{
	hideALL();
	AddCos->show();
}
void GUI::clickDel()
{
	hideALL();
	Delete->show();
}
void GUI::clickUpd()
{
	hideALL();
	Update->show();
}
void GUI::clickFilter()
{
	hideALL();
	Filter->show();
}
void GUI::clickSort()
{
	hideALL();
	Sort->show();
}
void GUI::clickUndo()
{
	try {
		serv.undo();
	}
	catch (const Exception &exc)
	{
		QString temp;
		PrintException->show();
		exception->setText(temp);
		temp.append("Exceptii: \n");
		QString exceptie = QString::fromStdString(exc.getMsg());
		temp.append(exceptie);
		exception->setText(temp);
	}
}
void GUI:: clickExport2HTML()
{
	exportToHTML("testExport.html", cu.getMem());
	QString link = "file:///C:/Users/ptido/source/repos/Lab10-11/Lab10-11/testExport.html";
	QDesktopServices::openUrl(QUrl(link));
}
void GUI::clickExeAdd()
{
	try {
		serv.Sadd(EaddTitlu->text().toStdString(), EaddDescriere->text().toStdString(), EaddTip->text().toStdString(), EaddDurata->text().toInt());
	}
	catch (const Exception &exc)
	{
		QString temp;
		PrintException->show();
		exception->setText(temp);
		temp.append("Exceptii: \n");
		QString exceptie = QString::fromStdString(exc.getMsg());
		temp.append(exceptie);
		exception->setText(temp);
	}
}
void GUI::clickExeAddCos()
{
	try {
		cu.add(EaddTitluCos->text().toStdString());
		model->addData(EaddTitluCos->text());
		notify();
	}
	catch (const Exception &exc)
	{
		QString temp;
		PrintException->show();
		exception->setText(temp);
		temp.append("Exceptii: \n");
		QString exceptie = QString::fromStdString(exc.getMsg());
		temp.append(exceptie);
		exception->setText(temp);
	}
}
void GUI::clickExeDel()
{
	try {
		serv.Sdel(DaddTitlu->text().toStdString(), DaddDescriere->text().toStdString(), DaddTip->text().toStdString(), DaddDurata->text().toInt());
	}
	catch (const Exception &exc)
	{
		QString temp;
		PrintException->show();
		exception->setText(temp);
		temp.append("Exceptii: \n");
		QString exceptie = QString::fromStdString(exc.getMsg());
		temp.append(exceptie);
		exception->setText(temp);
	}

}
void GUI::clickClearCos()
{
	cu.deleteAll();
	model->empty();
	notify();
}
void GUI::clickExeUpd()
{
	try {
		serv.Supd(UaddTitlu->text().toStdString(), UaddDescriere->text().toStdString(), UaddTip->text().toStdString(), UaddDurata->text().toInt(), UaddNTitlu->text().toStdString(), UaddNDescriere->text().toStdString(), UaddNTip->text().toStdString(), UaddNDurata->text().toInt());
	}
	catch (const Exception &exc)
	{
		QString temp;
		PrintException->show();
		exception->setText(temp);
		temp.append("Exceptii: \n");
		QString exceptie = QString::fromStdString(exc.getMsg());
		temp.append(exceptie);
		exception->setText(temp);
	}
}
void GUI::clickPopulateCos()
{
	hideALL();
	Populate->show();
}
void GUI::clickExePopulateCos()
{
	try {
		cu.populeaza(EaddPopulateCos->text().toInt());
		for (auto i : cu.getMem())
		{
			QString str = QString::fromStdString(i.getTitlu() + " " + i.getDescriere() + " " + i.getTip() + " " + std::to_string(i.getDurata()));
			model->addData(str);
		}
		notify();
	}
	catch (const Exception &exc)
	{
		QString temp;
		PrintException->show();
		exception->setText(temp);
		temp.append("Exceptii: \n");
		QString exceptie = QString::fromStdString(exc.getMsg());
		temp.append(exceptie);
		exception->setText(temp);
	}
}
void GUI::clickExeFilter()
{
	hideALL();
	LIST->show();
	std::vector<Activitate> filtrat;
	filtrat=serv.filtrare(Efilter1->text().toStdString(), Efilter2->text().toStdString());
	printVector(filtrat);
}
void GUI::clickExeSort()
{
	hideALL();
	SORTEDLIST->show();
	std::vector<Activitate> sortat;
	sortat = serv.sort(Esort1->text().toStdString());
	printVectorSortat(sortat);
}
void GUI::clickPrint()
{
	hideALL();
	scrollArea->show();
	QString temp;
	printList->setText(temp);
	for (auto i : serv.getRepo().getList())
	{
		temp.append("Titlu: ");
		QString titlu = QString::fromStdString(i.getTitlu());
		temp.append(titlu);
		temp.append("\n");
		temp.append("Descriere:  ");
		QString descriere= QString::fromStdString(i.getDescriere());
		temp.append(descriere);
		temp.append("\n");
		QString tip = QString::fromStdString(i.getTip());
		temp.append("Tip:  ");
		temp.append(tip);
		temp.append("\n");
		QString durata = QString::number(i.getDurata());
		temp.append("Durata:  ");
		temp.append(durata);
		temp.append("\n");
		temp.append("\n");
	}
	printList->setText(temp);
}
void GUI::clickPrintCos()
{
	Cos* cosulet = new Cos{ cu,obs,model };
	cosulet;
	//obs.push_back(cosulet);
	QString temp;
	//PrintCos->show();
	showCos->setText(temp);
	temp.append("Cosul este format din: \n");
	for (auto i : cu.getMem())
	{
		temp.append("Titlu: ");
		QString titlu = QString::fromStdString(i.getTitlu());
		temp.append(titlu);
		temp.append("\n");
		temp.append("Descriere:  ");
		QString descriere = QString::fromStdString(i.getDescriere());
		temp.append(descriere);
		temp.append("\n");
		QString tip = QString::fromStdString(i.getTip());
		temp.append("Tip:  ");
		temp.append(tip);
		temp.append("\n");
		QString durata = QString::number(i.getDurata());
		temp.append("Durata:  ");
		temp.append(durata);
		temp.append("\n");
		temp.append("\n");
	}
	showCos->setText(temp);
}

void GUI::printVector(const std::vector<Activitate>& activitati)
{
	QString temp;
	printLIST->setText(temp);
	for (auto i : activitati)
	{
		temp.append("Titlu: ");
		QString titlu = QString::fromStdString(i.getTitlu());
		temp.append(titlu);
		temp.append("\n");
		temp.append("Descriere:  ");
		QString descriere = QString::fromStdString(i.getDescriere());
		temp.append(descriere);
		temp.append("\n");
		QString tip = QString::fromStdString(i.getTip());
		temp.append("Tip:  ");
		temp.append(tip);
		temp.append("\n");
		QString durata = QString::number(i.getDurata());
		temp.append("Durata:  ");
		temp.append(durata);
		temp.append("\n");
		temp.append("\n");
	}
	printLIST->setText(temp);
}
void GUI::printVectorSortat(const std::vector<Activitate>& activitati)
{
	QString temp;
	printSorted->setText(temp);
	for (auto i : activitati)
	{
		temp.append("Titlu: ");
		QString titlu = QString::fromStdString(i.getTitlu());
		temp.append(titlu);
		temp.append("\n");
		temp.append("Descriere:  ");
		QString descriere = QString::fromStdString(i.getDescriere());
		temp.append(descriere);
		temp.append("\n");
		QString tip = QString::fromStdString(i.getTip());
		temp.append("Tip:  ");
		temp.append(tip);
		temp.append("\n");
		QString durata = QString::number(i.getDurata());
		temp.append("Durata:  ");
		temp.append(durata);
		temp.append("\n");
		temp.append("\n");
	}
	printSorted->setText(temp);
}
// Slot for the button
void GUI::on_button()
{
	QColor color = QColor(Qt::green);
	QString s1 = QString("background-color: %1").arg(color.name());
	buttonPrint->setStyleSheet(s1);
	QColor color2 = QColor(Qt::red);
	QString s2=QString("background-color: %1").arg(color2.name());
	buttonAdd->setStyleSheet(s2);
	QColor color3 = QColor(Qt::yellow);
	QString s3 = QString("background-color: %1").arg(color3.name());
	buttonDel->setStyleSheet(s3);
	QColor color4 = QColor(Qt::green);
	QString s4 = QString("background-color: %1").arg(color4.name());
	buttonUpd->setStyleSheet(s4);
	QColor color5 = QColor(Qt::red);
	QString s5 = QString("background-color: %1").arg(color5.name());
	buttonFilter->setStyleSheet(s5);
	QColor color6 = QColor(Qt::yellow);
	QString s6 = QString("background-color: %1").arg(color6.name());
	buttonSort->setStyleSheet(s6);
	QColor color7 = QColor(Qt::green);
	QString s7 = QString("background-color: %1").arg(color7.name());
	buttonAddCos->setStyleSheet(s7);
	QColor color8 = QColor(Qt::red);
	QString s8 = QString("background-color: %1").arg(color8.name());
	buttonClearCos->setStyleSheet(s8);
	QColor color9 = QColor(Qt::yellow);
	QString s9 = QString("background-color: %1").arg(color9.name());
	buttonPopulateCos->setStyleSheet(s6);
	QColor color10 = QColor(Qt::green);
	QString s10 = QString("background-color: %1").arg(color10.name());
	buttonPrintCos->setStyleSheet(s10);
	QColor color11 = QColor(Qt::red);
	QString s11 = QString("background-color: %1").arg(color11.name());
	buttonUndo->setStyleSheet(s11);
	QColor color12 = QColor(Qt::yellow);
	QString s12 = QString("background-color: %1").arg(color12.name());
	buttonExport2HTML->setStyleSheet(s12);
}
void GUI::clickForme()
{
	Forme* form = new Forme { cu.getMem() };
	obs.push_back(form);
}
void GUI::notify()
{
	for (auto i : obs)
	{
		i->update();
	}
}
void GUI::clickShowIstoric()
{
	hideALL();
	Istoric->show();
}
void GUI::clickExeIstoric()
{
	std::map<std::string, std::string> ist = serv.getIstoric();
	lista->clear();
	std::map<std::string, std::string>::iterator it = ist.begin();
	
	std::string data = istoric_line->text().toStdString();
	for (it = ist.begin(); it != ist.end(); ++it)
	{
		if (it->first == data)
		{
			QString q = QString::fromStdString(it->second);
			QListWidgetItem* el = new QListWidgetItem(q, lista);
			el;
			std::string str;
			str= it->second;
			if (serv.isKey(str) == true)
			{
				std::map<std::string, std::string>::iterator it2 = ist.begin();
				for (it2 = ist.begin(); it2 != ist.end(); ++it2)
				{
					if (it2->first == str)
					{
						QString qr = QString::fromStdString(it2->second);
						QListWidgetItem* el2 = new QListWidgetItem(qr, lista);
						el2;
					}
				}
				//str = it2->second;
			}
		}
	}

}