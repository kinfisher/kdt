#include "Kdtree.h"



Kdtree::Kdtree(vector<Kdpunto> points, vector<Kdpunto>limits, int lim, int dim)
{
	root = NULL;
	limite = lim;
	gdim = dim;
	creacion(root, points, 0);
}

void Kdtree::creacion(Kdnodo*& P, vector<Kdpunto>points, int dim)
{
	P = new Kdnodo();
	if (points.size() <= limite)
	{
		P->puntosNodos = points;
		return;
	}

	gdim = dim;

	sort(points.begin(), points.end(), [dim](Kdpunto a, Kdpunto b)
	{
		return a.coords[dim] < b.coords[dim];
	});

	P->hoja = false;
	int medio = points.size() / 2;
	P->eleMedio = points[medio].coords[dim];
	if (dim == 2)
	{
		dim = 0;
	}
	else
	{
		dim++;
	}

	creacion(P->next[0], vector<Kdpunto>(points.begin(), points.begin() + medio), dim);
	creacion(P->next[1], vector<Kdpunto>(points.begin() + medio + 1, points.end()), dim);



}

bool Kdtree::buscar(Kdpunto punto)
{
	Kdnodo *p;
	int dim = 0;
	for (p = root; !p->hoja; p->next[punto.coords[dim] > p->eleMedio]);

	for (int i = 0; i < p->puntosNodos.size(); i++)
	{
		if (p->puntosNodos[i].coords[0] == punto.coords[0] and p->puntosNodos[i].coords[1] == punto.coords[1] and p->puntosNodos[i].coords[2] == punto.coords[2])
		{
			return 1;
		}
	}
	return 0;
}


void Kdtree::dibujar(Kdnodo*P, vector<Kdpunto>limits, int dim)
{
	if (!P)
	{
		return;
	}

	if (P->hoja)
	{
		for (int i = 0; i < P->puntosNodos.size(); i++)
		{
			glPointSize(5.0);
			glBegin(GL_POINTS);
			glColor3d(255, 0, 0);
			glVertex3d(P->puntosNodos[i].coords[0], P->puntosNodos[i].coords[1], P->puntosNodos[i].coords[2]);
			glEnd();
		}
		return;
	}

	vector<Kdpunto> izq;
	vector<Kdpunto> der;

	if (dim == 0)
	{
		dim = 1;
		glBegin(GL_LINES);
		glColor3d(255, 0, 0);
		glVertex3d(P->eleMedio, limits[1].coords[0], limits[2].coords[0]);
		glVertex3d(P->eleMedio, limits[1].coords[1], limits[2].coords[0]);

		glColor3d(255, 0, 0);
		glVertex3d(P->eleMedio, limits[1].coords[0], limits[2].coords[1]);
		glVertex3d(P->eleMedio, limits[1].coords[1], limits[2].coords[1]);

		glColor3d(255, 0, 0);
		glVertex3d(P->eleMedio, limits[1].coords[0], limits[2].coords[0]);
		glVertex3d(P->eleMedio, limits[1].coords[0], limits[2].coords[1]);

		glColor3d(255, 0, 0);
		glVertex3d(P->eleMedio, limits[1].coords[1], limits[2].coords[0]);
		glVertex3d(P->eleMedio, limits[1].coords[1], limits[2].coords[1]);

		glEnd();

		izq.push_back(Kdpunto(P->eleMedio, limits[0].coords[1]));
		der.push_back(Kdpunto(limits[0].coords[0], P->eleMedio));

		izq.push_back(limits[1]);
		der.push_back(limits[1]);

		izq.push_back(limits[2]);
		der.push_back(limits[2]);

	}

	else if (dim == 1)
	{
		dim = 2;
		glBegin(GL_LINES);
		glColor3d(255, 0, 0);
		glVertex3d(limits[0].coords[0], P->eleMedio, limits[2].coords[0]);
		glVertex3d(limits[0].coords[1], P->eleMedio, limits[2].coords[0]);

		glColor3d(255, 0, 0);
		glVertex3d(limits[0].coords[0], P->eleMedio, limits[2].coords[1]);
		glVertex3d(limits[0].coords[1], P->eleMedio, limits[2].coords[1]);

		glColor3d(255, 0, 0);
		glVertex3d(limits[0].coords[0], P->eleMedio, limits[2].coords[0]);
		glVertex3d(limits[0].coords[0], P->eleMedio, limits[2].coords[1]);

		glColor3d(255, 0, 0);
		glVertex3d(limits[0].coords[1], P->eleMedio, limits[2].coords[0]);
		glVertex3d(limits[0].coords[1], P->eleMedio, limits[2].coords[1]);

		glEnd();

		izq.push_back(limits[0]);
		der.push_back(limits[0]);

		izq.push_back(Kdpunto(P->eleMedio, limits[1].coords[1]));
		der.push_back(Kdpunto(limits[1].coords[0], P->eleMedio));

		izq.push_back(limits[2]);
		der.push_back(limits[2]);


	}
	else
	{
		dim = 0;
		glBegin(GL_LINES);
		glColor3d(255, 0, 0);
		glVertex3d(limits[0].coords[0], limits[1].coords[0], P->eleMedio);
		glVertex3d(limits[0].coords[1], limits[1].coords[0], P->eleMedio);

		glColor3d(255, 0, 0);
		glVertex3d(limits[0].coords[0], limits[1].coords[1], P->eleMedio);
		glVertex3d(limits[0].coords[1], limits[1].coords[1], P->eleMedio);

		glColor3d(255, 0, 0);
		glVertex3d(limits[0].coords[0], limits[1].coords[0], P->eleMedio);
		glVertex3d(limits[0].coords[0], limits[1].coords[1], P->eleMedio);

		glColor3d(255, 0, 0);
		glVertex3d(limits[0].coords[1], limits[1].coords[0], P->eleMedio);
		glVertex3d(limits[0].coords[1], limits[1].coords[1], P->eleMedio);

		glEnd();

		izq.push_back(limits[0]);
		der.push_back(limits[1]);
		izq.push_back(limits[1]);
		der.push_back(limits[1]);
		izq.push_back(Kdpunto(P->eleMedio, limits[2].coords[1]));
		der.push_back(Kdpunto(limits[2].coords[0], P->eleMedio));

	}

	dibujar(P->next[0], izq, dim);
	dibujar(P->next[1], der, dim);

}




Kdtree::~Kdtree()
{
}
