/*************************************************
** 功能 : 第三章实验：类的构造与应用
** 作者 : 2019Jibinquan
** 创建 : 2020-10-27 / 19:00
** 版权 : 431263064@qq.com
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
	cout << "请输入要进行的操作：" << endl;
	cout << "输入'student' 以测试student类" << endl;
	cout << "输入'triangle' 以测试triangle类 " << endl;
	cout << "输入'stack' 以测试stack类 " << endl;
	cout << "输入'string' 以测试string类 " << endl;
	cout << "输入'point' 以测试point类 " << endl;
	cout << "输入'end' 以结束 " << endl;
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
			cout << "指令错误！" << endl;
		}
		cout << "请输入要进行的操作：" << endl;
		cout << "输入'student' 以测试student类" << endl;
		cout << "输入'triangle' 以测试triangle类 " << endl;
		cout << "输入'stack' 以测试stack类 " << endl;
		cout << "输入'string' 以测试string类 " << endl;
		cout << "输入'point' 以测试point类 " << endl;
		cout << "输入'end' 以结束 " << endl;
	}
	system("pause");

	return 0;
}
