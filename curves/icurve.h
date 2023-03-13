#pragma once
#include <functional>
#include <memory>

namespace curve
{
	struct point
	{
		point(double px=0, double py=0, double pz=0) : x(px), y(py), z(pz) {}
		double x, y, z;
	};

	class icurve
	{
	public:
		icurve() {}
		virtual ~icurve() {}

		virtual std::function<point(const double &)> getFunction() = 0;
		virtual point getPoint(const double &t) = 0;
		virtual point getDerivative(const double &t, std::function<point(const double &)> func, const double &eps = 0.00001)
		{
			auto eps2 = 2 * eps;
			auto t_add = func(t + eps);
			auto t_sub = func(t - eps);
			
			double x_t = (t_add.x - t_sub.x) / eps2;
			double y_t = (t_add.y - t_sub.y) / eps2;
			double z_t = (t_add.z - t_sub.z) / eps2;
			return point(x_t, y_t, z_t);
		}
	};
}//namespace curve
