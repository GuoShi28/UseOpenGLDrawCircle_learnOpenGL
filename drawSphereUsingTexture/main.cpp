#pragma once

#include <GL/glut.h>
#include <GL/GLU.h>
#include <GL/GL.h>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

#define stripeImageWidth 32
GLubyte stripeImage[4 * stripeImageWidth];

#ifdef GL_VERSION_1_1
static GLuint texName;
#endif

void makeStripeImage(void)
{
	int j;
	for (j = 0; j < stripeImageWidth; j++)
	{
		stripeImage[4 * j] = (GLubyte)((j <= 4) ? 255 : 0);
		stripeImage[4 * j + 1] = (GLubyte)((j > 4) ? 255 : 0);	//why use this judge?
		stripeImage[4 * j + 2] = (GLubyte)0;
		stripeImage[4 * j + 3] = (GLubyte)255;
	}
}

//planes for texture coordinate generation
static GLfloat xequalzero[] = { 1.0, 0.0, 0.0, 0.0 };
static GLfloat slanted[] = { 1.0, 1.0, 1.0, 0.0 };
static GLfloat *currentCoeff;
static GLenum currentPlane;
static GLint currentGenMode;
static float roangles;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	
	makeStripeImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);	//use?

#ifdef GL_VERSION_1_1
	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_1D, texName);	//why not 2D
#endif
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);	//use?
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//use?
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	//use?
#ifdef GL_VERSION_1_1
	glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, stripeImageWidth, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);
#else
	glTexImage1D(GL_TEXTURE_1D, 0, 4, stripeImageWidth, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);	//use?
#endif			
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	currentCoeff = xequalzero;
	currentGenMode = GL_OBJECT_LINEAR;
	currentPlane = GL_OBJECT_PLANE;
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);	//use?
	glTexGenfv(GL_S, currentPlane, currentCoeff);

	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_1D);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glFrontFace(GL_CW);	//use?
	//glCullFace(GL_BACK);
	glMaterialf(GL_FRONT, GL_SHININESS, 64.0);
	roangles = 45.0f;
}





