#include "UndoUpdate.h"



UndoUpdate::UndoUpdate(Activitate activitate, Activitate newactivitate) : act{ activitate }, newact { newactivitate } {}
void UndoUpdate::doUndo(Repository& repo)
{
	repo.upd(newact, act);
}