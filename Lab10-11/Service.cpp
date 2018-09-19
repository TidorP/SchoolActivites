#include "Service.h"


Service::Service(Repository& rep)noexcept :repo{ rep } {}
Repository& Service::getRepo() noexcept
{
	return this->repo;
}
bool Service::validate(const std::string& titlu, const std::string& descriere, const std::string& tip, const int& durata)const
{
	if (titlu == "") throw Exception("Titlu vid!\n");
	if (descriere == "") throw Exception("Descriere vid!\n");
	if (tip == "") throw Exception("Tip vid!\n");
	if (durata <= 0) throw Exception("Durata trebuie sa fie pozitiva \n");
	return true;
}
void Service::Sadd(const std::string& titlu, const std::string& descriere, const std::string& tip, const int& durata)
{
	bool const val = validate(titlu, descriere, tip, durata);
	if (val == true)
	{
		Activitate act = Activitate(titlu, descriere, tip, durata);
		repo.add(act);
		UndoAdauga* und = new UndoAdauga{ act };
		actiuni.push_back(und);
	}
}
void Service::Sdel(const std::string& titlu, const std::string& descriere, const std::string& tip, const int& durata)
{
	bool const val = validate(titlu, descriere, tip, durata);
	if (val == true)
	{
		Activitate act = Activitate(titlu, descriere, tip, durata);
		repo.del(act);
		UndoDelete* und = new UndoDelete{ act };
		actiuni.push_back(und);
	}
}
void Service::Supd(const std::string& titlu, const std::string& descriere, const std::string& tip, const int& durata, const std::string& newtitlu, const std::string& newdescriere, const std::string& newtip, const int& newdurata)
{
	bool const val1 = validate(titlu, descriere, tip, durata);
	bool const val2 = validate(newtitlu, newdescriere, newtip, newdurata);
	if (val1 == true && val2 == true)
	{	
		Activitate act = Activitate(titlu, descriere, tip, durata);
		Activitate newact = Activitate(newtitlu, newdescriere, newtip, newdurata);
		repo.upd(act, newact);
		UndoUpdate* und = new UndoUpdate{ act,newact };
		actiuni.push_back(und);
		istoric.insert(std::make_pair(newact.getTitlu(),act.getTitlu()) );
	}
}
std::map<std::string, std::string> Service::getIstoric()
{
	return istoric;
}
bool Service::isKey(std::string key)
{
	std::map<std::string, std::string>::iterator it = istoric.begin();
	for (it = istoric.begin(); it != istoric.end(); ++it)
	{
		if (it->first == key)
			return true;
	}
	return false;
}
std::vector<Activitate> Service::filtrare(const std::string& type, const std::string& nume)
{
	std::vector<Activitate>& activitati=repo.getList();
	std::vector<Activitate> filter;
	/*int const len = repo.getLen();
	if (type == "descriere")
	{
		for (int index = 0; index < len; index++)
		{
			if (activitati[index].getDescriere() == nume) filter.push_back(activitati[index]);
			
		}
	}
	if (type =="tip")
	{
		for (int index = 0; index < len; index++)
		{
			if (activitati[index].getTip() == nume) filter.push_back(activitati[index]);

		}
	}*/
	if (type == "descriere")
		std::copy_if(activitati.begin(), activitati.end(), back_inserter(filter), [&nume](auto x) {return x.getDescriere() == nume; });
	if (type == "tip")
		std::copy_if(activitati.begin(), activitati.end(), back_inserter(filter), [&nume](auto x) {return x.getTip() == nume; });
	return filter;
}
std::vector<Activitate> Service::sort(const std::string& type)
{
	std::vector<Activitate> activitati = repo.getList();
	/*int const len = repo.getLen();
	if (type == "titlu")
	{
		for (int index = 0; index < len - 1; index++)
		{
			for (int index2 = index + 1; index2 < len; index2++)
				if (activitati[index].getTitlu() > activitati[index2].getTitlu())
				{
					Activitate aux = activitati[index];
					activitati[index] = activitati[index2];
					activitati[index2] = aux;
				}


		}
	}
	if (type == "descriere")
	{
		for (int index = 0; index < len - 1; index++)
		{
			for (int index2 = index + 1; index2 < len; index2++)
				if (activitati[index].getDescriere() > activitati[index2].getDescriere())
				{
					Activitate aux = activitati[index];
					activitati[index] = activitati[index2];
					activitati[index2] = aux;
				}


		}
	}
	if (type == "tip+durata")
	{
		for(int index = 0; index < len - 1; index++)
		{
			for (int index2 = index + 1; index2 < len; index2++)
				if (activitati[index].getTip() > activitati[index2].getTip()||(activitati[index].getTip()== activitati[index2].getTip()&& activitati[index].getDurata() > activitati[index2].getDurata()))
				{
					Activitate aux = activitati[index];
					activitati[index] = activitati[index2];
					activitati[index2] = aux;
				}


		}
	}*/
	if (type == "titlu")
		std::sort(activitati.begin(), activitati.end(), [](auto x, auto y){ return x.getTitlu() < y.getTitlu(); });
	if (type == "descriere")
		std::sort(activitati.begin(), activitati.end(), [](auto x, auto y) { return x.getDescriere() < y.getDescriere(); });
	if (type == "tip+durata")
		std::sort(activitati.begin(), activitati.end(), [](auto x, auto y) { return x.getTip() < y.getTip() || (x.getTip() == y.getTip() && x.getDurata()<y.getDurata()); });
	return activitati;
}

void Service::undo()
{	
	if (actiuni.size() == 0) throw Exception("Nu se mai poate face Undo \n");
	actiuni[actiuni.size()-1]->doUndo(repo);
	ActiuneUndo* nume=actiuni[actiuni.size() - 1];
	actiuni.pop_back();
	nume;
	delete nume;
}
Service::~Service()
{
	for (auto& undoh : actiuni)
		delete undoh;
}


