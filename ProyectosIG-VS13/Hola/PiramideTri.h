#pragma once
#include "Triangulo.h"

class PiramideTri
{
public:
	PiramideTri(GLdouble radioB, GLdouble altura);
	~PiramideTri();
	void draw()const;
	GLdouble getAltura() { return alt; };
	void setTexCoord(CText2 const cTextura[3]);

private:
	GLdouble alt;
	Triangulo* triangulos[3];
};

