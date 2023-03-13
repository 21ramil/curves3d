#include "spiral.h"
#include "math.h"

namespace curve
{
	spiral::spiral(const double& radius) : r(radius)
	{
		if (r < 0)
			throw "Radius must be positive";

		func = [&](const double &t)
		{
			curve::point pnt(r * t * cos(t), 
							 r * t * sin(t), 
							 t);
			return pnt;
		};
	}
	curve::point spiral::getPoint(const double &t)
	{
		return func(t);
	}

	std::function<point(const double &)> spiral::getFunction()
	{
		return func;
	}
}