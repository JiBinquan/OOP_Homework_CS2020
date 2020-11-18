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
	cout << "������Ҫ���еĲ�����" << endl;
	cout << "����'create a b c '�Գ�ʼ��һ�������� " << endl;
	int a, b, c;
	while (cin >> op) {
		if (op == "create") {
			cin >> a >> b >> c;
			break;
		}
		else {
			cout << "ָ�����" << endl;
		}
	}
	Triangle tri(a, b, c);
	bool pd = tri.check();
	cout << "������Ҫ���еĲ�����" << endl;
	cout << "����'check' ���ж��Ƿ񹹳�������" << endl;
	cout << "����'girth' �Լ����ܳ� " << endl;
	cout << "����'Area' �Լ������ " << endl;
	cout << "����'judge' �ж����������� " << endl;
	cout << "����'end' �Խ��� " << endl;
	while (cin >> op) {
		if (op == "end") {
			break;
		}
		else if (op == "check") {
			if (pd) {
				cout << "���Թ���������" << endl;
			}
			else {
				cout << "�����Թ���������" << endl;
			}
		}
		else if (op == "girth") {
			if (pd) {
				cout << tri.girth() << endl;
			}
			else {
				cout << "�����β��Ϸ���" << endl;
			}
		}
		else if (op == "Area") {
			if (pd) {
				cout << tri.Area() << endl;
			}
			else {
				cout << "�����β��Ϸ���" << endl;
			}
		}
		else if (op == "judge") {
			if (pd) {
				if (tri.judge() > 0) {
					cout << "��������Ϊ�۽�������" << endl;
				}
				else if (tri.judge() < 0) {
					cout << "��������Ϊ���������" << endl;
				}
				else {
					cout << "��������Ϊֱ��������" << endl;
				}
			}
			else {
				cout << "�����β��Ϸ���" << endl;
			}
		}
		else {
			cout << "ָ�����" << endl;
		}
		cout << "������Ҫ���еĲ�����" << endl;
	}
}

#endif
