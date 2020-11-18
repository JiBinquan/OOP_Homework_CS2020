#include "Point.h"
#include "Line.h"

Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Point::setPoint(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Point::printCoordinate()
{
	cout << " 横坐标： " << x << " 纵坐标： " << y << endl;
}

double distance(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Point_test()
{
	string op;
	int tp;
	cout << "请输入要进行的操作：" << endl;
	cout << "输入'create x y '以初始化一个点 " << endl;
	int x,y;
	while (cin >> op) {
		if (op == "create") {
			cin >> x >> y;
			break;
		}
		else {
			cout << "指令错误！" << endl;
		}
	}
	Point poi(x, y);
	cout << "请输入要进行的操作：" << endl;
	cout << "输入'set x y ' 以修改点的坐标为 (x,y) " << endl;
	cout << "输入'print' 以输出当前点的坐标 " << endl;
	cout << "输入'distance' 以计算于另一个点的距离 " << endl;
	cout << "输入'line' 以与另外一点生成一条线段，并计算长度 " << endl;
	cout << "输入'end' 以结束 " << endl;
	while (cin >> op) {
		if (op == "end") {
			break;
		}
		else if (op == "set") {
			cin >> x >> y;
			poi.setPoint(x, y);
		}
		else if (op == "print") {
			poi.printCoordinate();
		}
		else if (op == "distance") {
			cout << "请输入另外一点坐标 x y ：" << endl;
			cin >> x >> y;
			Point p2(x, y);
			cout << "两点之间距离为： " << distance(poi, p2) << endl;
		}
		else if (op == "line") {
			cout << "请输入另外一点坐标 x y ：" << endl;
			cin >> x >> y;
			Point p2(x, y);
			Line lin(poi, p2);
			cout << "线段长度为： " << lin.length() << endl;
		}
		else {
			cout << "指令错误！" << endl;
		}
		cout << "请输入要进行的操作：" << endl;
	}
}
