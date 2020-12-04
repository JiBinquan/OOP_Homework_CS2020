/*************************************************
** 功能 : 第五章实验（类与类的关系）
** 作者 : 2019Jibinquan
** 创建 : 2020-12-1 / 19:06
** 版权 : 431263064@qq.com
/**************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << " " << a << endl
using namespace std;
typedef long long ll;
const double pi = acos(-1);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int maxn = 100007;//1e5+7 
const ll mod = 1000000007;//1e9+7

/*----------------------------------*
		 Class Definition
*-----------------------------------*/

class Base {
public:
	int a;
	void print() {
		cout << "Base: " << " a: " << a << " b: " << b << " c: " << c << endl;
	}
	static int statistic() {
		return count;
	}
	Base(int _a = 0, int _b = 0, int _c = 0) {
		a = _a;
		b = _b;
		c = _c;
		cout << " Base() 构造函数被调用 " << endl;
		count++;
	}
	~Base() {
		cout << " ~Base() 析构函数被调用 " << endl;
	}
protected:
	int b;
private:
	int c;
	static int count;
};

int Base::count = 0;

class derived1 : public Base {
public:
	void show() {
		cout << "a: " << a << " b: " << b << " c: 不可访问" << endl;
		cout << "父类：" << endl;
		Base::print();
	}
	derived1(int _a, int _b, int _c) : Base(_a, _b, _c) {
		cout << " derived1() 构造函数被调用 " << endl;
	}
	~derived1() {
		cout << " ~derived1() 析构函数被调用 " << endl;
	}
};

class derived2 : protected Base {
public:
	void show() {
		cout << "a: " << a << " b: " << b << " c: 不可访问" << endl;
		cout << "父类：" << endl;
		Base::print();
	}
	derived2(int _a, int _b, int _c) : Base(_a, _b, _c) {
		cout << " derived2() 构造函数被调用 " << endl;
	}
	~derived2() {
		cout << " ~derived2() 析构函数被调用 " << endl;
	}
};

class derived3 : private Base {
public:
	void show() {
		cout << "a: " << a << " b: " << b << " c: 不可访问" << endl;
		cout << "父类：" << endl;
		Base::print();
	}
	derived3(int _a, int _b, int _c) : Base(_a, _b, _c) {
		cout << " derive3() 构造函数被调用 " << endl;
	}
	~derived3() {
		cout << " ~derived3() 析构函数被调用 " << endl;
	}
};

class derived4 : public  derived2 {
public:
	void show() {
		cout << "a: " << a << " b: " << b << " c: 不可访问" << endl;
		cout << "父类：" << endl;
		derived2::show();
	}
	derived4(int _a, int _b, int _c) : derived2(_a, _b, _c){
		cout << " derive4() 构造函数被调用 " << endl;
	}
	~derived4() {
		cout << " ~derived4() 析构函数被调用 " << endl;
	}
};

class derived5 : public  derived3 {
public:
	void show() {
		cout << "a: 不可访问" << " b: 不可访问" << " c: 不可访问" << endl;
		cout << "父类：" << endl;
		derived3::show();
	}
	derived5(int _a, int _b, int _c) : derived3(_a, _b, _c) {
		cout << " derive5() 构造函数被调用 " << endl;
	}
	~derived5() {
		cout << " ~derived5() 析构函数被调用 " << endl;
	}
};

class Location {
protected:
	int x, y;
public:
	void trans(int _x, int _y) {
		x = _x;
		y = _y;
	}
	void move(int dx, int dy) {
		x += dx;
		y += dy;
	}
	void show() {
		cout << " x: " << x << " y: " << y << endl;
	}
	Location(int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
	}
	~Location() {};
};

class Point : public Location {
protected:
	int z;
public:
	void trans(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	void move(int dx, int dy, int dz) {
		x += dx;
		y += dy;
		z += dz;
	}
	void show() {
		cout << " x: " << x << " y: " << y << " z: " << z << endl;
	}
	Point(int _x = 0, int _y = 0, int _z = 0) : Location(_x, _y) {
		z = _z;
	}
	~Point() {};
};

class Sphere : public Point {
protected:
	double r;
public:
	void move(int dx, int dy, int dz) {
		x += dx;
		y += dy;
		z += dz;
	}
	void show() {
		cout << " x: " << x << " y: " << y << " z: " << z << " r: " << r << " volume: " << (4.0 / 3 * pi * r * r) << endl;
	}
	Sphere(int _x = 0, int _y = 0, int _z = 0, double _r = 0.0) : Point(_x, _y, _z) {
		x = _x;
		y = _y;
		z = _z;
		r = _r;
	}
	~Sphere() {};
};

/*----------------------------------*
		  Main Function
*-----------------------------------*/

void Task1()
{
	cout << "Base: fa 基类 ：" << endl << endl;
	Base fa(1, 2, 3);
	cout << " sizeof(fa) " << sizeof(fa) << endl << endl;
	cout << endl << "derived1 son1 公有继承 ：" << endl << endl;
	derived1 son1(4, 5, 6);
	cout << " sizeof(son1) " << sizeof(son1) << endl;
	son1.show();
	cout << endl << endl << "derived2 son2 保护继承 ：" << endl << endl;
	derived2 son2(7, 8, 9);
	cout << " sizeof(son2) " << sizeof(son2) << endl;
	son2.show();
	cout << endl << endl << "derived3 son3 私有继承 ：" << endl << endl;
	derived3 son3(10, 11, 12);
	cout << " sizeof(son3) " << sizeof(son3) << endl;
	son3.show();
	cout << endl << endl << "derived4 grandson1 公有继承 derived2 ：" << endl << endl;
	derived4 grandson1(13, 14, 15);
	grandson1.show();
	cout << endl << endl << "derived5 grandson2 公有继承 derived3 ：" << endl << endl;
	derived5 grandson2(16, 17, 18);
	grandson2.show();
	cout << endl << endl << "结束" << endl << endl;
}

void Task2()
{
	cout << "Location loa ：" << endl;
	Location loa(1, 2);
	loa.show();
	cout << "move(1, -1): " << endl;
	loa.move(1, -1);
	loa.show();
	cout << endl;

	Point p;
	cout << "Point p : " << endl;
	p.show();
	cout << "move(0, 1, -1): " << endl;
	p.move(0, 1, -1);
	p.show();
	cout << endl;
	cout << "Sphere s : " << endl;
	Sphere s(6, 7, 8, 9.0);

	s.show();
	cout << "move(3, 5, -5): " << endl;
	s.move(3, 5, -5);
	s.show();
}

int main()
{
	cout << "任务一：" << endl << endl;
	Task1();
	cout << endl << endl;
	cout << "任务二：" << endl << endl;
	Task2();
	cout << endl << endl;
	system("pause");
	return 0;
}
