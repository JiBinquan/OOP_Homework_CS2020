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
	cout << " �����꣺ " << x << " �����꣺ " << y << endl;
}

double distance(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Point_test()
{
	string op;
	int tp;
	cout << "������Ҫ���еĲ�����" << endl;
	cout << "����'create x y '�Գ�ʼ��һ���� " << endl;
	int x,y;
	while (cin >> op) {
		if (op == "create") {
			cin >> x >> y;
			break;
		}
		else {
			cout << "ָ�����" << endl;
		}
	}
	Point poi(x, y);
	cout << "������Ҫ���еĲ�����" << endl;
	cout << "����'set x y ' ���޸ĵ������Ϊ (x,y) " << endl;
	cout << "����'print' �������ǰ������� " << endl;
	cout << "����'distance' �Լ�������һ����ľ��� " << endl;
	cout << "����'line' ��������һ������һ���߶Σ������㳤�� " << endl;
	cout << "����'end' �Խ��� " << endl;
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
			cout << "����������һ������ x y ��" << endl;
			cin >> x >> y;
			Point p2(x, y);
			cout << "����֮�����Ϊ�� " << distance(poi, p2) << endl;
		}
		else if (op == "line") {
			cout << "����������һ������ x y ��" << endl;
			cin >> x >> y;
			Point p2(x, y);
			Line lin(poi, p2);
			cout << "�߶γ���Ϊ�� " << lin.length() << endl;
		}
		else {
			cout << "ָ�����" << endl;
		}
		cout << "������Ҫ���еĲ�����" << endl;
	}
}
