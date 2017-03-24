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
	void position(GLdouble x, GLdouble y);
	void rotate();
	void actualizaCoord();
	bool dentro(GLdouble x, GLdouble y);
	void capturaTextura(GLdouble winWidth, GLdouble winHeigth);
	void setcTex(CText2 const cTexturo[3]);
	bool text;
	CText2 cTextura[3];

protected:
	GLdouble pi = 3.1416;
	GLdouble radio;
	PVec3 CoordenadasTriangulo[3];
	PVec3 normales[3];
	Color4 colores[3];
	PVec3 makenormal();
	GLdouble angulo;
	PVec3 centro = { 0, 0, 0 };

};

////glPolygonModel(GL_FRONT_AND_BACK,GL_LINES);			Esto es para que se dibujen solo las líneas