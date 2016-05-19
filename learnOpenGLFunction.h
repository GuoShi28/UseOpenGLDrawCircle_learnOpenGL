#pragma once
#include "pointClasscpp.h"
#include <GL/glut.h>
#include <GL/GLU.h>
#include <GL/GL.h>
#include <Windows.h>
#include <cstdlib>

#define STEP_NUM 50

drawSphereUsePoints* currentInstance;

void displayCallBack()
{
	currentInstance->displayFunc();
}

class drawSphereUsePoints
{
private:
	
	void drawPoints();
	
	

public:
	void init();

	void displayFunc();
	void setupDrawBack()
	{
		currentInstance = this;
		::glutDisplayFunc(::displayCallBack);
	}
};


class drawCubicSphere
{
private:
	GLfloat m_lightPosition[4];
	GLfloat m_whiteLight[4];
	GLfloat m_matSpecular[4];
	GLfloat m_matShininess[1];
	GLfloat m_matEmission[4];
	GLfloat m_spin;

public:
	void init();
	void display();
	void reshape(int w, int h);
	void keyboardfunc(unsigned char key, int x, int y);
	void mousefunc(int button, int state, int x, int y);
};




