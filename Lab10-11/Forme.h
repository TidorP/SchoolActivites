#pragma once
#include <QTWidgets>
#include "Observer.h"
#include <Activitate.h>
#include <QPaintEvent>
#include <QPainter>
#include <stdlib.h>
class Forme:public QWidget,public Observer
{
private:
	std::vector<Activitate>& activitati;
	QFormLayout* mainLayout = new QFormLayout;

public:
	Forme(std::vector<Activitate>& activitati);
	void paintEvent(QPaintEvent* ev);
	void update();
};

