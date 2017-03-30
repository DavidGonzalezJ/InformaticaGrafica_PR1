#include "escena.h"
#include <GL/freeglut.h>

//-------------------------------------------------------------------------

void Escena::init(){
	//color
	Color.red = 255;
	Color.blue = 255;
	Color.green = 255;

  // texturas
	glEnable(GL_TEXTURE_2D);
	tex.init();
	tex.load("../bmps/Zelda.bmp");
	tex1.init();
	tex1.load("../bmps/ray.bmp",150);
	tex2.init();
	tex2.load("../bmps/smiley.bmp", Color, 200);
	
  // luces
}

//-------------------------------------------------------------------------

Escena::~Escena(){
   // liberar memoria y recursos 
}

//-------------------------------------------------------------------------

void Escena::draw(int pato){
	switch (pato)
	{
	case 0:
		tex.activar();
		rect->draw();
		tex.desactivar();

		ejes.draw();
		triA->draw();
		break;
	case 1:
		tex.activar();
		triA->draw();
		tex.desactivar();
		ejes.draw();
		break;
	case 2:
		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		tex.activar();
		rect->draw();
		tex.desactivar();

		glPushMatrix();
		glTranslated(150, 50, 0);
		//glRotated(-45, 0, 0, 1);
		tex2.activar();
		rect2->draw();
		glPopMatrix();
		tex2.desactivar();

		tex1.activar();
		glPushMatrix();
		glTranslated(-245, -145,0);
		glRotated(-45, 0, 0, 1);
		rect1->draw();
		glPopMatrix();
		tex1.desactivar();
		
		glDisable(GL_BLEND);
		break;
	case 3:
		ejes.draw();
		tex.activar();
		drawDiabolo();
		tex.desactivar();
		break;
	default:
		break;
	}
}

//-------------------------------------------------------------------------

void Escena::drawDiabolo() {
	glPushMatrix();
	glRotated(90.0, 1.0, 0.0, 0.0);
	glTranslated(0.0, 0.0, -piramide->getAltura());
	piramide->draw();
	glRotated(60.0, 0.0, 0.0, 1.0);
	piramide->draw();

	glRotated(180.0, 1.0, 0.0, 0.0);
	glTranslated(0.0,0.0 , -2 * piramide->getAltura());
	piramide->draw();
	glRotated(60.0, 0.0, 0.0, 1.0);
	piramide->draw();
	glPopMatrix();
}

void Escena::rotateDiabolo(char aux){

	switch (aux)
	{
	case 'x':
		glRotated(10.0, 1.0, 0.0, 0.0);
		break;
	case 'y':
		glRotated(10.0, 0.0, 1.0, 0.0);
		break;
	case 'z':
		glRotated(10.0, 0.0, 0.0, 1.0);
		break;
	default:
		break;
	}
	//drawDiabolo();
}


//-------------------------------------------------------------------------

Ejes::Ejes(GLdouble l) {
  vertices[0].set(0, 0, 0);
  vertices[1].set(l, 0, 0);
  vertices[2].set(0, 0, 0);
  vertices[3].set(0, l, 0);
  vertices[4].set(0, 0, 0);
  vertices[5].set(0, 0, l);

  colores[0].set(1, 0, 0);
  colores[1].set(1, 0, 0);
  colores[2].set(0, 1, 0);
  colores[3].set(0, 1, 0);
  colores[4].set(0, 0, 1);
  colores[5].set(0, 0, 1);
}

//-------------------------------------------------------------------------

void Ejes::draw(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, vertices);
  glEnableClientState(GL_COLOR_ARRAY);
  glColorPointer(3, GL_DOUBLE, 0, colores);
  
  glLineWidth(2);
  glDrawArrays(GL_LINES, 0, 6); 
  glLineWidth(1);

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);

 /*
  glLineWidth(2);
  glBegin(GL_LINES);
     glColor3d(1.0, 0.0, 0.0); // red
     glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);   // origin
     glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);   // x   

     glColor3d(0.0, 1.0, 0.0); // green
     glVertex3d(vertices[2].x, vertices[2].y, vertices[2].z);   // origin
     glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);	  // y

     glColor3d(0.0, 0.0, 1.0); // blue
     glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);   // origin
     glVertex3d(vertices[5].x, vertices[5].y, vertices[5].z);	  // z   
  glEnd();
  glLineWidth(1);
  */
}

//-------------------------------------------------------------------------



