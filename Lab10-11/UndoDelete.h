#pragma once
#include "ActiuneUndo.h"
class UndoDelete:public ActiuneUndo
{
private:
	Activitate act;
public:
	UndoDelete(Activitate activitate);
	void doUndo(Repository& rep);
	
};

