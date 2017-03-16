#pragma once
#include "tipos.h"
class Triangulo
{
public:
	Triangulo();
	Triangulo(GLdouble radio);
	~Triangulo();
	void draw()const;
	void verticeZ(int numVert, GLdouble altura);

protected:
	GLdouble radio;
	PVec3 CoordenadasTriangulo[3];
	PVec3 normales[3];
	Color4 colores[3];
	PVec3 makenormal();
	CText2 cTextura[4];

};

////glPolygonModel(GL_FRONT_AND_BACK,GL_LINES);			Esto es para que se dibujen solo las l�neas