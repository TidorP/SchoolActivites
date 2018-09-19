#pragma once
#include <string>
//activity object which has title, description, type and time length
//the methods are defined in the public section
class Activitate
{
private:
	std::string titlu;
	std::string descriere;
	std::string tip;
	int durata;

public:
	//constructor 
	Activitate()noexcept;
	Activitate(const std::string& titlu,const std::string& descriere,const std::string& tip, const int& durata);
	//the below 4 functions are made for abstractization, the atributes are hidden so we need getter functions
	//to access them
	std::string getTitlu() const;
	std::string getDescriere() const;
	std::string getTip() const;
	int getDurata() const noexcept;
	/*4 functions in order to update/set the atributes
	*/
	void setTitlu(const std::string& titlu);
	void setDescriere(const std::string& descriere);
	void setTip(const std::string& tip);
	void setDurata(const int& durata)noexcept;
	/*we will rewrite the operator = and == for when using our objects
	*/
	bool operator==(const Activitate& ot) const;
	void operator=(const Activitate& ot);
};