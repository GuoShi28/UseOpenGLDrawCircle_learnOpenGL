#include "define.h"
#define WIDTH 600
#define HEIGHT 600


int main(int argc,char* argv[])
{
	glutInit(&argc, argv);

	//drawSphereUsePoints
	/*glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Sphere");
	drawSphereUsePoints test;
	test.init();
	test.setupDrawBack();*/
	
	

	//drawCubicSphere
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(450, 450);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("rotate sphere");
	drawCubicSphere test;
	test.init();
	test.SetUpDisplay();
	test.SetUpReshape();
	test.SetUpKeyBoardFunc();
	test.SetUpMouseFunc();

	glutMainLoop();
	return EXIT_SUCCESS;
}

