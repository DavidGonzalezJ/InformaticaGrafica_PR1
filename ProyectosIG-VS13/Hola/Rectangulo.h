#pragma once
#include "tipos.h"

class Rectangulo
{
public:
	Rectangulo(GLdouble base, GLdouble altura);
	~Rectangulo();
	void draw()const;
	void set(GLdouble base1, GLdouble altura1);
	void position(GLdouble x, GLdouble y);

private:
	PVec3 vertices[4];
	PVec3 normal;
	//PVec3 colores[4];//Yo creo que eso no hace... eh, no es
	Color4 color = { 1, 0, 0, 1 };
	CText2 cTextura[4];
	//GLvoid * cTextura;
	GLdouble base, altura;
};

