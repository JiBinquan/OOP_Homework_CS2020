#pragma once
#include "m_head.h"
class Point
{
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0);
	void setPoint(int _x, int _y);
	void printCoordinate();
	friend double distance(Point a,Point b);
	friend class Line;
};


void Point_test();
