#include "Rectangulo.h"



Rectangulo::Rectangulo(GLdouble base, GLdouble altura)
{
	vertices[0] = { 0.0,0.0,0.0 };
	vertices[1] = {base,0.0,0.0 };
	vertices[2] = { base,altura,0.0 };
	vertices[3] = { 0.0,altura,0.0 };
}

Rectangulo::~Rectangulo()
{
}

void Rectangulo::draw()const {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_DOUBLE, 0, vertices);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_DOUBLE, 0, colores);

	glLineWidth(2);
	glDrawArrays(GL_TRIANGLE_STRIP , 0, 3);
	glDrawArrays(GL_LINE_LOOP, 0, 3);
	glLineWidth(1);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

}