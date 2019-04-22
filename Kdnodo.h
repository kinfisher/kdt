#pragma once
#include "Kdpunto.h"

using namespace std;

class Kdnodo
{
public:
	Kdnodo();
	double eleMedio;
	bool hoja;
	vector<Kdpunto> puntosNodos;
	Kdnodo *next[2];

	~Kdnodo();
};

