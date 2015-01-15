#include <windows.h>
#include <GL/glut.h>
#include "Input.h"
#include "Entity.h"
#include "Player.h"
#include "World.h"
//Player 		entity(5, 5, 50, 100, 1.0, 1.0, 0.0);
Player		entity2(20, 30, 100, 100, 1.0, 0.0, 0.0);
World		*world;
Entity		*active;
bool		added;
int			cameraX				= 0;
int			cameraY				= 0;
int			exitCode			= 0;
int			screenwidth			= 800;
int			screenheight		= 600;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void keyPress(unsigned char key, int x, int y) {
	if (key == 27)  Input::escDown = true;
	if (key == 'a')	Input::aDown = true;
	if (key == 'b')	Input::bDown = true;
	if (key == 'c')	Input::cDown = true;
	if (key == 'd')	Input::dDown = true;
	if (key == 'e')	Input::eDown = true;
	if (key == 'f')	Input::fDown = true;
	if (key == 'g')	Input::gDown = true;
	if (key == 'h')	Input::hDown = true;
	if (key == 'i')	Input::iDown = true;
	if (key == 'j')	Input::jDown = true;
	if (key == 'k')	Input::kDown = true;
	if (key == 'l')	Input::lDown = true;
	if (key == 'm')	Input::mDown = true;
	if (key == 'n')	Input::nDown = true;
	if (key == 'o')	Input::oDown = true;
	if (key == 'p')	Input::pDown = true;
	if (key == 'q')	Input::qDown = true;
	if (key == 'r')	Input::rDown = true;
	if (key == 's')	Input::sDown = true;
	if (key == 't')	Input::sDown = true;
	if (key == 'u')	Input::sDown = true;
	if (key == 'v')	Input::sDown = true;
	if (key == 'w')	Input::wDown = true;
	if (key == 'x')	Input::sDown = true;
	if (key == 'y')	Input::sDown = true;
	if (key == 'z')	Input::sDown = true;
}
void keyRelease(unsigned char key, int x, int y) {
	if (key == 27)  Input::escDown = false;
	if (key == 'a')	Input::aDown = false;
	if (key == 'b')	Input::bDown = false;
	if (key == 'c')	Input::cDown = false;
	if (key == 'd')	Input::dDown = false;
	if (key == 'e')	Input::eDown = false;
	if (key == 'f')	Input::fDown = false;
	if (key == 'g')	Input::gDown = false;
	if (key == 'h')	Input::hDown = false;
	if (key == 'i')	Input::iDown = false;
	if (key == 'j')	Input::jDown = false;
	if (key == 'k')	Input::kDown = false;
	if (key == 'l')	Input::lDown = false;
	if (key == 'm')	Input::mDown = false;
	if (key == 'n')	Input::nDown = false;
	if (key == 'o')	Input::oDown = false;
	if (key == 'p')	Input::pDown = false;
	if (key == 'q')	Input::qDown = false;
	if (key == 'r')	Input::rDown = false;
	if (key == 's')	Input::sDown = false;
	if (key == 't')	Input::sDown = false;
	if (key == 'u')	Input::sDown = false;
	if (key == 'v')	Input::sDown = false;
	if (key == 'w')	Input::wDown = false;
	if (key == 'x')	Input::sDown = false;
	if (key == 'y')	Input::sDown = false;
	if (key == 'z')	Input::sDown = false;
}
void specialKeyPress(int key, int x, int y) {
	if (key == GLUT_KEY_END)	Input::endDown		= true;
	if (key == GLUT_KEY_HOME)	Input::homeDown		= true;
	if (key == GLUT_KEY_INSERT)	Input::insDown		= true;
	if (key == GLUT_KEY_PAGE_DOWN)Input::pgdownDown	= true;
	if (key == GLUT_KEY_PAGE_UP)Input::pgupDown		= true;

	if (key == GLUT_KEY_F1)		Input::f1Down		= true;
	if (key == GLUT_KEY_F2)		Input::f2Down		= true;
	if (key == GLUT_KEY_F3)		Input::f3Down		= true;
	if (key == GLUT_KEY_F4)		Input::f4Down		= true;
	if (key == GLUT_KEY_F5)		Input::f5Down		= true;
	if (key == GLUT_KEY_F6)		Input::f6Down		= true;
	if (key == GLUT_KEY_F7)		Input::f7Down		= true;
	if (key == GLUT_KEY_F8)		Input::f8Down		= true;
	if (key == GLUT_KEY_F9)		Input::f9Down		= true;
	if (key == GLUT_KEY_F10)	Input::f10Down		= true;
	if (key == GLUT_KEY_F11){	Input::f11Down		= true; glutFullScreen(); }
	if (key == GLUT_KEY_F12)	Input::f12Down		= true;

	if (key == GLUT_KEY_DOWN)	Input::downDown		= true;
	if (key == GLUT_KEY_LEFT)	Input::leftDown		= true;
	if (key == GLUT_KEY_RIGHT)	Input::rightDown	= true;
	if (key == GLUT_KEY_UP)		Input::upDown		= true;
}
void specialKeyRelease(int key, int x, int y) {
	if (key == GLUT_KEY_END)	Input::endDown		= false;
	if (key == GLUT_KEY_HOME)	Input::homeDown		= false;
	if (key == GLUT_KEY_INSERT)	Input::insDown		= false;
	if (key == GLUT_KEY_PAGE_DOWN)Input::pgdownDown	= false;
	if (key == GLUT_KEY_PAGE_UP)Input::pgupDown		= false;

	if (key == GLUT_KEY_F1)		Input::f1Down		= false;
	if (key == GLUT_KEY_F2)		Input::f2Down		= false;
	if (key == GLUT_KEY_F3)		Input::f3Down		= false;
	if (key == GLUT_KEY_F4)		Input::f4Down		= false;
	if (key == GLUT_KEY_F5)		Input::f5Down		= false;
	if (key == GLUT_KEY_F6)		Input::f6Down		= false;
	if (key == GLUT_KEY_F7)		Input::f7Down		= false;
	if (key == GLUT_KEY_F8)		Input::f8Down		= false;
	if (key == GLUT_KEY_F9)		Input::f9Down		= false;
	if (key == GLUT_KEY_F10)	Input::f10Down		= false;
	if (key == GLUT_KEY_F11)	Input::f11Down		= false;
	if (key == GLUT_KEY_F12)	Input::f12Down		= false;

	if (key == GLUT_KEY_DOWN)	Input::downDown		= false;
	if (key == GLUT_KEY_LEFT)	Input::leftDown		= false;
	if (key == GLUT_KEY_RIGHT)	Input::rightDown	= false;
	if (key == GLUT_KEY_UP)		Input::upDown		= false;
}
void timer(int msdelay) {
	if (Input::aDown) cameraX -= 5;
	if (Input::dDown) cameraX += 5;
	if (Input::sDown) cameraY -= 5;
	if (Input::wDown) cameraY += 5;
	if (Input::escDown) exit(0);
	glLoadIdentity();
	gluOrtho2D(screenwidth / 2 * -1 + (GLdouble)cameraX, screenwidth / 2 + (GLdouble)cameraX, screenheight / 2 * -1 + (GLdouble)cameraY, screenheight / 2 + (GLdouble)cameraY);
	if (!world) world = new World();
	if (!added) {
		world->updateList[0] = new Player(200, 200, 50, 100, 1, 1, 0);
		world->updateList[1] = new Player(100, -300, 50, 50, 1,  1, 1);
        world->updateList[1]->active = false;
		added = true; }
	glClear(GL_COLOR_BUFFER_BIT);
	world->update();
	int c = 0;
	while (c < World::MAX) {
		if (world->updateList[c]) {
			active = world->updateList[c];
			glBegin(GL_QUADS);
				glColor3f(active->red, active->green, active->blue);
				glVertex2i(active->x, active->y);
				glVertex2i(active->x + active->width, active->y);
				glVertex2i(active->x + active->width, active->y + active->height);
				glVertex2i(active->x, active->y + active->height);
			glEnd(); }
		c++; }
	glutPostRedisplay();
	glutTimerFunc(30, timer, 0);
}
void render() {
	glFlush();
}
void reshape(GLsizei width, GLsizei height) {
	screenwidth = width;
	screenheight = height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(width / 2 * -1 + cameraX, width / 2 + cameraX, height / 2 * -1 + cameraY, height / 2 + cameraY);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Power Pug Invasion");
	glutFullScreen();
	glutDisplayFunc(render);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyRelease);
	glutSpecialFunc(specialKeyPress);
	glutSpecialUpFunc(specialKeyRelease);
	glutTimerFunc(0, timer, 0);
	initGL();
	glutMainLoop();
	world = new World();
	return 0;
}
