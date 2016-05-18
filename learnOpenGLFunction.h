#pragma once
#include "pointClasscpp.h"
#include <GL/glut.h>
#include <GL/GLU.h>
#include <GL/GL.h>

#define STEP_NUM 50

class drawSphereUsePoints
{
private:
	void drawPoints();
public:
	void init();	
	void displayFunc();
};


class drawCubicSphere
{
private:
	GLfloat lightPosition[];
	GLfloat whiteLight[];
	GLfloat matSpecular[];
	GLfloat matShininess[];
	GLfloat matEmission[];
	GLfloat spin;

public:
	void init();

};
