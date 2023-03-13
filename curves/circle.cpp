#include "circle.h"
#include "math.h"

namespace curve
{
	circle::circle(const double &radius): r(radius) 
	{
		if (r < 0)
			throw "Radius must be positive";

		func = [&](const double &t) 
		{
			curve::point pnt(r * cos(t), 
							 r * sin(t), 
							 0);
			return pnt; 
		};
	}

	curve::point circle::getPoint(const double &t)
	{
		return func(t);
	}

	double circle::getRadius() const
	{
		return r;
	}

	std::function<point(const double &)> circle::getFunction()
	{
		return func;
	}
}