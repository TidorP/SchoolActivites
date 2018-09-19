#pragma once
#include <string>
#include <vector>
#include "Activitate.h"
/*
Scrie in fisierul fName lista de animale
in format HTML
arunca PetException daca nu poate crea fisierul
*/
void exportToHTML(const std::string& fName, const std::vector<Activitate>& activitati);