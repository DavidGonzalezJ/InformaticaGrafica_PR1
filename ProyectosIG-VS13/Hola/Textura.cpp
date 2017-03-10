#include "Textura.h"
#include "PixMap24RGB.h"

bool Textura::load(const std::string & BMP_Name) {
	// la textura debe estar inicializada -> escena::init()
	PixMap24RGB pixMap;
	pixMap.load_bmpBGR(BMP_Name); // cargar
								  // carga correcta??
	w = pixMap.width();
	h = pixMap.height();
	//A ver si así
	pA[w*h];

	glBindTexture(GL_TEXTURE_2D, id); // transferir a openGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB,
		GL_UNSIGNED_BYTE, pixMap.map());
	/*…*/return true;
}

void Textura::save(const std::string & BMP_Name) {
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGB, // obtener de openGL
		GL_UNSIGNED_BYTE, pA);
	// pA-> array donde guardar los datos (de tipo y tamaño adecuado)
	/*…*/ // y guardar
}