#pragma once
#include "Service.h"
#include <string>
#include "Current.h"
//class Ui which uses a service
class UI
{
private:
	Service &serv;
	Current &cu;

public:
	//constructor
	UI( Service& serv,  Current& current) noexcept;
	// function in order to get the command from the user and to list the menu
	std::string getCmd()const;
	//add function 
	void uiAdd();
	//delete function
	void uiDel();
	//update function
	void uiUpd();
	//filter function constant
	void uiFilter();
	//sort fucntion constant
	void uiSort();
	//we need this function to print all the entities we do have right now
	void printAll();
	//run
	void printCurrent();
	void adaugaCurrent();
	void golesteCurrent()noexcept;
	void populateCurrent();
	void undo();
	void exportaCosHTML(std::string fName)const;
	void run();
};

