#include "ellipse.h"
#include "math.h"

namespace curve
{
	ellipse::ellipse(const double radius1, const double radius2): a(radius1), b(radius2)
	{
		if (a < 0 || b < 0)
			throw "Radius must be positive";

		func = [&](const double &t) 
		{
			curve::point pnt(a * cos(t), 
							 b * sin(t), 
							 0);
			return pnt; 
		};
	}

	curve::point ellipse::getPoint(const double &t)
	{
		return func(t);
	}

	std::function<point(const double &)> ellipse::getFunction()
	{
		return func;
	}
}
