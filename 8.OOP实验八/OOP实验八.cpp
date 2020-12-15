/*************************************************
** 功能 : 第六章实验（类的多态性）  
** 作者 : 2019Jibinquan
** 创建 : 2020-12-8 / 19:09
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
	
class Array {
private:
	int size;
	int* ps;
public:
	Array() {
		size = 0;
		ps = NULL;
	}
	Array(int s,int a[]) {
		size = s;
		ps = new int[size+1];//必须多申请一个空间，不然谜之内存泄漏
		for (int i = 0; i <= s; i++) {
			ps[i] = a[i];
		}
	}
	Array(const Array &arr){//两个下午一场空，不写深拷见祖宗
		size = arr.size;
		ps = new int[size + 1];
		for (int i = 0; i <= size; i++) {
			ps[i] = arr.ps[i];
		}
	}
	~Array()
	{
		delete[]ps;
	}
	int length() {
		return size;
	}
	void print() const{
		for (int i = 0; i < size; i++) {
			cout << ps[i] << " \n"[i == size-1];
		}
	}
	int& operator[](const int pos) {
		return ps[pos];
	}
	Array& operator = (const Array &arr) {
		if (&arr == this) {
			return *this;
		}
		if (ps != NULL) {
			delete []ps;
		}
		size = arr.size;
		if (size > 0) {
			this->ps = new int[size+1];
		}		
		for (int i = 0; i < size; i++) {
			this->ps[i] = arr.ps[i];
		}
		return (*this);
	}
	Array operator + (const Array& arr) {
		Array tmp;
		tmp.size = size + arr.size;
		if (tmp.size > 0) {
			tmp.ps = new int[tmp.size+1];
		}
		int tp = 0;
		for (int i = 0; i < size;i++) {
			tmp.ps[tp++] = ps[i];
		}
		for (int i = 0; i < arr.size; i++) {
			tmp.ps[tp++] = arr.ps[i];
		}
		return tmp;
	}
	friend Array operator - (Array&, Array&);
};

Array operator - (Array& ar1, Array& ar2) {
	Array tmp;
	tmp.ps = new int[ar1.size+1];
	int tp = 0;
	set<int>se;
	queue<int>que;
	for (int i = 0; i < ar1.size; i++) {
		que.push(ar1.ps[i]);
	}
	for (int i = 0; i < ar2.size; i++) {
		se.insert(ar2.ps[i]);
	}
	while (!que.empty()) {
		int nw = que.front();
		que.pop();
		if (!se.count(nw)) {
			tmp.ps[tp++] = nw;
		}
	}
	tmp.size = tp;
	while (tp < ar1.size) {
		tmp.ps[tp++] = 0;//剩下的用0填满，不然还是内存谜之泄露
	}
	return tmp;
}

class Shapes {
	public:
		virtual void dispaly() = 0;
};

class Rectangle : public Shapes
{
public:
	void dispaly() {
		cout << "这是一个矩形" << endl;
	}
};

class Cricle : public Shapes
{
public:
	void dispaly() {
		cout << "这是一个圆形" << endl;
	}
};

void task2()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 3,4,5,6,7 };
	int c[] = { 8,9,10,11,12 };
	Array ar1(5, a), ar2(5, b), ar3(5, a);
	cout << endl << "重载 [] ： " << endl;
	for (int i = 0; i < ar3.length(); i++) {
		cout << ar3[i] << " \n"[i == ar3.length() - 1];
	}
	cout << endl << "重载 + ： " << endl;
	ar3 = ar1 + ar2;
	ar3.print();
	cout << endl << "重载 - ： " << endl;
	ar3 = ar1 - ar2;
	ar3.print();
	return;
}

void task3() 
{
	Shapes* p[2+1];
	Rectangle rec;
	Cricle cri;
	p[1] = &rec;
	p[2] = &cri;
	p[1]->dispaly();
	p[2]->dispaly();
	cout << endl;
	return;
}

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	cout << "任务二：" << endl;
	task2();
	cout << endl << "任务三：" << endl;
	task3();
	system("pause");
	
	return 0;
}
