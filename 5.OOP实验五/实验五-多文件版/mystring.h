#ifndef __MY_STRING_H
#define __MY_STRING_H

#include "m_head.h"

class Mystring {
private:
	int len;
	char st[maxn];
public:
	Mystring() {
		len = 0;
		memset(st, '\0', sizeof(st));
	}

	void setstr() {
		cout << "请输入字符串:" << endl;
		cin >> st;
		for (int i = 1; i <= maxn; i++) {
			if (st[i] == '\0' || st[i] == '\n') {
				len = i;
				break;
			}
		}
	}

	int leng() {
		return len;
	}

	void uion(Mystring s2) {
		int pos = len;
		if (leng() + s2.len >= maxn) {
			cout << "无法完全合并" << endl;
			for (int i = 0; i + pos <= maxn; i++) {
				st[i + pos] = s2.st[i];
			}
			len = maxn;
		}
		else {
			for (int i = 0; i < s2.leng(); i++) {
				st[i + pos] = s2.st[i];
			}
			this->len = len + s2.len;
		}

	}

	void printstr() {
		cout << st << endl;
	}

	void reverse() {
		for (int i = 0; i < (len / 2); i++) {
			swap(st[i], st[len - i - 1]);
		}
	}

	int compare(Mystring s2) {
		int n = min(len, s2.len);
		for (int i = 0; i < n; i++) {
			if (st[i] < s2.st[i]) {
				return -1;
			}
			else if (st[i] > s2.st[i]) {
				return 1;
			}
		}
		if (len == s2.len) {
			return 0;
		}
		else if (len > s2.len) {
			return 1;
		}
		else {
			return -1;
		}
	}

	void append(char ch) {
		st[len++] = ch;
	}

	void modify(int pos, char ch) {
		if (pos < 0 || pos >= len) {
			cout << "非法访问！" << endl;
		}
		else {
			st[pos] = ch;
		}
	}

	void del(int pos) {
		if (pos < 0 || pos >= len) {
			cout << "非法访问！" << endl;
		}
		for (int i = pos; i <= len - 1; i++) {
			st[i] = st[i + 1];
		}
		st[len] = '\0';
		len--;
	}

	bool bf_find(Mystring s2) {
		int res = -1;
		bool flag = 1;
		for (int i = 0; i < len; i++) {
			flag = 1;
			for (int j = 0; j < s2.len; j++) {
				if (st[i + j] != s2.st[j]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			return true;
		}
		else {
			return false;
		}
	}
};

void String_test()
{
	string op;
	int tp;
	cout << "请输入要进行的操作：" << endl;
	cout << "输入'create'以初始化一个字符串" << endl;
	Mystring str;
	while (cin >> op) {
		if (op == "create") {
			str.setstr();
			break;
		}
		else {
			cout << "指令错误！" << endl;
		}
	}
	cout << "请输入要进行的操作：" << endl;
	cout << "输入'union' 以连接到另外一个字符串 " << endl;
	cout << "输入'size' 以获取当前字符串长度 " << endl;
	cout << "输入'compare' 以按字典序比较两个字符串 " << endl;
	cout << "输入'append c' 以在当前串后添加字符 c" << endl;
	cout << "输入'modify x c' 以将原串x位置字符修改为c" << endl;
	cout << "输入'delete x' 以删除x上的字符 " << endl;
	cout << "输入'reverse' 以反转字符串 " << endl;
	cout << "输入'find' 以进行模式匹配 " << endl;
	cout << "输入'end' 以结束 " << endl;
	while (cin >> op) {
		if (op == "end") {
			break;
		}
		else if (op == "size") {
			cout << "当前字符串大小：" << str.leng() << endl;
		}
		else if (op == "union") {
			Mystring st2;
			st2.setstr();
			str.uion(st2);
			cout << "当前字符串" << endl;
			str.printstr();
		}
		else if (op == "compare") {
			Mystring st2;
			st2.setstr();
			int pd = str.compare(st2);
			if (pd < 0) {
				cout << "原串小于当前串" << endl;
			}
			else if (pd > 0) {
				cout << "原串小于当前串" << endl;
			}
			else {
				cout << "两串相同" << endl;
			}
		}
		else if (op == "append") {
			char ch;
			cin >> ch;
			str.append(ch);
			cout << "当前字符串" << endl;
			str.printstr();
		}
		else if (op == "modify") {
			int x; char ch;
			cin >> x >> ch;
			str.modify(x, ch);
			cout << "当前字符串" << endl;
			str.printstr();
		}
		else if (op == "delete") {
			int x;
			cin >> x ;
			str.del(x);
			cout << "当前字符串" << endl;
			str.printstr();
		}
		else if (op == "reverse") {
			str.reverse();
			cout << "当前字符串" << endl;
			str.printstr();
		}
		else if (op == "find") {
			Mystring st2;
			cout << "设置待匹配串" << endl;
			st2.setstr();
			if (str.bf_find(st2)) {
				cout << "该串为原串子串" << endl;
			}
			else {
				cout << "该串非原串子串" << endl;
			}
		}
		else {
			cout << "指令错误！" << endl;
		}
		cout << "请输入要进行的操作：" << endl;
	}

}

#endif
