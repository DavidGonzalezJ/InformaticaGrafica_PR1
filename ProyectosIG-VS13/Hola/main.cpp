//#include <Windows.h>
//#include <gl/GL.h>
//#include <gl/GLU.h>
//#include <GL/glut.h>

#include <GL/freeglut.h>

#include "tipos.h"
#include "escena.h"

#include <iostream>
using namespace std;

//-------------------------------------------------------------------------

// Window size
int winWidth = 800, winHeight = 600;

// Viewport 
PuertoVista viewPort(0, 0, winWidth, winHeight);

// Camera: Scene visible area size and projection
Camara camera(winWidth, winHeight);

// Scene variables
Escena escena;

//----------- Callbacks ----------------------------------------------------

void display();
void resize(int newWidth, int newHeight);
void key(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
bool pinchado;

//------------ ESTADOS -----------------------------------------------------
enum Estado{RECORTAR,ANIMAR,COLLAGE,DIABOLO};
Estado actState;
bool basaur=false;
//-------------------------------------------------------------------------
void intitGL(){ //OpenGL basic setting

  //glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  //glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_POLYGON_SMOOTH);
  //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  //glShadeModel(GL_SMOOTH);

  glClearColor(1.0, 1.0, 1.0, 1.0);  // color de fondo (alpha=1 -> opaco)
    
  // ViewPort
  viewPort.set(viewPort.x, viewPort.y, winWidth, winHeight);  // glViewport(0, 0, WIDTH, HEIGHT);

  // Camera position and orentation
  camera.setEZ(); 
  // Scene visible area and projection  
  camera.setVV();

  // Luz ambiente global
  //GLfloat amb[]={0.25, 0.25, 0.25, 1.0};
  //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
  // Light0  set up
  glEnable(GL_LIGHT0);
  GLfloat LuzDifusa[4] = { 1, 1, 1, 1.0 };
  glLightfv(GL_LIGHT0, GL_DIFFUSE, LuzDifusa);
  //GLfloat LuzSp[4] = { 1, 1, 1, 1 };
  //glLightfv(GL_LIGHT0, GL_SPECULAR, LuzSp);
  //GLfloat LuzAmbiente[4]={0.3f, 0.3f, 0.3f, 1.0f};
  //glLightfv(GL_LIGHT0, GL_AMBIENT, LuzAmbiente);
  GLfloat posLuz0[4] = { 100.0, 100.0, 100.0, 0.0 };
  glLightfv(GL_LIGHT0, GL_POSITION, posLuz0);

  cout << glGetString(GL_VERSION) << '\n';
  cout << glGetString(GL_VENDOR) << '\n';
 }

//-------------------------------------------------------------------------

int main(int argc, char *argv[]){

  cout << "Starting console..." << '\n';

  // Initialization
  glutInitWindowSize(winWidth, winHeight);
  //glutInitWindowPosition (140, 140);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInit(&argc, argv);

  // Window construction
  int win = glutCreateWindow( "Freeglut-project" );  // window's identifier

    
  // Callback registration
  glutReshapeFunc(resize);
  glutKeyboardFunc(key);
  glutSpecialFunc(specialKey);
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);

  // OpenGL basic setting
  intitGL();
  actState = Estado::COLLAGE;
  pinchado = false;
  glDisable(GL_DEPTH_TEST);
  escena.init();
  escena.triA->position(0, 0);

  glutSetOption ( GLUT_ACTION_ON_WINDOW_CLOSE, /*GLUT_ACTION_CONTINUE_EXECUTION*/GLUT_ACTION_EXIT ) ; 
						         // after X-closing the window, continue execution
  glutMainLoop();


  cin.sync();
  cin.get();

  return 0;
}

//-------------------------------------------------------------------------
void tilling(){
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			viewPort.set((winWidth / 3)*i, (winHeight / 4)*j, (winWidth / 3), winWidth / 4);
			escena.draw(actState);
		}
	}
	viewPort.set(0, 0, winWidth, winHeight);
}
//-------------------------------------------------------------------------

void display(){
 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

  if (!basaur)
	escena.draw(actState);
  else{
	  tilling();
  }

  glPopMatrix();
  
  glutSwapBuffers();  //glFlush();
}

//-------------------------------------------------------------------------

