#ifndef __TRIANGLR_H
#define __TRIANGLR_H
#include "m_head.h"

class Triangle {
private:
	int ed1, ed2, ed3;
public:
	Triangle(int a, int b, int c) {
		if (a > b) {
			swap(a, b);
		}
		if (b > c) {
			swap(b, c);
		}
		if (a > b) {
			swap(a, b);
		}
		ed1 = a;
		ed2 = b;
		ed3 = c;
	}

	bool check() {
		if (ed1 + ed2 <= ed3) {
			return false;
		}
		else {
			return true;
		}
	}

	int girth() {
		return ed1 + ed2 + ed3;
	}

	double Area() {
		double p = (ed1 + ed2 + ed3) * 1.0 / 2;
		double ar = sqrt(p * (p - ed1) * (p - ed2) * (p - ed3));
		return ar;
	}

	int judge() {
		if (ed3 * ed3 > (ed2 * ed2 + ed1 * ed1)) {
			return 1;
		}
		else if (ed3 * ed3 < (ed2 * ed2 + ed1 * ed1)) {
			return -1;
		}
		else {
			return 0;
		}
	}

};


void Trangle_test()
{
	string op;
	int tp;
	cout << "请输入要进行的操作：" << endl;
	cout << "输入'create a b c '以初始化一个三角形 " << endl;
	int a, b, c;
	while (cin >> op) {
		if (op == "create") {
			cin >> a >> b >> c;
			break;
		}
		else {
			cout << "指令错误！" << endl;
		}
	}
	Triangle tri(a, b, c);
	bool pd = tri.check();
	cout << "请输入要进行的操作：" << endl;
	cout << "输入'check' 以判断是否构成三角形" << endl;
	cout << "输入'girth' 以计算周长 " << endl;
	cout << "输入'Area' 以计算面积 " << endl;
	cout << "输入'judge' 判断三角形类型 " << endl;
	cout << "输入'end' 以结束 " << endl;
	while (cin >> op) {
		if (op == "end") {
			break;
		}
		else if (op == "check") {
			if (pd) {
				cout << "可以构成三角形" << endl;
			}
			else {
				cout << "不可以构成三角形" << endl;
			}
		}
		else if (op == "girth") {
			if (pd) {
				cout << tri.girth() << endl;
			}
			else {
				cout << "三角形不合法！" << endl;
			}
		}
		else if (op == "Area") {
			if (pd) {
				cout << tri.Area() << endl;
			}
			else {
				cout << "三角形不合法！" << endl;
			}
		}
		else if (op == "judge") {
			if (pd) {
				if (tri.judge() > 0) {
					cout << "该三角形为钝角三角形" << endl;
				}
				else if (tri.judge() < 0) {
					cout << "该三角形为锐角三角形" << endl;
				}
				else {
					cout << "该三角形为直角三角形" << endl;
				}
			}
			else {
				cout << "三角形不合法！" << endl;
			}
		}
		else {
			cout << "指令错误！" << endl;
		}
		cout << "请输入要进行的操作：" << endl;
	}
}

#endif
