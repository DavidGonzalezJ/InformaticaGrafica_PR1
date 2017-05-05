#pragma once
#include "Malla.h"
float const pi = 3.1416;
class Hipotrocoide: public Malla
{
public:
	Hipotrocoide(int nP, int nQ, GLfloat a, GLfloat b, GLfloat c);
	~Hipotrocoide();

private:
	GLfloat a, b, c, t; //parámetros de la curva
	int nP; //número de lados del polígono que aproxima el grosor de la curva (perfil)
	int nQ; //número de de muestras que se toman en la curva (repeticiones del perfil)
	GLfloat m[16]; //matriz para pasar el perfil a la curva
	PuntoVector3D** perfil; //polígono de nP lados
	int rad = 12; //radio para el perfil

	PuntoVector3D* C(GLfloat t);
	PuntoVector3D* C’(GLfloat t);
	PuntoVector3D* C’’(GLfloat t);
	PuntoVector3D* T(GLfloat t);
	PuntoVector3D* B(GLfloat t);
	PuntoVector3D* N(GLfloat t);
	void creaPerfil();
	void rellenaMatriz(); 

	PuntoVector3D* multMatriz(int perf);
};

/*La clase Hipotrocoide
Atributos
GLfloat a, b, c: parámetros de la curva
int nP: número de lados del polígono que aproxima el grosor de la curva
int nQ: número de de muestras que se toman en la curva
GLfloat m[16]: matriz para pasar el perfil a la curva
PuntoVector3D** perfil: polígono de nP lados
Métodos
PuntoVector3D* C(t), C’(t), C’’(t), T(t), B(t), N(t): métodos necesarios para rellenar la matriz m
Constructora
Hipotrocoide(nP, nQ, a, b, c):
	1.- Se crean los arrays de vértices, normales y caras
2.- Bucle de la constructora:
	Crear el perfil;
	t=0.0f;
	Crear vértices iniciales;
	Repetir nQ veces:
		Aumentar t;
		Calcular m(t);
		Crear nuevos vértices;
Unirlos con los vértices anteriores formando caras;*/