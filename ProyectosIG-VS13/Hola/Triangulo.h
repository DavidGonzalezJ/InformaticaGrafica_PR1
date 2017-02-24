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
	
	
	PVec3 makenormal(){
		PVec3 aux,aux2,resul;

		aux.x = (CoordenadasTriangulo[2].x - CoordenadasTriangulo[1].x);
		aux.y = (CoordenadasTriangulo[2].y - CoordenadasTriangulo[1].y);
		aux.z = (CoordenadasTriangulo[2].z - CoordenadasTriangulo[1].z);

		aux2.x = (CoordenadasTriangulo[0].x - CoordenadasTriangulo[1].x);
		aux2.x = (CoordenadasTriangulo[0].y - CoordenadasTriangulo[1].y);
		aux2.z = (CoordenadasTriangulo[0].z - CoordenadasTriangulo[1].z);

		resul.x = aux.y*aux2.z - aux.z*aux2.y;
		resul.y = aux.z*aux2.x - aux.x*aux2.z;
		resul.z = aux.x*aux2.y - aux.y*aux2.x;
		resul.normalize();
		return resul;
	}

};

////glPolygonModel(GL_FRONT_AND_BACK,GL_LINES);			Esto es para que se dibujen solo las líneas