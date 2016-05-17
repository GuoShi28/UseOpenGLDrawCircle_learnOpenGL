#include <GL/glut.h>
#include <GL/GLU.h>
#include <GL/GL.h>

int main(int argc,char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Sphere");

	init();
	glutDisplayFunc(disPlayFunc);
	glutMainLoop();
}

void init()
{
	glClearColor(0, 1, 1, 1); //Q1:将初始值换位其他的是否可行？ r,g,b,a
	glClearDepth(1.0);	//Q2:更换初始值得变化？ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //将glClearColor与glClearDepth设置的值，消除到整个窗口上

	glClearColor(0, 1, 1, 1); 
	glClearDepth(1.0);	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Q3:为什么重复两边？打重了？

	GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 1.0f };//Q4:改变数值，对结果影响？
	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 0.2f };//环境光，Q5:改变环境光对结果的影响？
	GLfloat light_diffuse[] = { 0.5f, 0.5f, 0.5f, 0.2f };//漫反射光，Q6:改变数值对结果的影响？
	GLfloat light_specular[] = { 0.5f, 0.5f, 0.5f, 0.2f }; //镜面反射，Q7:改变数值对结果的影响？
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);//图像可以将光反射到各个方向
	glEnable(GL_NORMALIZE);//根据函数glNormal的设置条件，启用法向量
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);//深度缓冲比较值
}