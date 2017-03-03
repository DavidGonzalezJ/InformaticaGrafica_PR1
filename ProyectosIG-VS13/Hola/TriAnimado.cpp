#include "TriAnimado.h"
#include <GL/freeglut.h>



TriAnimado::TriAnimado(GLdouble radio, GLdouble radioGiro, GLdouble giro, GLdouble rota):Triangulo(radio),radioGiro(radioGiro),anguloGiro(giro),anguloRota(rota)
{
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

	GLdouble pi = 3.1416;
	GLdouble transAG = (anguloAcumuladoGiro*pi) / 180;
	GLdouble transfRad = (anguloAcumuladoRot*pi) / 180;
	centro = { radioGiro* cos(transAG), radioGiro*sin(transAG),0 };

	//Ahora lo rotamos
	CoordenadasTriangulo[0] = { radio*cos(transfRad) + centro.x, radio * sin(transfRad) + centro.y, CoordenadasTriangulo[0].z + centro.z };
	CoordenadasTriangulo[1] = { radio*cos(transfRad + 2 * pi / 3) + centro.x, radio * sin(transfRad + 2 * pi / 3) + centro.y, CoordenadasTriangulo[1].z + centro.z };
	CoordenadasTriangulo[2] = { radio*cos(transfRad + 4 * pi / 3) + centro.x, radio * sin(transfRad + 4 * pi / 3) + centro.y, CoordenadasTriangulo[2].z + centro.z };




	/*
	PVec3 centroNuevo = { cos(anguloAcumuladoGiro)*radioGiro, CoordenadasTriangulo[0].y, sin(anguloAcumuladoGiro)*radioGiro };
	//Primero lo desplazamos
	CoordenadasTriangulo[0] = { radio + centroNuevo.x , 0 , centroNuevo.z };
	CoordenadasTriangulo[1] = { radio * cos(2 * pi / 3) + centroNuevo.x , radio * sin(2 * pi / 3),centroNuevo.z };
	CoordenadasTriangulo[2] = { radio * cos(2 * pi / 3) + centroNuevo.x , -radio * sin(2 * pi / 3),centroNuevo.z };

	//Ahora lo rotamos
	CoordenadasTriangulo[0] = { radio*cos(transfRad), radio * sin(transfRad), CoordenadasTriangulo[0].z };
	CoordenadasTriangulo[1] = { radio*cos(transfRad + 2 * pi / 3), radio * sin(transfRad + 2 * pi / 3), CoordenadasTriangulo[1].z };
	CoordenadasTriangulo[2] = { radio*cos(transfRad + 4 * pi / 3), radio * sin(transfRad + 4 * pi / 3), CoordenadasTriangulo[2].z };
	*/
	anguloAcumuladoGiro += anguloGiro;
	anguloAcumuladoRot += anguloRota;

	
}
