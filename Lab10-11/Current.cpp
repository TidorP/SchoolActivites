#include "Current.h"



Current::Current(Repository &rep) noexcept :repo{ rep } {}

void Current::deleteAll()noexcept
{
	this->mem.clear();
}
void Current::add(std::string titlu)
{
	std::vector < Activitate > activitati= repo.getList();
	auto it = std::find_if(activitati.begin(), activitati.end(), [&titlu](auto x) {return x.getTitlu() == titlu; });
	auto it2= std::find_if(mem.begin(), mem.end(), [&titlu](auto x) {return x.getTitlu() == titlu; });
	if (it == activitati.end())
		throw Exception("Titlu inexistent \n");
	if (it2 != mem.end())
		throw Exception("Activitatea cu acest titlu se afla deja in current \n");
	mem.push_back(*it);
}
void Current::populeaza(int numar)
{
	std::vector <Activitate> activitati_copy = repo.getList();
	if (numar <= int(activitati_copy.size()))
	{
		for (int i = 0; i < numar; i++)
		{
			std::mt19937 mt{ std::random_device{}() };
			std::uniform_int_distribution<> const dist(0, activitati_copy.size() - 1);
			const int rndNr = dist(mt);
			mem.push_back(activitati_copy[rndNr]);
			activitati_copy.erase(activitati_copy.begin() + rndNr);
		}
	}
	else
		throw Exception("Nu exista atatea elemente in Repository \n");
	
}
std::vector<Activitate>  & Current::getMem() noexcept
{
	return this->mem;
}
