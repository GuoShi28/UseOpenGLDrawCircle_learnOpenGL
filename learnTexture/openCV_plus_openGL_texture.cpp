#include <GL/glut.h>
#include <GL/GL.h>
#include <opencv2/opencv.hpp>

#define SOLOVE_COORDINATE

GLuint texture;	
cv::Mat img;
GLfloat angle = 0.0;
unsigned char* textureImage;
static GLint spinx = 0;	
/*note: gs 2016/06/12 20:03  */
//why static?
static GLint spiny = 0;

void makeTextureImg(cv::Mat& src_img)
{
	int width = src_img.cols;
	int height = src_img.rows;

	int ch = src_img.channels();
	if (ch == 3)
	{
		textureImage = new unsigned char[width * height * 3];
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				textureImage[3 * (i*width + j) + 0] = src_img.at<cv::Vec3b>(i, j)[0];
				textureImage[3 * (i*width + j) + 1] = src_img.at<cv::Vec3b>(i, j)[1];
				textureImage[3 * (i*width + j) + 2] = src_img.at<cv::Vec3b>(i, j)[2];
			}
		}
	}
	else if (ch == 1)
	{
		textureImage = new unsigned char[width * height];
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				textureImage[i*width + j] = src_img.at<uchar>(i, j);
			}
		}
	}
}
#ifdef SOLOVE_COORDINATE
	GLUquadricObj * m_pQuadratic = NULL;
#endif // SOLOVE_COORDINATE


int loadTexture(cv::Mat& src_img, GLuint *text)
{
	if (src_img.data == NULL)	return -1;
	glGenTextures(1, text);
	glBindTexture(GL_TEXTURE_2D, *text);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	
	/*note: gs 2016/06/12 20:03  */
	//glTexParameteri与glTexParameterf的区别
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	//load texture
#ifndef SOLOVE_COORDINATE
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
#endif // SOLOVE_COORDINATE

	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,src_img.cols,src_img.rows,0,GL_RGB,GL_UNSIGNED_BYTE,
	src_img.data);
#ifdef SOLOVE_COORDINATE
	m_pQuadratic = gluNewQuadric();
	gluQuadricTexture(m_pQuadratic, GL_TRUE);
#endif // SOLOVE_COORDINATE

	return 0;
}

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glColor3f(1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef((GLfloat)spinx,1.0,0.0,0.0);
	glRotatef((GLfloat)spiny, 0.0, 1.0, 0.0);	
	/*note: gs 2016/06/12 20:03  */
	//difference between glRotatef and glRotated
	glEnable(GL_TEXTURE_2D);
	
#ifdef SOLOVE_COORDINATE
	gluSphere(m_pQuadratic, 2, 100, 100);
#else
	//glutSolidTeapot(2.0);
	glutSolidSphere(2.0, 32, 32);
#endif // SOLOVE_COORDINATE

	//glutSolidSphere(2.0, 32, 32);	
	/*note: gs 2016/06/12 19:58  
	why teapot can use but sphere can not?
	*/
	/*note: gs 2016/06/12 19:59  
	the teapot set texture coordate inside, but sphere not,
	so when we enable:
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	sphere can also load texture,this brings a new question :	the image(texture) didn't map well.
	to solve this problem : the solution write in the define SOLOVE_COORDINATE
	use the math lib glu.(detail should check futher)

	suggest:
	1.learn the texture coordinate map
	2.read mesc3D(drive of opengl)
	*/	
	glutSwapBuffers();
	angle += 0.01;
	glPopMatrix();
	glFlush();	
	/*note: gs 2016/06/12 20:02  
	Q:why use glFlush and glutSwapBuffers at the same time?
	the difference between glSwapBuffers and glutSwapBuffers?
	*/
}

void reshape(int w,int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);	//parameter meaning?
}

void mouse(int button, int state, int x, int y)
{
	switch (button){
	case GLUT_LEFT_BUTTON:
		switch (state){
		case GLUT_DOWN:
			spinx = (spinx + 5) % 360;
			glutPostRedisplay();
			break;
		default:
			break;
		}
		break;

	case GLUT_MIDDLE_BUTTON:
		switch (state){
		case GLUT_DOWN:
			spiny = (spiny + 5) % 360;
			glutPostRedisplay();
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("useImageAsTexture");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	
	//read texture:
	img = cv::imread("1.jpg");
	loadTexture(img, &texture);

	glutMainLoop();		//opengl use what language to write
	return 0;
}