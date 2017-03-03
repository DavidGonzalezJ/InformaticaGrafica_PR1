#pragma once
#include "tipos.h"
class Rectangulo
{
public:
	Rectangulo(GLdouble base, GLdouble altura);
	~Rectangulo();
	void draw()const;

private:
	PVec3 vertices[4];
	PVec3 normal[4];
	PVec3 colores[4];//Yo creo que eso no hace... eh, no es
	CText2 textura;
};

