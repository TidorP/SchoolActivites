#include "GUI.h"
#include "UI.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::vector<Activitate> list;
	Repository repo{ list };
	Current c{ repo };
	Service serv{ repo };
	//UI ui{ serv,c };
	GUI gui{ serv,c };
	run_tests();
	gui.showMenu();
	//ui.run();
	return a.exec();
}
