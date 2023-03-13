#pragma once
#include "icurve.h"

namespace curve
{
	class ellipse : public icurve
	{
	public:
		ellipse(const double radius1, const double radius2);
		~ellipse() {}

		curve::point getPoint(const double &t) override;
		std::function<point(const double &)> getFunction() override;

	private:
		std::function<point(const double &)> func;
		double a, b;
	};
}//namespace curve

