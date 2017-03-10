#include "Rectangulo.h"



Rectangulo::Rectangulo(GLdouble base, GLdouble altura):textura(base,altura)
{
	vertices[0] = { 0.0,0.0,0.0 };
	vertices[1] = {base,0.0,0.0 };
	vertices[2] = { base,altura,0.0 };
	vertices[3] = { 0.0,altura,0.0 };
	//textura.s = base;
	//textura.t = altura;
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
/*
Define una clase Rectangulo para guardar las coordenadas 3D de los cuatro vértices y
sus coordenadas de textura, un atributo para el color y otro para el vector normal.
Una constructora con dos argumentos para el ancho y el alto, que genera los vértices
del rectángulo centrado en el plano Z=0 y paralelo a los ejes X e Y. La constructora
asignará las coordenadas de textura para que aparezca toda la imagen en el
rectángulo. El método draw() utiliza GL_TRIANGLE_STRIP y glNormal3*() y
glColor4*(color). Añade un método set(ancho, alto) para modificar el tamaño del
rectángulo.
*/