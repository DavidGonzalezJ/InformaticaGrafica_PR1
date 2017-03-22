#pragma once
#include "Triangulo.h"
class TriAnimado :
	public Triangulo
{
public:
	TriAnimado(GLdouble radio, GLdouble radioGiro, GLdouble giro, GLdouble rota);
	virtual ~TriAnimado();
	void update();
private:
	GLdouble anguloRota;
	GLdouble anguloGiro;
	GLdouble radioGiro;
	GLdouble anguloAcumuladoGiro;
	GLdouble anguloAcumuladoRot;
};

