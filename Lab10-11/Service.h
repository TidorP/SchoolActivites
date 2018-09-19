#pragma once
#include <map>
#include "Repository.h"
#include "UndoAdauga.h"
#include "ActiuneUndo.h"
#include "UndoDelete.h"
#include "UndoUpdate.h"
#include "Export.h"
#include <utility> 
//Service class which works with a repository
class Service
{
private:
	std::vector<ActiuneUndo*> actiuni;
	std::map<std::string,std::string > istoric;
	Repository &repo;

public:
	//constructor
	Service(Repository& repo)noexcept;
	//function to acces the repository
	Repository& getRepo() noexcept;
	//function to validate our data of entry 
	bool validate(const std::string& titlu, const std::string& descriere, const std::string& tip, const int& durata)const;
	/*The add function from service which of course uses the add function from repo
	In: our atributes data collected from UI
	*/
	void Sadd(const std::string& titlu, const std::string& descriere, const std::string& tip, const int& durata);
	/*The delete function from service which of course uses the delete function from repo
	In: our atributes data collected from UI
	*/
	void Sdel(const std::string& titlu, const std::string& descriere, const std::string& tip, const int& durata);
	/*The update function from service which of course uses the update function from repo
	In: our atributes data collected from UI
	*/
	void Supd(const std::string& titlu, const std::string& descriere, const std::string& tip, const int& durata, const std::string& newtitlu, const std::string& newdescriere, const std::string& newtip, const int& newdurata);
	/*Filter function if we want to list all activities characterized by a given type and the name of that type
	In: our atributes data collected from UI
	Out: a vector that contains our list of enitites respecting the aforementioned conditions 
	*/
	std::vector<Activitate> filtrare(const std::string& type, const std::string& nume);
	/*Function which sorts the entities by a given type (collected from the UI)
	In: the type we want to sort by
	Out: vector that contains the sorted activities
	*/
	std::vector<Activitate> sort(const std::string& type);
	std::map<std::string, std::string> getIstoric();
	bool isKey(std::string key);
	void undo();
	~Service();

};

