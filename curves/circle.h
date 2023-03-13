#pragma once
#include "icurve.h"

namespace curve
{
	class circle : public icurve
	{
	public:
		circle(const double &radius);
		~circle() {}

		curve::point getPoint(const double &t) override;
		std::function<point(const double &)> getFunction() override;
		double getRadius() const;

	private:
		std::function<point(const double &)> func;
		double r;
	};
}//namespace curve

