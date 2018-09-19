#include "UI.h"
#include <iostream>
UI::UI( Service& serv,  Current& current) noexcept :serv{ serv }, cu{ current } {}


std::string UI::getCmd()const
{
	std::cout << "0:Afisare toate activitatile \n";
	std::cout << "1:Adaugare activitate noua \n";
	std::cout << "2:Stergere activitate \n";
	std::cout << "3:Actualizare activitate \n";
	std::cout << "4:Filtrare \n";
	std::cout << "5:Sortare \n \n";
	std::cout << "6:Adauga activitate noua dupa titlu in lista de activitati curente \n";
	std::cout << "7:Goleste lista de activitati curente \n";
	std::cout << "8: Populate lista activitati curente \n";
	std::cout << "9: Printeaza lista de activitati curente \n \n";
	std::cout << "10:Iesire aplicatie \n";
	std::cout << "11: Undo \n";
	std::cout << "12: Salvare in fisier \n";
	std::string cmd;
	std::cout << "Dati comanda: \n";
	std::cin >> cmd;
	return cmd;
}
void UI::uiAdd()
{
	std::cout << "Dati titlu: ";
	std::string titlu;
	std::cin >> titlu;
	std::cout << "Dati descriere: ";
	std::string descriere;
	std::cin >> descriere;
	std::cout << "Dati tip: ";
	std::string tip;
	std::cin >> tip;
	std::cout << "Dati durata: ";
	int durata;
	std::cin >> durata;
	serv.Sadd(titlu, descriere, tip, durata);
}
void UI::uiDel()
{
	std::cout << "Dati titlu: ";
	std::string titlu;
	std::cin >> titlu;
	std::cout << "Dati descriere: ";
	std::string descriere;
	std::cin >> descriere;
	std::cout << "Dati tip: ";
	std::string tip;
	std::cin >> tip;
	std::cout << "Dati durata: ";
	int durata;
	std::cin >> durata;
	serv.Sdel(titlu, descriere, tip, durata);
}
void UI::uiUpd()
{
	std::cout << "Dati datele activitatii pe care doriti sa o schimbati \n";
	std::cout << "Dati titlu: ";
	std::string titlu;
	std::cin >> titlu;
	std::cout << "Dati descriere: ";
	std::string descriere;
	std::cin >> descriere;
	std::cout << "Dati tip: ";
	std::string tip;
	std::cin >> tip;
	std::cout << "Dati durata:";
	int durata;
	std::cin >> durata;

	std::cout << "Dati datele noii activitati \n";
	std::cout << "Dati titlu nou: ";
	std::string newtitlu;
	std::cin >> newtitlu;
	std::cout << "Dati descriere noua: ";
	std::string newdescriere;
	std::cin >> newdescriere;
	std::cout << "Dati tip nou: ";
	std::string newtip;
	std::cin >> newtip;
	std::cout << "Dati durata noua: ";
	int newdurata;
	std::cin >> newdurata;
	serv.Supd(titlu, descriere, tip, durata, newtitlu, newdescriere, newtip, newdurata);
}
void UI::uiFilter() 
{
	std::vector<Activitate> v;
	std::cout << "Descriere sau Tip pentru filtrare?";
	std::string type;
	std::cin >> type;
	std::cout << "Dati numele dupa care vreti sa filtrati:";
	std::string nume;
	std::cin >> nume;
	v=serv.filtrare(type, nume);
	const int len = int(v.size());
	for (int index = 0; index < len; index++)
	{
		std::cout << "Titlu: " << v[index].getTitlu() << "\n";
		std::cout << "Descriere: " << v[index].getDescriere() << "\n";
		std::cout << "Tip: " << v[index].getTip() << "\n";
		std::cout << "Durata: " << v[index].getDurata() << "\n\n";
	}
}
void UI::uiSort()
{
	std::vector<Activitate> v;
	std::cout << "Descriere , Tip sau tip+durata pentru sortare?";
	std::string type;
	std::cin >> type;
	v = serv.sort(type);
	const int len = int(v.size());
	for (int index = 0; index < len; index++)
	{
		std::cout << "Titlu: " << v[index].getTitlu() << "\n";
		std::cout << "Descriere: " << v[index].getDescriere() << "\n";
		std::cout << "Tip: " << v[index].getTip() << "\n";
		std::cout << "Durata: " << v[index].getDurata() << "\n\n";
	}
}
void UI::adaugaCurrent()
{
	std::cout << "Dati titlu: ";
	std::string titlu;
	std::cin >> titlu;
	cu.add(titlu);
}
void UI::golesteCurrent()noexcept
{
	cu.deleteAll();
}
void UI::populateCurrent()
{
	std::cout << "Dati numar: ";
	int n;
	std::cin >> n;
	cu.populeaza(n);
}
void UI::undo()
{
	serv.undo();
}
void UI::printAll()
{
	//LinkedList<Activitate>& activitati = serv.getRepo().getList();
	/*int const len = serv.getRepo().getLen();
	
	for (int index = 0; index < len; index++)
	{
		std::cout << "Titlu: "<< serv.getRepo().getList()[index].getTitlu() << "\n";
		std::cout << "Descriere: "<< serv.getRepo().getList()[index].getDescriere() << "\n";
		std::cout << "Tip: "<< serv.getRepo().getList()[index].getTip() << "\n";
		std::cout << "Durata: "<< serv.getRepo().getList()[index].getDurata() << "\n\n";
	}*/
	for (auto i : serv.getRepo().getList())
	{
		std::cout << "Titlu: " << i.getTitlu() << "\n";
		std::cout << "Descriere: " << i.getDescriere() << "\n";
		std::cout << "Tip: " << i.getTip() << "\n";
		std::cout << "Durata: " << i.getDurata() << "\n\n";
	}

}
void UI::printCurrent()
{
	for (auto i : cu.getMem())
	{
		std::cout << "Titlu: " << i.getTitlu() << "\n";
		std::cout << "Descriere: " << i.getDescriere() << "\n";
		std::cout << "Tip: " << i.getTip() << "\n";
		std::cout << "Durata: " << i.getDurata() << "\n\n";
	}
}
void UI::exportaCosHTML(std::string fName) const {
	exportToHTML(fName, cu.getMem());
}

void UI::run()
{
	std::string cmd;
	while (true)
	{
		try {
			cmd = getCmd();
			if (cmd == "1") uiAdd();
			else if (cmd == "2") uiDel();
			else if (cmd == "3") uiUpd();
			else if (cmd == "4") uiFilter();
			else if (cmd == "5") uiSort();
			else if (cmd == "0") printAll();
			else if (cmd == "6") adaugaCurrent();
			else if (cmd == "7") golesteCurrent();
			else if (cmd == "8") populateCurrent();
			else if (cmd == "9") printCurrent();
			else if (cmd == "11") undo();
			else if (cmd == "12") exportaCosHTML("testExport.html");
			else if (cmd == "10") break;
		}
		catch ( Exception& exc)
		{
			std::cout << exc.getMsg();
		}
	}
	
}









