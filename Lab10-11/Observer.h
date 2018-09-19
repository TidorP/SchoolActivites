#pragma once
#include <vector>
class Observer
{
public:
	virtual void update() = 0;
};

class Observable
{
private:
	std::vector<Observer*>& obs;
public:
	Observable(std::vector<Observer*>& obs) :obs{ obs } {}
	void notify()
	{
		for (Observer* observer : obs)
			observer->update();
	}
	//void Register(Observer* ob)
	//{
	//	obs.push_back(ob);
	//}
	//void Unregister(Observer* ob)
	//{
		//obs.erase(ob);
	//}
};