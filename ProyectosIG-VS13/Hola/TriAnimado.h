#pragma once
#include "Triangulo.h"
class TriAnimado :
	public Triangulo
{
public:
	TriAnimado(GLdouble radio);
	virtual ~TriAnimado();
private:
	GLdouble anguloGiro;
	GLdouble anguloRota;
	GLdouble radioGiro;
};

