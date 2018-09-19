#include "UndoDelete.h"



UndoDelete::UndoDelete(Activitate activitate) : act{ activitate } {}
void UndoDelete::doUndo(Repository& repo)
{
		repo.add(act);
}
