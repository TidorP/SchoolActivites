#pragma once
#include "Repository.h"
#include <random>
class Current
{
private:
	std::vector<Activitate> mem;
	Repository &repo;

public:

	Current(Repository &repo) noexcept;
	void deleteAll()noexcept;
	void add(std::string titlu);
	void populeaza(int numar);
	std::vector<Activitate> &getMem()noexcept;
};

