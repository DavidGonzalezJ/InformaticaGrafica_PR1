#pragma once
#include "tipos.h"
class Triangulo
{
public:
	Triangulo();
	~Triangulo();
private:
	PVec3 CoordenadasTriangulo[3];
	PVec3 normales[3];
	PVec3 colores[3];

};