void resize(int newWidth, int newHeight){

  winWidth = newWidth;
  winHeight = newHeight;

  // Resize Viewport
  viewPort.set(viewPort.x, viewPort.y, winWidth, winHeight);  //glViewport(0, 0, WIDTH, HEIGHT);

  // Resize Scene Visible Area 
  camera.setVV(winWidth, winHeight);
}

//-------------------------------------------------------------------------

void key(unsigned char key, int x, int y){

  bool need_redisplay = true;

  switch (key) {
  case 27:  // Escape key 
    glutLeaveMainLoop(); // Freeglut's sentence for stopping glut's main loop 
    break;
  case '+':
    glScaled(1.1, 1.1, 1.1); // aumentar la escala 
    break;
  case '-':
    glScaled(0.9, 0.9, 0.9); // reducir la escala 
    break;
  case 'l':
	  camera.set3D(); 
	  break;
  case 'm':
	  if (actState == Estado::DIABOLO){
		  basaur= !basaur;
	  }
	  break;
  case 'o':
	  camera.setEZ();
	  break;
  case 'r':
	  escena.triA->rotate();
	  break;
  case 't':
	  if (actState == Estado::ANIMAR){
		basaur = false;
		escena.triA->update();
	  }
	  break;
  case 'x':
	  if (actState == Estado::DIABOLO){
		  escena.rotateDiabolo(key);
	  }
	  break;
  case 'y':
	  if (actState == Estado::DIABOLO){
		  escena.rotateDiabolo(key);
	  }
	  break;
  case 'z':
	  if (actState == Estado::DIABOLO){
		  escena.rotateDiabolo(key);
	  }
	  break;
  case '2':
	  if (actState == Estado::COLLAGE){
		  basaur = false;
		  //CAPTURAMOS y sobreescribimos la text1
		  escena.tex.activar();
		  escena.tex.save("../bmps/collage.bmp");
		  escena.tex.load("../bmps/collage.bmp");
		  escena.tex.desactivar();
		  actState = Estado::RECORTAR;
	  }
	  break;
  case '3':
	  if (actState == Estado::RECORTAR){
		  basaur = false;
		  glDisable(GL_DEPTH_TEST);
		  escena.triA->capturaTextura(winWidth,winHeight);
		  actState = Estado::ANIMAR;
		  escena.triA->reset();
	  }
	  else if (actState == Estado::DIABOLO) {
		  basaur = false;
		  glDisable(GL_DEPTH_TEST);
		  actState = Estado::ANIMAR;
		  camera.setEZ();
		  escena.triA->reset();
	  }
	  break;
  case '4':
	  actState = Estado::DIABOLO;
	  basaur = false;
	  escena.piramide->setTexCoord(escena.triA->cTextura);
	  glEnable(GL_DEPTH_TEST);
	  break;
  default:
    need_redisplay = false;
    break;
  }//switch

  if (need_redisplay)
    glutPostRedisplay();
}

//-------------------------------------------------------------------------

void specialKey(int key, int x, int y){

  bool need_redisplay = true;

  switch (key) {
  case GLUT_KEY_RIGHT:
    glTranslated(1, 0, 0);  // trasladar 1 en el eje X
    break;
  case GLUT_KEY_LEFT:
    glTranslated(-1, 0, 0);
    break;
  case GLUT_KEY_UP:
    glRotated(1, 0, 0, 1);  // girar 1 en el eje Z
    break;
  case GLUT_KEY_DOWN:
    glRotated(-1, 0, 0, 1);
    break;
  default:
    need_redisplay = false;
    break;
  }//switch

  if (need_redisplay)
    glutPostRedisplay();
}

//-------------------------------------------------------------------------

void mouse(int button, int state, int x, int y){
  if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) { // DOWN
	int transX = -winWidth / 2 + x;
	int transY = -(-winHeight/2 + y);
	if (escena.triA->dentro(transX, transY)) {
	  pinchado = true;
	}
  }
  else {
	  pinchado = false;
  }
}

//-------------------------------------------------------------------------
 
void motion(int x, int y){
	int transX = -winWidth / 2 + x;
	int transY = -(-winHeight / 2 + y);
	if (pinchado && actState == Estado::RECORTAR) {
		escena.triA->position(transX, transY);
		glutPostRedisplay();
	}
}

