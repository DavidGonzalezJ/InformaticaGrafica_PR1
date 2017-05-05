#include "Hipotrocoide.h"


Hipotrocoide::Hipotrocoide(int nP, int nQ, GLfloat a, GLfloat b, GLfloat c) : nP(nP), nQ(nQ), a(a), b(b), c(c)
{
	creaPerfil();
	numeroVertices = nP*nQ;
	vertice = new PuntoVector3D* [numeroVertices];
	numeroCaras = nP*(nQ - 1);
	cara = new Cara*[numeroCaras];
	numeroNormales = numeroCaras;
	normal = new PuntoVector3D*[numeroNormales];

	t=0.0f;
	for (int i = 1; i < nQ; i++)
	{
		t += 0.5f;
		rellenaMatriz();
		for (int j = 0; j < nP; j++)
		{
			vertice[j + nP*i] = multMatriz(j);
		}
		/*Postmultiplicas el perfil por la matriz y vas guardadno cada uno de las coordenadas en nuevos puntos*/
	}
	/*2.- Bucle de la constructora:
	Crear el perfil;
	Crear vértices iniciales;
	Repetir nQ veces:
		Aumentar t;
		Calcular m(t);
		Crear nuevos vértices;
Unirlos con los vértices anteriores formando caras;*/

}


Hipotrocoide::~Hipotrocoide()
{
}

void Hipotrocoide::creaPerfil(){
	perfil = new PuntoVector3D* [nP];
	GLdouble ang = (2 * pi) / nP;

	for  (int i = 0; i < nP; i++)
	{
		perfil[i] = (rad*cos(ang*i), 0, rad* sin(ang*i), 0);
	}

}

PuntoVector3D* Hipotrocoide::C(GLfloat t){
	return  new PuntoVector3D((a - b)*cos(t) + c*cos(t*((a - b) / b)),
		0, 
		(a - b)*sin(t) - c*sin(t*((a - b) / b)), 0 );
}

PuntoVector3D* Hipotrocoide::C’(GLfloat t){
	return  new PuntoVector3D(-(a - b)*sin(t) - c*((a - b) / b)*sin(t*((a - b) / b)),
		0,
		(a - b)*cos(t) - c*((a - b) / b)*cos(t*((a - b) / b)) , 0);
}

PuntoVector3D* Hipotrocoide::C’’(GLfloat t){
	return new PuntoVector3D(-(a - b)*cos(t) - c*((a - b) / b)*((a - b) / b)*cos(t*((a - b) / b)),
		0,
		-(a - b)*sin(t) + c*((a - b) / b) *((a - b) / b) * sin(t*((a - b) / b)), 0);
}

PuntoVector3D* Hipotrocoide::T(GLfloat t){
	PuntoVector3D* aux = C’(t)->clonar();
	aux->normalizar();
	return aux;
}

PuntoVector3D* Hipotrocoide::B(GLfloat t){
	PuntoVector3D* aux = C’(t)->clonar();
	PuntoVector3D* aux1 = C’’(t)->clonar();
	aux = aux->productoVectorial(aux1);
	aux->normalizar();
	return aux;
}

PuntoVector3D* Hipotrocoide::N(GLfloat t){
	PuntoVector3D* aux = B(t)->clonar();
	PuntoVector3D* aux1 = T(t)->clonar();
	aux = aux->productoVectorial(aux1);
	return aux;
}

void Hipotrocoide::rellenaMatriz(){
	PuntoVector3D* b= B(t);
	m[0] = b->getX();
	m[1] = b->getY();
	m[2] = b->getZ();
	m[3] = 0;

	b= N(t);
	m[4] = b->getX();
	m[5] = b->getY();
	m[6] = b->getZ();
	m[7] = 0;

	b = T(t);
	m[8] = b->getX();
	m[9] = b->getY();
	m[10] = b->getZ();
	m[11] = 0;

	b = C(t);
	m[12] = b->getX();
	m[13] = b->getY();
	m[14] = b->getZ();
	m[15] = 1;

}
PuntoVector3D* Hipotrocoide::multMatriz(int perf){
	PuntoVector3D* aux = new PuntoVector3D (0,0,0,0);

	aux->sumar( new PuntoVector3D (
		perfil[perf]->getX()*m[0] + perfil[perf]->getY()*m[1] + perfil[perf]->getZ()*m[2],
		perfil[perf]->getX()*m[4] + perfil[perf]->getY()*m[5] + perfil[perf]->getZ()*m[6],
		perfil[perf]->getX()*m[8] + perfil[perf]->getY()*m[9] + perfil[perf]->getZ()*m[10], 
		perfil[perf]->getX()*m[12] + perfil[perf]->getY()*m[13] + perfil[perf]->getZ()*m[14]));

	return aux;
}