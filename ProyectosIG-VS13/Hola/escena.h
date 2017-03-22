//#pragma once
#ifndef _H_escena_H_
#define _H_escena_H_
#include "tipos.h"
#include "Triangulo.h"
#include "PiramideTri.h"
#include "TriAnimado.h"
#include "Textura.h"
#include "Rectangulo.h"

//-------------------------------------------------------------------------
class Ejes {
public:
  Ejes(GLdouble l);
  ~Ejes(){};
  void draw();
public:
  PVec3 vertices[6];
  PVec3 colores[6];
};

//-------------------------------------------------------------------------

class Escena {
public:
  Escena(): ejes(200) {};
  ~Escena();
  void init();
  void draw();
  void drawDiabolo();
  void rotateDiabolo(char aux);
public:
  Ejes ejes;
  //Triangulo* tri1 = new Triangulo(50);
  PiramideTri* piramide = new PiramideTri(50, 100);
  TriAnimado* triA = new TriAnimado(50, 200, 5, 25);
  Triangulo* tri = new Triangulo(50);
  Textura tex;
  Rectangulo* rect = new Rectangulo(800,600);
};

//-------------------------------------------------------------------------

#endif  // _H_escena_H_
