#include "PiramideTri.h"



PiramideTri::PiramideTri(GLdouble radioB, GLdouble altura):alt(altura)
{
	triangulos[0] = new Triangulo(radioB);
	triangulos[0]->verticeZ(0,altura);
	triangulos[1] = new Triangulo(radioB);
	triangulos[1]->verticeZ(1, altura);
	triangulos[2] = new Triangulo(radioB);
	triangulos[2]->verticeZ(2, altura);
}

PiramideTri::~PiramideTri()
{
	for (int i = 0; i < 3; i++) {
		delete triangulos[i];
	}
}

void PiramideTri::draw()const {
	for (int i = 0; i < 3; i++) {
		triangulos[i]->draw();
	}
}