#include "UndoAdauga.h"
#include <iostream>


UndoAdauga::UndoAdauga(Activitate activitate) : act{ activitate } {}
void UndoAdauga::doUndo(Repository& rep) 
{
	rep.del(act);
}

//UndoAdauga::~UndoAdauga()
//{
//	delete this;
//}