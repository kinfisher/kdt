#include "Kdpunto.h"



Kdpunto::Kdpunto()
{

}

Kdpunto::Kdpunto(double _x ,double _y, double _z)
{
	
	coords.push_back(_x);
	coords.push_back(_y);
	coords.push_back(_z);
}

Kdpunto::Kdpunto(double _x, double _y)
{
	coords.push_back(_x);
	coords.push_back(_y);
}

void Kdpunto::imprimir()
{
	cout << coords[0] << " , " << coords[1] << " , " << coords[2] << endl;
}


Kdpunto::~Kdpunto()
{
}
