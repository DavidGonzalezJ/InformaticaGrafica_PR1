#include "Textura.h"

bool Textura::load(const std::string & BMP_Name) {
	// la textura debe estar inicializada -> escena::init()
	PixMap24RGB pixMap;
	pixMap.load_bmpBGR(BMP_Name); // cargar
	if (!(pixMap.is_null())) {	 // carga correcta??
		w = pixMap.width();
		h = pixMap.height();


		glBindTexture(GL_TEXTURE_2D, id); // transferir a openGL
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGB,
			GL_UNSIGNED_BYTE, pixMap.map());
		return true;
	}
	else return false;
}

bool Textura::load(const std::string & BMP_Name, GLubyte alpha) {
	PixMap24RGB pixMap;
	pixMap.load_bmpBGR(BMP_Name); // cargar
	GLubyte* info = pixMap.create_RGBA(alpha);
	if (!(pixMap.is_null())) {	 // carga correcta??
		w = pixMap.width();
		h = pixMap.height();


		glBindTexture(GL_TEXTURE_2D, id); // transferir a openGL
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, info);
		return true;
	}
	else return false;
}

bool Textura::load(const std::string & BMP_Name, PixMap24RGB::rgb_color colorKey, GLubyte alpha) {


	return true;
}

void Textura::save(const std::string & BMP_Name) {
	pA[w*h];
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGB,GL_UNSIGNED_BYTE, pA);
	// pA-> array donde guardar los datos (de tipo y tama�o adecuado)
	/*�*/ // y guardar
}