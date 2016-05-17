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
	glClearColor(0, 1, 1, 1); //Q1:����ʼֵ��λ�������Ƿ���У� r,g,b,a
	glClearDepth(1.0);	//Q2:������ʼֵ�ñ仯�� 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //��glClearColor��glClearDepth���õ�ֵ������������������

	glClearColor(0, 1, 1, 1); 
	glClearDepth(1.0);	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Q3:Ϊʲô�ظ����ߣ������ˣ�

	GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 1.0f };//Q4:�ı���ֵ���Խ��Ӱ�죿
	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 0.2f };//�����⣬Q5:�ı价����Խ����Ӱ�죿
	GLfloat light_diffuse[] = { 0.5f, 0.5f, 0.5f, 0.2f };//������⣬Q6:�ı���ֵ�Խ����Ӱ�죿
	GLfloat light_specular[] = { 0.5f, 0.5f, 0.5f, 0.2f }; //���淴�䣬Q7:�ı���ֵ�Խ����Ӱ�죿
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);//ͼ����Խ��ⷴ�䵽��������
	glEnable(GL_NORMALIZE);//���ݺ���glNormal���������������÷�����
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);//��Ȼ���Ƚ�ֵ
}