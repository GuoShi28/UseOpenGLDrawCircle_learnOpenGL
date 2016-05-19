#include "pointClasscpp.h"
#include "learnOpenGLFunction.h"

#define WIDTH 600
#define HEIGHT 600



int main(int argc,char* argv[])
{
	glutInit(&argc, argv);

	//drawSphereUsePoints
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Sphere");
	drawSphereUsePoints test;
	test.init();
	test.setupDrawBack();
	//glutDisplayFunc(test.displayFunc);
	

	//drawCubicSphere
	/*glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(450, 450);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("rotate sphere");
	drawCubicSphere test;
	glutDisplayFunc(test.display);
	glutReshapeFunc(test.reshape);
	glutKeyboardFunc(test.keyboardfunc);
	glutMouseFunc(test.mousefunc);
	test.init();*/


	glutMainLoop();
	return EXIT_SUCCESS;
}

