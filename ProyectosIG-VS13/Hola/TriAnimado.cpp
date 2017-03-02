#include "TriAnimado.h"



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
	//Primero lo desplazamos
	PVec3 centroNuevo = { cos(anguloAcumuladoGiro)*radioGiro, CoordenadasTriangulo[0].y, sin(anguloAcumuladoGiro)*radioGiro };
	GLdouble pi = 3.1416;
	GLdouble transfRad = (anguloAcumuladoRot*pi) / 180;
	CoordenadasTriangulo[0] = { radio + centroNuevo.x /*- radio* cos(transfRad)*/ ,0,centroNuevo.z /*- radio* sin(transfRad)*/ };
	CoordenadasTriangulo[1] = { radio * cos(2 * pi / 3) + centroNuevo.x + radio* cos(transfRad), radio * sin(2 * pi / 3),centroNuevo.z + radio* sin(transfRad) };
	CoordenadasTriangulo[2] = { radio * cos(2 * pi / 3) + centroNuevo.x + radio* cos(transfRad), -radio * sin(2 * pi / 3),centroNuevo.z + radio* sin(transfRad) };
	anguloAcumuladoGiro += anguloGiro;
	//Ahora lo rotamos
	/*CoordenadasTriangulo[0] = { CoordenadasTriangulo[0].x,CoordenadasTriangulo[0].y,CoordenadasTriangulo[0].z };
	CoordenadasTriangulo[1] = { CoordenadasTriangulo[1].x,CoordenadasTriangulo[1].y,CoordenadasTriangulo[1].z };
	CoordenadasTriangulo[2] = { CoordenadasTriangulo[2].x,CoordenadasTriangulo[2].y,CoordenadasTriangulo[2].z };*/
	anguloAcumuladoRot += anguloRota;
}