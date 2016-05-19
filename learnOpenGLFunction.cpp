#include "learnOpenGLFunction.h"


void drawSphereUsePoints::drawPoints()
{
	double u_step = 1 / (double)STEP_NUM;
	double v_step = 1 / (double)STEP_NUM;
	double u = 0;
	double v = 0;
	for (int i = 0; i < STEP_NUM; i++)
	{
		glBegin(GL_LINE_LOOP);
		Point a(0, 0);
		glVertex3d(a.x, a.y, a.z);
		Point b(u, v_step);
		glVertex3d(b.x, b.y, b.z);
		Point c(u + u_step, v_step);
		glVertex3d(c.x, c.y, c.z);
		u += u_step;
		glEnd();
	}
	u = 0;
	v = v_step;
	for (int i = 0; i < STEP_NUM - 1; i++)
	{
		for (int j = 0; j < STEP_NUM - 1; j++)
		{
			glBegin(GL_LINE_LOOP);
			Point a(u, v);
			Point b(u + u_step, v);
			Point c(u + u_step, v + v_step);
			Point d(u, v + v_step);
			glVertex3d(a.x, a.y, a.z);
			glVertex3d(b.x, b.y, b.z);
			glVertex3d(c.x, c.y, c.z);
			glVertex3d(d.x, d.y, d.z);
			u += u_step;
			glEnd();
		}
		v += v_step;
	}
	u = 0;
	for (int i = 0; i < STEP_NUM; i++)
	{
		glBegin(GL_LINE_LOOP);
		Point a(0, 1);
		Point b(u, 1 - v_step);
		Point c(u + u_step, 1 - v_step);
		glVertex3d(a.x, a.y, a.z);
		glVertex3d(b.x, b.y, b.z);
		glVertex3d(c.x, c.y, c.z);
		glEnd();
	}
}

void drawSphereUsePoints::init()
{
	glClearColor(0, 1, 1, 1);
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //将glClearColor与glClearDepth设置的值，消除到整个窗口上

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

void drawSphereUsePoints::displayFunc()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	//回复默认为初始矩阵
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glRotated(30, 1, 0, 0);
	glRotated(60, 0, 1, 0);
	glRotated(90, 0, 0, 1);
	drawSphereUsePoints();
	glutSwapBuffers();
}


////
void drawCubicSphere::init()
{
	m_lightPosition[0] = 10.0;
	m_lightPosition[1] = 10.0;
	m_lightPosition[2] = 10.0;
	m_lightPosition[3] = 0.0;
	m_whiteLight[0] = 0.8;
	m_whiteLight[1] = 0.8;
	m_whiteLight[2] = 0.8;
	m_whiteLight[3] = 1.0;
	m_matSpecular[0] = 0.3;
	m_matSpecular[1] = 0.3;
	m_matSpecular[2] = 0.3;
	m_matSpecular[3] = 1.0;
	m_matShininess[0] = 20.0;
	m_matEmission[0] = 0.3;
	m_matEmission[1] = 0.3;
	m_matEmission[2] = 0.3;
	m_matEmission[3] = 1.0;
	m_spin = 0;
	
	glClearColor(0.3, 0.3, 0.3, 1.0);
	glClearDepth(1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, m_lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, m_whiteLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, m_whiteLight);
}

void drawCubicSphere::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BITS);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -10, 10);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(m_spin, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_matSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, m_matShininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, m_matEmission);
	glutSolidSphere(3.0, 16, 16);
	glPopMatrix();
	glFlush();
}

void drawCubicSphere::reshape(int w, int h)
{
	glViewport(0.0, 0.0, (GLsizei)w, (GLsizei)h);
}

void drawCubicSphere::keyboardfunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		m_spin += 30;
		break;
	case 'b':
		m_spin -= 30;
		break;
	}
	if (m_spin < 360) m_spin += 360;
	else if (m_spin >= 360) m_spin -= 360;
	glutPostRedisplay();
}

void drawCubicSphere::mousefunc(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			m_matEmission[0] += 1.0;
			if (m_matEmission[0] > 1.0)	m_matEmission[0] -= 1.1;
			break;
		case GLUT_MIDDLE_BUTTON:
			m_matEmission[1] += 1.0;
			if (m_matEmission[1] > 1.0)	m_matEmission[1] -= 1.1;
			break;
		case GLUT_RIGHT_BUTTON:
			m_matEmission[2] += 1.0;
			if (m_matEmission[2] > 1.0)	m_matEmission[2] -= 1.1;
			break;	
		}
		glutPostRedisplay();
	}
}

