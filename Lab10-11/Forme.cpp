#include "Forme.h"



Forme::Forme(std::vector<Activitate>& activitati): activitati { activitati }
{
	this->setLayout(mainLayout);
	this->show();
	setMinimumWidth(500);
	setMaximumWidth(500);
	setMinimumHeight(500);
	setMaximumHeight(500);
}
void Forme::paintEvent(QPaintEvent* ev)
{
	QPainter p{ this };
	int i;
	for(i=0;i<activitati.size();i++)
	p.drawRect(1+rand()%300,2+rand()%300,3+rand()%190,2+rand()%180);
	ev;
}
void Forme::update()
{
	repaint();
}
