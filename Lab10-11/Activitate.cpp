#include "Activitate.h"
//Activitate::Activitate()noexcept :titlu { "" }, descriere{ "" }, tip{ "" }, durata{ -1 } {}
	
Activitate::Activitate(const std::string& titlu,const std::string& descriere,const std::string& tip,const int& durata)
{
	this->titlu = titlu;
	this->descriere = descriere;
	this->tip = tip;
	this->durata = durata;
}
std::string Activitate::getTitlu()const {
	return this->titlu;
}
std::string Activitate::getDescriere()const {
	return this->descriere;
}
std::string Activitate::getTip()const {
	return this->tip;
}
int Activitate::getDurata()const noexcept{
	return this->durata;
}
void Activitate::setTitlu(const std::string& inserttitlu) {
	this->titlu= inserttitlu;
}
void Activitate::setDescriere(const std::string& insertdescriere) {
	this->descriere= insertdescriere;
}
void Activitate::setTip(const std::string& inserttip) {
	this->tip= inserttip;
}
void Activitate::setDurata(const int& insertdurata)noexcept{
	this->durata= insertdurata;
}
bool Activitate::operator==(const Activitate& ot) const
{
	if (titlu == ot.getTitlu() && descriere == ot.getDescriere() && tip == ot.getTip() && durata == ot.getDurata())
		return true;
	return false;
}
void Activitate::operator=(const Activitate& ot)
{
	setTitlu(ot.getTitlu());
	setDescriere(ot.getDescriere());
	setTip(ot.getTip());
	setDurata(ot.getDurata());
}

