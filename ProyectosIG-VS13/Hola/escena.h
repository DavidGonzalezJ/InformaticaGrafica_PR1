//#pragma once
#ifndef _H_escena_H_
#define _H_escena_H_
#include "tipos.h"

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
public:
  Ejes ejes;
};

//-------------------------------------------------------------------------

#endif  // _H_escena_H_
