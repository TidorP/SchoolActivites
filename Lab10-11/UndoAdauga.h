#pragma once
#include "ActiuneUndo.h"
class UndoAdauga: public ActiuneUndo
{
private:
	Activitate act;
public:
	UndoAdauga(Activitate activitate);
	void doUndo(Repository& rep);
	//~UndoAdauga();
};






