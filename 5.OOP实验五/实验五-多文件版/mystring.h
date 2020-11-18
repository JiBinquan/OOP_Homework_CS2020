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
		cout << "�������ַ���:" << endl;
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
			cout << "�޷���ȫ�ϲ�" << endl;
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
			cout << "�Ƿ����ʣ�" << endl;
		}
		else {
			st[pos] = ch;
		}
	}

	void del(int pos) {
		if (pos < 0 || pos >= len) {
			cout << "�Ƿ����ʣ�" << endl;
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
	cout << "������Ҫ���еĲ�����" << endl;
	cout << "����'create'�Գ�ʼ��һ���ַ���" << endl;
	Mystring str;
	while (cin >> op) {
		if (op == "create") {
			str.setstr();
			break;
		}
		else {
			cout << "ָ�����" << endl;
		}
	}
	cout << "������Ҫ���еĲ�����" << endl;
	cout << "����'union' �����ӵ�����һ���ַ��� " << endl;
	cout << "����'size' �Ի�ȡ��ǰ�ַ������� " << endl;
	cout << "����'compare' �԰��ֵ���Ƚ������ַ��� " << endl;
	cout << "����'append c' ���ڵ�ǰ��������ַ� c" << endl;
	cout << "����'modify x c' �Խ�ԭ��xλ���ַ��޸�Ϊc" << endl;
	cout << "����'delete x' ��ɾ��x�ϵ��ַ� " << endl;
	cout << "����'reverse' �Է�ת�ַ��� " << endl;
	cout << "����'find' �Խ���ģʽƥ�� " << endl;
	cout << "����'end' �Խ��� " << endl;
	while (cin >> op) {
		if (op == "end") {
			break;
		}
		else if (op == "size") {
			cout << "��ǰ�ַ�����С��" << str.leng() << endl;
		}
		else if (op == "union") {
			Mystring st2;
			st2.setstr();
			str.uion(st2);
			cout << "��ǰ�ַ���" << endl;
			str.printstr();
		}
		else if (op == "compare") {
			Mystring st2;
			st2.setstr();
			int pd = str.compare(st2);
			if (pd < 0) {
				cout << "ԭ��С�ڵ�ǰ��" << endl;
			}
			else if (pd > 0) {
				cout << "ԭ��С�ڵ�ǰ��" << endl;
			}
			else {
				cout << "������ͬ" << endl;
			}
		}
		else if (op == "append") {
			char ch;
			cin >> ch;
			str.append(ch);
			cout << "��ǰ�ַ���" << endl;
			str.printstr();
		}
		else if (op == "modify") {
			int x; char ch;
			cin >> x >> ch;
			str.modify(x, ch);
			cout << "��ǰ�ַ���" << endl;
			str.printstr();
		}
		else if (op == "delete") {
			int x;
			cin >> x ;
			str.del(x);
			cout << "��ǰ�ַ���" << endl;
			str.printstr();
		}
		else if (op == "reverse") {
			str.reverse();
			cout << "��ǰ�ַ���" << endl;
			str.printstr();
		}
		else if (op == "find") {
			Mystring st2;
			cout << "���ô�ƥ�䴮" << endl;
			st2.setstr();
			if (str.bf_find(st2)) {
				cout << "�ô�Ϊԭ���Ӵ�" << endl;
			}
			else {
				cout << "�ô���ԭ���Ӵ�" << endl;
			}
		}
		else {
			cout << "ָ�����" << endl;
		}
		cout << "������Ҫ���еĲ�����" << endl;
	}

}

#endif
