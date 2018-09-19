#pragma once
#include "Service.h"
#include <QObject>
#include "Current.h"
#include "Cos.h"
#include <QtWidgets>
#include <climits>
#include <cstring>
#include "Forme.h"
#include "List_view.h"
class GUI:public QObject
{
	Q_OBJECT
private:
	MyListModel* model = new MyListModel;
	Service & serv;
	Current &cu;
	std::vector<Observer*> obs;

	QScrollArea* scrollArea = new QScrollArea();

	QWidget* w = new QWidget();
	QWidget* e = new QWidget();
	QWidget* main = new QWidget();
	QWidget* Add = new QWidget();
	QWidget* Print = new QWidget();
	QWidget* Delete = new QWidget();
	QWidget* Update = new QWidget();
	QWidget* Filter = new QWidget();
	QWidget* Sort = new QWidget();
	QWidget* LIST = new QWidget();
	QWidget* SORTEDLIST = new QWidget();
	QWidget* AddCos = new QWidget();
	QWidget* PrintCos = new QWidget();
	QWidget* Populate = new QWidget();
	QWidget* PrintException = new QWidget();
	QWidget* Istoric = new QWidget();

	QFormLayout* add = new QFormLayout();
	QFormLayout* del = new QFormLayout();
	QFormLayout* upd = new QFormLayout();
	QFormLayout* filter = new QFormLayout();
	QFormLayout* sort = new QFormLayout();
	QFormLayout* print = new QFormLayout();
	QFormLayout* list = new QFormLayout();
	QFormLayout* sortedList = new QFormLayout();
	QFormLayout* addCos = new QFormLayout();
	QFormLayout* printCos = new QFormLayout();
	QFormLayout* populate = new QFormLayout();
	QFormLayout* printException = new QFormLayout();
	QFormLayout* istoric = new QFormLayout();
	QListWidget* lista = new QListWidget;

	QVBoxLayout* box = new QVBoxLayout();
	QVBoxLayout* empty = new QVBoxLayout();
	QHBoxLayout* principal = new QHBoxLayout();
	

	QLabel* printList = new QLabel("Lista activitatilor:\n");
	QLabel* printLIST = new QLabel("Lista activitatilor:\n");
	QLabel* printSorted = new QLabel("Lista activitatilor:\n");
	QLabel* addTitlu = new QLabel("Titlu:");
	QLabel* addDescriere = new QLabel("Descriere:");
	QLabel* addTip = new QLabel("Tip:");
	QLabel* addDurata = new QLabel("Durata:");
	QLabel* delTitlu = new QLabel("Titlu:");
	QLabel* delDescriere = new QLabel("Descriere:");
	QLabel* delTip = new QLabel("Tip:");
	QLabel* delDurata = new QLabel("Durata:");
	QLabel* filter1 = new QLabel("Descriere sau tip pentru filtrare?");
	QLabel* filter2 = new QLabel("Numele dupa care sa filtram: ");
	QLabel* sort1 = new QLabel("Descriere ,tip sau tip si durata pentru sortare?");
	QLabel* oldTitlu = new QLabel("Titlu:");
	QLabel* oldDescriere = new QLabel("Descriere:");
	QLabel* oldTip = new QLabel("Tip:");
	QLabel* oldDurata = new QLabel("Durata:");
	QLabel* newTitlu = new QLabel("Titlu nou:");
	QLabel* newDescriere = new QLabel("Descriere noua:");
	QLabel* newTip = new QLabel("Tip nou:");
	QLabel* newDurata = new QLabel("Durata noua:");
	QLabel* addTitluCos = new QLabel("Titlul dupa care punem in Cos:");
	QLabel* showCos = new QLabel("Lista activitatilor din Cos:\n");
	QLabel* populateCos = new QLabel("Cu cate activitati sa populam cosul? \n");
	QLabel* exception = new QLabel("Exceptie: \n");
	QLabel* istoric_data = new QLabel("Dati activitatea la care vreti istoric \n");

	QLineEdit* EaddTitlu = new QLineEdit();
	QLineEdit* EaddDescriere = new QLineEdit();
	QLineEdit* EaddTip = new QLineEdit();
	QLineEdit* EaddDurata = new QLineEdit();

	QLineEdit* DaddTitlu = new QLineEdit();
	QLineEdit* DaddDescriere = new QLineEdit();
	QLineEdit* DaddTip = new QLineEdit();
	QLineEdit* DaddDurata = new QLineEdit();
	QLineEdit* Efilter1 = new QLineEdit();
	QLineEdit* Efilter2 = new QLineEdit();
	QLineEdit* Esort1 = new QLineEdit();

	QLineEdit* UaddTitlu = new QLineEdit();
	QLineEdit* UaddDescriere = new QLineEdit();
	QLineEdit* UaddTip = new QLineEdit();
	QLineEdit* UaddDurata = new QLineEdit();
	QLineEdit* UaddNTitlu = new QLineEdit();
	QLineEdit* UaddNDescriere = new QLineEdit();
	QLineEdit* UaddNTip = new QLineEdit();
	QLineEdit* UaddNDurata = new QLineEdit();

	QLineEdit* EaddTitluCos = new QLineEdit();
	QLineEdit* EaddPopulateCos = new QLineEdit();
	QLineEdit* istoric_line = new QLineEdit();

	QPushButton* buttonPrint = new QPushButton("PrintAll");
	QPushButton* buttonAdd = new QPushButton("add");
	QPushButton* buttonDel = new QPushButton("delete");
	QPushButton* buttonUpd = new QPushButton("update");
	QPushButton* buttonFilter = new QPushButton("Filter");
	QPushButton* buttonSort = new QPushButton("Sort");
	QPushButton* buttonAddCos = new QPushButton("AddCos");
	QPushButton* buttonClearCos = new QPushButton("ClearCos");
	QPushButton* buttonPopulateCos = new QPushButton("PopulateCos");
	QPushButton* buttonPrintCos = new QPushButton("PrintCos");
	QPushButton* buttonUndo = new QPushButton("Undo");
	QPushButton* buttonExport2HTML = new QPushButton("Export2HTML");

	QPushButton* buttonExeAdd = new QPushButton("Execute");
	QPushButton* buttonExeDel = new QPushButton("Execute");
	QPushButton* buttonExeUpd = new QPushButton("Execute");
	QPushButton* buttonExeSort = new QPushButton("Execute");
	QPushButton* buttonExeFilter = new QPushButton("Execute");
	QPushButton* buttonExeAddCos = new QPushButton("Adauga in Cos");
	QPushButton* buttonExePopulateCos = new QPushButton("Adauga in Cos");
	QPushButton* buttonForme = new QPushButton("Afisare forme");
	QPushButton* button_istoric = new QPushButton("Execute");
public:
	GUI(Service& serv, Current &cu);
	void showMenu();
	void hideALL();
	void printVector(const std::vector<Activitate>& activitati);
	void printVectorSortat(const std::vector<Activitate>& activitati);
	void notify();
private slots:
	void clickAdd();
	void clickDel();
	void clickFilter();
	void clickSort();
	void clickPrint();
	void clickUpd();
	void clickAddCos();
	void clickPrintCos();
	void clickClearCos();
	void clickPopulateCos();
	void clickUndo();
	void clickExport2HTML();
	void on_button();

	void clickExeAdd();
	void clickExeDel();
	void clickExeUpd();
	void clickExeFilter();
	void clickExeSort();
	void clickExeAddCos();
	void clickExePopulateCos();
	void clickForme();

	void clickShowIstoric();
	void clickExeIstoric();

};

