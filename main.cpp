#include <GL/glut.h>
#include <GL/GLU.h>
#include <GL/GL.h>
#include "pointClasscpp.h"
#include "learnOpenGLFunction.h"

#define WIDTH 600
#define HEIGHT 600

int main(int argc,char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Sphere");

	//drawSphereUsePoints
	drawSphereUsePoints test;
	test.init();
	glutDisplayFunc(test.displayFunc);
	glutMainLoop();
}

