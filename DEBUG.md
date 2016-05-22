2016/05/21 :
Bug:Using OpenGL glutDisplayFunc within class
Solve:
reference:http://stackoverflow.com/questions/3589422/using-opengl-glutdisplayfunc-within-class
reason:class in c++ pass a this pointer, but opengl api don't,
solution:
create a global class pointer to store this pointer, 

drawSphereUsePoints* currentInstance;

then write a global shell function

void drawSphereUsePoints::setupDrawBack()
{
	currentInstance = this;
	::glutDisplayFunc(displayCallBack);
}

then call display function of currentInstance

void displayCallBack()
{
	currentInstance->displayFunc();
}
