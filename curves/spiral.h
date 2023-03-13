#pragma once
#include "icurve.h"

namespace curve
{
	class spiral : public icurve
	{
	public:
		spiral(const double& radius);
		~spiral() {}

		curve::point getPoint(const double &t) override;
		std::function<point(const double &)> getFunction() override;

	private:
		std::function<point(const double &)> func;
		double r;
	};
}//namespace curve

