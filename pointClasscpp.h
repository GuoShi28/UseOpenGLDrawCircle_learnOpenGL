#pragma once
#include <math.h>
#include "define.h"
#define PI 3.1415926
#define PI2 6.2831853


class Point
{
public:
	Point(){};
	Point(double a, double b, double c) :x(a), y(b), z(c){};
	Point(double u, double v);
	double x;
	double y;
	double z;
};