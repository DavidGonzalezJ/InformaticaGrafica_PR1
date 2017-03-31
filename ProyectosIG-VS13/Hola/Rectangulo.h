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
	Color4 color = { 1, 0, 0, 1 };
	CText2 cTextura[4];
	GLdouble base, altura;
};

