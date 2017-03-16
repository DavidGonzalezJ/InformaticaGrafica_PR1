#include "Rectangulo.h"



Rectangulo::Rectangulo(GLdouble base, GLdouble altura)
{
	vertices[0] = { -base/2,altura/2,0.0 };
	vertices[1] = { -base / 2, -altura / 2, 0.0 };
	vertices[2] = { base / 2, altura / 2, 0.0 };
	vertices[3] = { base / 2, -altura / 2, 0.0 };
	normal = { 0,0,1 };
	cTextura[0].set(0, 1);
	cTextura[1].set(0, 0);
	cTextura[2].set(1, 1);
	cTextura[3].set(1, 0);
}

Rectangulo::~Rectangulo()
{
}

void Rectangulo::draw()const{

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_TEXTURE_2D);

	glVertexPointer(3, GL_DOUBLE, 0, vertices);
	glNormal3d(normal.x, normal.y, normal.z);

	glTexCoordPointer(2, GL_DOUBLE, 0, cTextura);
	glColor4d(color.r, color.g, color.b, color.a);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}
void Rectangulo::set(GLdouble base, GLdouble altura){
	vertices[0] = { -base / 2, altura / 2, 0.0 };
	vertices[1] = { -base / 2, -altura / 2, 0.0 };
	vertices[2] = { base / 2, altura / 2, 0.0 };
	vertices[3] = { base / 2, -altura / 2, 0.0 };
}
