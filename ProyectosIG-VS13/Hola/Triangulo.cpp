#include "Triangulo.h"


Triangulo::Triangulo()
{
}

Triangulo::Triangulo(GLdouble radio):radio(radio)
{
	angulo = 0;
	colores[0].set(1, 0, 0, 1);
	colores[1].set(0, 0, 1, 1);
	colores[2].set(0, 1, 0, 1);
	//Coordenadas textura
	cTextura[0].set(0, 1);
	cTextura[1].set(0, 0);
	cTextura[2].set(1, 1);
	//cTextura[3].set(1, 0);
	text = false;
	GLdouble pi = 3.1416;
	CoordenadasTriangulo[0]={radio,0,0};
	CoordenadasTriangulo[1] = { radio * cos(2 * pi / 3) , radio * sin(2 * pi / 3),0 };
	CoordenadasTriangulo[2] = { radio * cos(2 * pi / 3), -radio * sin(2 * pi / 3),0 };
	for (int i = 0; i < 3; i++) { normales[i]=makenormal(); }
}


Triangulo::~Triangulo()
{
}

//Pone un vertice en el eje Z con la altura que se pasa
void Triangulo::verticeZ(int numVert, GLdouble altura) {
	CoordenadasTriangulo[numVert] = { 0,0,altura };
	for (int i = 0; i < 3; i++) { normales[i] = makenormal(); }
}

void Triangulo::draw()const {

	if (!text){
		glEnableClientState(GL_VERTEX_ARRAY);
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);//
		//glEnableClientState(GL_TEXTURE_2D);//

		glVertexPointer(3, GL_DOUBLE, 0, CoordenadasTriangulo);
		glNormal3d(normales[0].x, normales[0].y, normales[0].z);
		//glTexCoordPointer(2, GL_DOUBLE, 0, cTextura);//

		glColor4d(colores[0].r, colores[0].g, colores[0].b, colores[0].a);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//Dibuja lineas
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//Dibuja relleno
		glDisableClientState(GL_VERTEX_ARRAY);
		//glDisableClientState(GL_TEXTURE_2D);
		//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	else{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);//
		glEnableClientState(GL_TEXTURE_2D);//

		glVertexPointer(3, GL_DOUBLE, 0, CoordenadasTriangulo);
		glNormal3d(normales[0].x, normales[0].y, normales[0].z);
		glTexCoordPointer(2, GL_DOUBLE, 0, cTextura);//

		glColor4d(colores[0].r, colores[0].g, colores[0].b, colores[0].a);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//Dibuja lineas
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//Dibuja relleno
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_2D);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	
	}
}

void Triangulo::capturaTextura(GLdouble winWidth, GLdouble winHeigth){
	//AQUI CAMBIO LAS COORD DE TEXTURA ...
	//Si la coord x del vertice A      es      winWidth/2 + posicion       sobre        winWidth
	//La proporcion en cTextura        es             "ALGO"               sobre           1
	//Y así con todas las coord de los 3 vertices
	//    GG EZ

	text = true;

}


PVec3 Triangulo::makenormal() {
	PVec3 aux, aux2, resul;

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

void Triangulo::position(GLdouble x, GLdouble y){
	
	centro = { x, y, 0 };
	actualizaCoord();
}

void Triangulo::rotate(){
	
	GLdouble rotar = 5*pi / 180;
	angulo += rotar;
	actualizaCoord();
	
}
void Triangulo::actualizaCoord(){

	//Ahora lo rotamos
	CoordenadasTriangulo[0] = { radio*cos(angulo) + centro.x, radio * sin(angulo) + centro.y, CoordenadasTriangulo[0].z + centro.z };
	CoordenadasTriangulo[1] = { radio*cos(angulo + 2 * pi / 3) + centro.x, radio * sin(angulo + 2 * pi / 3) + centro.y, CoordenadasTriangulo[1].z + centro.z };
	CoordenadasTriangulo[2] = { radio*cos(angulo + 4 * pi / 3) + centro.x, radio * sin(angulo + 4 * pi / 3) + centro.y, CoordenadasTriangulo[2].z + centro.z };

}


bool Triangulo::dentro(GLdouble x, GLdouble y){
	if ((CoordenadasTriangulo[0].x - x) * (CoordenadasTriangulo[1].y - y) - (CoordenadasTriangulo[0].y - y) * (CoordenadasTriangulo[1].x - x) < 0)
		return false;
	else if ((CoordenadasTriangulo[1].x - x) * (CoordenadasTriangulo[2].y - y) - (CoordenadasTriangulo[1].y - y) * (CoordenadasTriangulo[2].x - x) < 0)
		return false;
	else if ((CoordenadasTriangulo[2].x - x) * (CoordenadasTriangulo[0].y - y) - (CoordenadasTriangulo[2].y - y) * (CoordenadasTriangulo[0].x - x) < 0)
		return false;
	else return true;
}