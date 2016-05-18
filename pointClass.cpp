#include "pointClasscpp.h"

Point::Point(double u, double v)
{
	x = sin(PI * v) * cos(PI2 * u);
	y = sin(PI * v) * sin(PI2 * u);
	z = cos(PI * v);
}