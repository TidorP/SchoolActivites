#include "Tests.h"
#include <string>
#include "Repository.h"
#include "Service.h"
#include <iostream>
#include <assert.h>
#include "Current.h"

void testAdd()
{
	std::vector<Activitate> list;
	Repository repo{list};
	Activitate act = Activitate("aa", "bb", "cc", 3);
	repo.add(act);
	std::vector<Activitate>& activitati = repo.getList();
	assert(activitati[0].getDescriere() == "bb");
	const int len= repo.getLen();
	assert(len == 1);
	try {
		repo.add(act);}
	catch (Exception&)
	{
		assert(true);
	}
}
void testFind()
{
	std::vector<Activitate> list; 
	Repository repo{list};
	Activitate act = Activitate("aa", "bb", "cc", 3);
	repo.add(act);
	Activitate otheract = Activitate("a", "b", "c", 3);
	assert(repo.find(act) == 0);
	try {
		repo.find(otheract);}
	catch(const Exception &exc)
	{	
		assert(exc.getMsg() == "Element inexistent \n");
		assert(true);
	}
}
void testDelete()
{
	std::vector<Activitate> list; 
	Repository repo{list};
	Activitate act = Activitate("aa", "bb", "cc", 3);
	repo.add(act);
	Activitate otheract = Activitate("a", "b", "c", 3);
	repo.add(otheract);
	repo.del(act);
	std::vector<Activitate>& activitati = repo.getList();
	assert(activitati[0].getTitlu() != "aa");
	assert(activitati[0].getTitlu() == "a");
	repo.add(act);
	repo.del(act);
	assert(activitati[0].getTitlu() == "a");
	Activitate inex = Activitate("apr", "bds", "cds", 3);
	try {
		repo.del(inex);}
	catch (const Exception &exc)
	{
		assert(exc.getMsg() == "Element inexistent \n");
		assert(true);
	}
}
void testUpdate()
{
	std::vector<Activitate> list; 
	Repository repo{list};
	std::vector<Activitate>& activitati = repo.getList();;
	Activitate act = Activitate("aa", "bb", "cc", 3);
	repo.add(act);
	Activitate otheract = Activitate("a", "b", "c", 3);
	repo.upd(act, otheract);
	assert(activitati[0].getTitlu() == "a");
	Activitate inex = Activitate("apr", "bds", "cds", 3);
	repo.add(inex);
	try {
		repo.upd(inex,otheract);}
	catch (const Exception &exc)
	{
		assert(exc.getMsg() == "Element existent \n");
		assert(true);
	}
}
void testServiceAdd()
{
	std::vector<Activitate> list; 
	Repository repo{list};
	Service serv{repo};
	serv.Sadd("aa", "bb", "cc", 3);
	std::vector<Activitate>& activitati = serv.getRepo().getList();
	assert(activitati[0].getTitlu() == "aa");
}
void testServiceDelete()
{
	std::vector<Activitate> list; 
	Repository repo{list};
	Service serv = Service(repo);
	serv.Sadd("aa", "bb", "cc", 3);
	serv.Sadd("a", "b", "c", 3);
	serv.Sdel("aa", "bb", "cc", 3);
	std::vector<Activitate>& activitati = serv.getRepo().getList();
	assert(activitati[0].getTitlu() == "a");
}
void testServiceUpd()
{
	std::vector<Activitate> list; 
	Repository repo{list};
	Service serv = Service(repo);
	serv.Sadd("aa", "bb", "cc", 3);
	serv.Supd("aa", "bb", "cc", 3, "a", "b", "c", 3);
	std::vector<Activitate>& activitati = serv.getRepo().getList();
	assert(activitati[0].getTitlu() == "a");
}
void testFiltrare()
{
	std::vector<Activitate> list; 
	Repository repo{list};
	Service serv = Service(repo);
	serv.Sadd("ka", "ob", "xc", 3);
	serv.Sadd("a", "b", "c", 3);
	serv.Sadd("w", "t", "b", 3);
	std::vector<Activitate> v;
	v = serv.filtrare("descriere", "b");
	assert(v[0].getTitlu() == "a");
	v = serv.filtrare("tip", "b");
	assert(v[0].getTitlu() == "w");

}
void testSort()
{
	std::vector<Activitate> list;
	Repository repo{list};
	Service serv = Service(repo);
	serv.Sadd("ka", "ob", "xc", 3);
	serv.Sadd("a", "b", "c", 3);
	serv.Sadd("w", "t", "b", 3);
	std::vector<Activitate> v;
	v = serv.sort("descriere");
	assert(v[0].getTitlu() == "a");
	assert(v[1].getTitlu() == "ka");
	v = serv.sort("tip+durata");
	assert(v[0].getTitlu() == "w");
	assert(v[1].getTitlu() == "a");
	v = serv.sort("titlu");
	assert(v[0].getTitlu() == "a");
	assert(v[1].getTitlu() == "ka");
}
void testAddCurrent()
{
	std::vector<Activitate> mem;
	Repository repo{ mem };
	Current cu{ repo };
	std::string titlu="aa";
	Activitate act = Activitate("aa", "bb", "cc", 3);
	repo.add(act);
	cu.add(titlu);
	assert(cu.getMem()[0].getDurata() == 3);
	try {
		cu.add("a");}
	catch (Exception&)
	{
		assert(true);
	}
	try {
		cu.add("aa");}
	catch (Exception&)
	{
		assert(true);
	}
}
void testGolesteCurrent()
{
	std::vector<Activitate> mem;
	Repository repo{ mem };
	Current cu{ repo };
	std::string titlu = "aa";
	Activitate act = Activitate("aa", "bb", "cc", 3);
	repo.add(act);
	cu.add(titlu);
	cu.deleteAll();
	assert(cu.getMem().size()==0);
}
void testPopulate()
{
	std::vector<Activitate> mem;
	Repository repo{ mem };
	Current cu{ repo };
	Activitate act = Activitate("aa", "bb", "cc", 3);
	repo.add(act);
	Activitate otheract = Activitate("a", "b", "c", 3);
	repo.add(otheract);
	cu.populeaza(2);
	assert(cu.getMem().size() == 2);
	try {
		cu.populeaza(4);}
	catch (Exception&)
	{
		assert(true);
	}

}
void testUndo()
{
	std::vector<Activitate> list;
	Repository repo{ list };
	Service serv = Service(repo);
	serv.Sadd("ka", "ob", "xc", 3);
	serv.Sadd("a", "b", "c", 3);
	serv.undo();
	std::vector<Activitate>& activitati = repo.getList();
	assert(activitati[0].getTitlu() == "ka");
	assert(activitati.size() == 1);
	serv.Sdel("ka", "ob", "xc", 3);
	serv.undo();
	std::vector<Activitate>& activi = repo.getList();
	assert(activi[0].getTitlu() == "ka");
	assert(activi.size() == 1);
	serv.Supd("ka", "ob", "xc", 3, "a", "b", "c", 3);
	serv.undo();
	std::vector<Activitate>& ac = repo.getList();
	assert(ac[0].getTitlu() == "ka");
}
#include <fstream>
void testExport()
{
	std::vector<Activitate> list;
	Repository repo{ list };
	Service serv = Service(repo);
	serv.Sadd("ka", "ob", "xc", 3);
	serv.Sadd("a", "b", "c", 3);
	serv.Sadd("w", "t", "b", 3);
	std::vector<Activitate>& activitati = repo.getList();
	exportToHTML("test.html", activitati);
	std::ifstream in("test.html");
	in.open("testExport.html");
	assert(in.is_open());

	//daca se da un nume de fisier invalid se arunca exceptie
	try {
		exportToHTML("test/Export.html", activitati);}
		//assert(false);
	catch (Exception&) {
		assert(true);}
}

void run_tests()
{
	testAdd();
	testFind();
	testDelete();
	testUpdate();
	testServiceAdd();
	testServiceDelete();
	testServiceUpd();
	testFiltrare();
	testSort();
	testAddCurrent();
	testGolesteCurrent();
	testPopulate();
	testUndo();
	testExport();
}
