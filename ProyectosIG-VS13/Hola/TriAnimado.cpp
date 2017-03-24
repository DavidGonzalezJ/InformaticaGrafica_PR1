#include "TriAnimado.h"
#include <GL/freeglut.h>



TriAnimado::TriAnimado(GLdouble radio, GLdouble radioGiro, GLdouble giro, GLdouble rota):Triangulo(radio),radioGiro(radioGiro),anguloRota(rota)
{
	centro = { radioGiro, 0, 0 };
	anguloGiro=giro;
	CoordenadasTriangulo[0].x += radioGiro;
	CoordenadasTriangulo[1].x += radioGiro;
	CoordenadasTriangulo[2].x += radioGiro;
	anguloAcumuladoGiro = anguloGiro;
	anguloAcumuladoRot = anguloRota;
}


TriAnimado::~TriAnimado()
{
}

void TriAnimado::update() {
		
	GLdouble transAG = (anguloAcumuladoGiro*pi) / 180;
	angulo = (anguloAcumuladoRot*pi) / 180;
	centro = { radioGiro* cos(transAG), radioGiro*sin(transAG),0 };
	actualizaCoord();

	anguloAcumuladoGiro += anguloGiro;
	anguloAcumuladoRot += anguloRota;
}

void TriAnimado::reset() {
	centro = { radioGiro,0,0 };
	angulo = 0;
	actualizaCoord();
}