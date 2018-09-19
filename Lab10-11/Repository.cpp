#include "Repository.h"
Repository::Repository(std::vector<Activitate>& list)noexcept :elem{list}{}

std::vector<Activitate>& Repository::getList() noexcept
{
	return this->elem;
}

int Repository::getLen() noexcept
{
	return int(this->elem.size());
}

int Repository::find(const Activitate& act) 
{
	/*for (int index = 0; index < getLen(); index++)
	{
		if (elem[index] == act) return index;
	}
	throw Exception("Element inexistent \n");*/
	auto it = std::find_if(elem.begin(), elem.end(), [&act](auto x) {return x == act; });
	if (it != elem.end())
		return int(it - elem.begin());
	throw Exception("Element inexistent \n");}
void Repository::add(const Activitate& act) 
{
	try {
		find(act);}
	catch (Exception&) {
		elem.push_back(act);
		return;}
	throw Exception("Element deja existent \n");
}

void Repository::del(const Activitate& act) 
{
	int index = 0;
	try {
		index=find(act);
		elem.erase(elem.begin()+index);}
	catch (Exception&) {
		throw Exception("Element inexistent \n");}
}
void Repository::upd(const Activitate& act, const Activitate& newact) 
{
	find(act);
	int index = 0;
	try {
		index=find(newact);}
	catch (Exception&) {
		elem[index] = newact;
		return;}
	throw Exception("Element existent \n");
}



