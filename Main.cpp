/*
		The idea here is simply to print out small bits of info like the
	'y' and 'x' intercepts of a given point. Print the slope and the full
	equation that represents the 2 points entered.
	
		There will be no error catching here because I don't really plan
	on using this anywhere else but for me. In the future, this code may
	come in handy.
*/

#include <iostream>

#define PRINT std::cout
#define GET std::cin

struct Point2D
{
	long double x;
	long double y;
};

inline long double getSlope(Point2D& p1, Point2D& p2);
inline long double getYIntercept(long double& slope, Point2D& p);
inline long double getXIntercept(long double& slope, long double& yInt, Point2D& p);

int main()
{
	Point2D p1;
	Point2D p2;

	long double slope;
	long double yInt;

	PRINT << "Enter the first point cordinates starting with x1 (no fractions please, I break when I handle them).\n";
	{
		PRINT << "x1:\t";
		GET >> p1.x;

		PRINT << "y1:\t";
		GET >> p1.y;

		PRINT << "x2:\t";
		GET >> p2.x;

		PRINT << "y2:\t";
		GET >> p2.y;
	}

	slope = getSlope(p1, p2);
	yInt = getYIntercept(slope, p1);

	PRINT << "Slope:\t" << slope << "\n";
	PRINT << "xInt:\t" << getXIntercept(slope, yInt, p1) << "\n";
	PRINT << "yInt:\t" << yInt << "\n";
	PRINT << "\nFull Eqaution:\ty=" << slope << "x+" << yInt << "\n";
}

inline long double getSlope(Point2D& p1, Point2D& p2)
{
	// If I had a perfect multithreading system, I could have each subtraction problem
	// solved on their own thread.
	return (p2.y - p1.y) / (p2.x - p1.x);
}

inline long double getYIntercept(long double& slope, Point2D& p)
{
	return p.y - slope * p.x;
}

inline long double getXIntercept(long double& slope, long double& yInt, Point2D& p)
{
	return (-1.0 * yInt) / slope;
}
