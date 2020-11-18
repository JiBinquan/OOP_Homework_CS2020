#include "int_stack.h"
#include "m_head.h"


int_stack::int_stack() {
	topz = 0;
	memset(data, 0, sizeof(data));
}

bool int_stack::empty() {
	if (topz) {
		return false;
	}
	else {
		return true;
	}
}

int int_stack::size() {
	return topz;
}

int int_stack::top() {
	if (size() != 0) {
		return data[topz];
	}
	else {
		return inf;
	}
}

void int_stack::pop() {
	if (!empty()) {
		data[topz] = 0;
		topz--;
	}
}

void int_stack::push(int a) {
	data[++topz] = a;
}

void int_stack::create(int n) {
	topz = 0;
	for (int i = 1, tp; i <= n; i++) {
		cin >> tp;
		push(tp);
	}
}

void Stack_test()
{
	
	string op;
	int tp;
	cout << "请输入要进行的操作：" << endl;
	cout << "输入'create n'以初始化一个大小为n的栈 " << endl;
	int_stack sta;
	
	while (cin >> op) {
		if (op == "create") {
			cin >> tp;
			if (tp) {
				cout << "请输入元素：" << endl;
				sta.create(tp);
			}
			break;
		}
		else {
			cout << "指令错误！" << endl;
		}
	}
	cout << "请输入要进行的操作：" << endl;
	cout << "输入'size' 以求栈大小 " << endl;
	cout << "输入'push n' 以推入一个元素n " << endl;
	cout << "输入'top' 以获取当前栈顶元素 " << endl;
	cout << "输入'empty' 判断栈是否为空 " << endl;
	cout << "输入'pop' 以弹出当前栈顶元素 " << endl;
	cout << "输入'end' 以结束 " << endl;
	while (cin >> op) {
		if (op == "end") {
			break;
		}
		else if (op == "size") {
			cout << "当前栈大小：" << sta.size() << endl;
		}
		else if (op == "push") {
			cin >> tp;
			sta.push(tp);
		}
		else if (op == "top") {
			cout << "当前栈顶元素：" << sta.top() << endl;
		}
		else if (op == "pop") {
			if (sta.empty()) {
				cout << "当前栈为空 " << endl;
			}
			else {
				cout << "弹出元素：" << sta.top() << endl;
				sta.pop();
			}
		}
		else if (op == "empty") {
			if (sta.empty()) {
				cout << "当前栈为空 " << endl;
			}
			else {
				cout << "当前栈非空 " << endl;
			}
		}
		else {
			cout << "指令错误！" << endl;
		}
		cout << "请输入要进行的操作：" << endl;
	}
}

