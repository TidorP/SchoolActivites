#pragma once
#include "Repository.h"
#include <vector>
class ActiuneUndo
{

public:
	virtual void doUndo(Repository& rep) = 0;
	virtual ~ActiuneUndo() {};
};

