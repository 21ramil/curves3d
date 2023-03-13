#include <memory>

#include "icurve.h"
#include "circle.h"
#include "ellipse.h"
#include "spiral.h"

#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <ctime>
#include <algorithm>
#include <numeric>

// Create vector of curves created in random manner with random parameters
void createVector(std::vector<std::shared_ptr<curve::icurve>>& vecCurves, unsigned int maxRand = 20)
{
	std::srand(std::time(nullptr));
	auto getRandValue = [](unsigned int diap)
	{
		return std::rand() % diap + 1;
	};
	
	size_t countCircle = getRandValue(maxRand);
	size_t countEllipse = getRandValue(maxRand);
	size_t countSpiral = getRandValue(maxRand);

	for (size_t i = 0; i < countCircle; ++i)
	{
		vecCurves.emplace_back(std::make_shared<curve::circle>(getRandValue(maxRand)));
	}
	for (size_t i = 0; i < countEllipse; ++i)
	{
		vecCurves.emplace_back(std::make_shared<curve::ellipse>(getRandValue(maxRand), getRandValue(maxRand)));
	}
	for (size_t i = 0; i < countSpiral; ++i)
	{
		vecCurves.emplace_back(std::make_shared<curve::spiral>(getRandValue(maxRand)));
	}
}

// Print coordinates of pointsand derivatives of all curves in the container at t = PI / 4
void printCoordinatesDerivatives(const std::vector<std::shared_ptr<curve::icurve>>& vecCurves, const double &t)
{
	std::cout << "\nx\ty\tz\t\tx'\ty'\tz'";
	for (auto i : vecCurves)
	{
		auto pnt = i->getPoint(t);
		std::cout << "\n" << pnt.x << "\t" << pnt.y << "\t" << pnt.z << "\t";
		auto dif = i->getDerivative(t, i->getFunction());
		std::cout << "\t" << dif.x << "\t" << dif.y << "\t" << dif.z;
	}
	std::cout << std::endl;
}

// Populate a second container that would contain only circles from the first container. 
void populateCircle(const std::vector<std::shared_ptr<curve::icurve>>& vecCurves, std::vector<std::shared_ptr<curve::icurve>>& vecCircles)
{
	for (auto i : vecCurves)
	{
		if (std::dynamic_pointer_cast<curve::circle>(i))
			vecCircles.emplace_back(i);
	}
}

// Sort the container in the ascending order of circles radii. That is, the first element has the 
// smallest radius, the last - the greatest.
void sortCircle(std::vector<std::shared_ptr<curve::icurve>>& vecCircle)
{
	std::sort(vecCircle.begin(), vecCircle.end(),
		[&](std::shared_ptr<curve::icurve> curve1, std::shared_ptr<curve::icurve> curve2)
		{
			auto circle1 = std::dynamic_pointer_cast<curve::circle>(curve1);
			auto circle2 = std::dynamic_pointer_cast<curve::circle>(curve2);
			if (circle1 != nullptr && circle2 != nullptr)
				return circle1->getRadius() < circle2->getRadius();
			else
			{
				throw "Error. Not possible to cast the vectors element to the circle type.";
			}
		});
}

// Compute the total sum of radii of all circle in the container
double sumCircleRadius(const std::vector<std::shared_ptr<curve::icurve>>& vecCircle)
{
	return std::accumulate(vecCircle.begin(), vecCircle.end(), 0.0,
		[&](double sum, std::shared_ptr<curve::icurve> curve)
		{
			auto circle = std::dynamic_pointer_cast<curve::circle>(curve);
			if (circle != nullptr)
				return sum + circle->getRadius();
			else
			{
				throw "Error. Not possible to cast the vectors element to the circle type.";
			}
		});
}

int main()
{
	std::vector<std::shared_ptr<curve::icurve>> vecCurves;
	createVector(vecCurves);
	printCoordinatesDerivatives(vecCurves, M_PI_4);

	std::vector<std::shared_ptr<curve::icurve>> circles;
	populateCircle(vecCurves, circles);
	sortCircle(circles);
	std::cout << "\nSort circle radii: ";
	for (auto i : circles)
	{
		auto circle = std::dynamic_pointer_cast<curve::circle>(i);
		if (circle)
			std::cout << circle->getRadius() << " ";
	}
	std::cout<<"\n\nThe total sum of radii of all curves: "<<sumCircleRadius(circles)<<std::endl;

	return 0;
}