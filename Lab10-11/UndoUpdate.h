#pragma once
#include "ActiuneUndo.h"
class UndoUpdate :public ActiuneUndo
{
private:
	Activitate act;
	Activitate newact;
public:
	UndoUpdate(Activitate activitate, Activitate newact);
	void doUndo(Repository& rep);

};