/*************************************************
** ���� : ������ʵ�飺��Ĺ�����Ӧ��
** ���� : 2019Jibinquan
** ���� : 2020-10-27 / 19:00
** ��Ȩ : 431263064@qq.com
/**************************************************/

#include "int_stack.h"
#include "mystring.h"
#include "m_head.h"
#include "student.h"
#include "triangle.h"
#include "Point.h"

/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{
	string op;
	cout << "������Ҫ���еĲ�����" << endl;
	cout << "����'student' �Բ���student��" << endl;
	cout << "����'triangle' �Բ���triangle�� " << endl;
	cout << "����'stack' �Բ���stack�� " << endl;
	cout << "����'string' �Բ���string�� " << endl;
	cout << "����'point' �Բ���point�� " << endl;
	cout << "����'end' �Խ��� " << endl;
	while (cin >> op) {
		if (op == "end") {
			break;
		}
		else if (op == "student") {
			Student_test();
		}
		else if (op == "triangle") {
			Trangle_test();
		}
		else if (op == "stack") {
			Stack_test();
		}
		else if (op == "string") {
			String_test();
		}
		else if (op == "point") {
			Point_test();
		}
		else {
			cout << "ָ�����" << endl;
		}
		cout << "������Ҫ���еĲ�����" << endl;
		cout << "����'student' �Բ���student��" << endl;
		cout << "����'triangle' �Բ���triangle�� " << endl;
		cout << "����'stack' �Բ���stack�� " << endl;
		cout << "����'string' �Բ���string�� " << endl;
		cout << "����'point' �Բ���point�� " << endl;
		cout << "����'end' �Խ��� " << endl;
	}
	system("pause");

	return 0;
}
