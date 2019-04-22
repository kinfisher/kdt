#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Kdpunto
{
public:
	vector<double>coords;
	Kdpunto();
	Kdpunto(double, double); //creacion de puntos graficos
	Kdpunto(double, double, double);
	void imprimir();
	~Kdpunto();
};

