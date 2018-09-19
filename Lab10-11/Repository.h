#pragma once
#include "Activitate.h"
#include "Exception.h"
#include <algorithm>
#include <vector>
//class repo which has a vector that contains activity objects
class Repository
{

private:
	std::vector<Activitate> elem;

public:
	//default constructor
	Repository(std::vector<Activitate>& list)noexcept;
	//getter function in order to acces the private memory
	std::vector<Activitate>& getList()noexcept;
	int getLen()noexcept;
	/*find function which returns the index in which we can find an activity in our memory vector
	in: activity object
	out: index of the act in the vector or -1 if we cannot find it
	*/
	int find(const Activitate& act);
	/*add function to add a new entity to our vector of entities
	in: activity object
	*/
	void add(const Activitate& act);
	/*delete function to delete a present entity from our vector of entities (we also use the find function)
	in: activity object
	*/
	void del(const Activitate& act);
	/*update function to update a present entity from our vector of entities to a new one (we also use the find function)
	in: activity object and the new one (we also use the find function)
	*/
	void upd(const Activitate& act, const Activitate& newact);

};

