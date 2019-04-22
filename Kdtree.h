#pragma once
#include <GL/glut.h>
#include "Kdnodo.h"

class Kdtree
{
public:
	Kdtree(vector<Kdpunto>, vector<Kdpunto>, int,int);
	bool buscar(Kdpunto);
	void creacion(Kdnodo*&, vector<Kdpunto>, int);
	vector<Kdpunto> limites;
	int limite;
	Kdnodo *root;	
	int gdim;
	void dibujar(Kdnodo*, vector<Kdpunto>, int);
	~Kdtree();
};

