#pragma once
#include "m_head.h"
#include "Point.h"

class Line
{
private:
	Point a;
	Point b;
public:
	Line(Point _a, Point _b) {
		a = _a;
		b = _b;
	}
	double length() {
		return hypot(a.x - b.x, a.y - b.y);
	}
};

