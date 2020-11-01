/*************************************************
** 功能 : OOP课程上机实验课：第4次实验
** 作者 : 2019Jibinquan
** 创建 : 2020-10-20 / 19:01
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
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const int maxn = 100007;//1e5+7 
const ll mod = 1000000007;//1e9+7

/*----------------------------------*
         Class Definition
*-----------------------------------*/

typedef struct LNode {
	int data;
	LNode* next;
	LNode* pre;
}LNode, * Linklist;

Linklist initList() //初始化链表 
{
	Linklist L = new LNode;
	L->data = 0;
	L->next = NULL;
	L->pre = NULL;
	return L;
}


void insert_back(Linklist& L, int e) //尾插法插入元素 
{
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	LNode* s = new LNode;
	s->data = e;
	s->next = NULL;
	s->pre = p;
	p->next = s;
	L->data++;
}

void distorylist(Linklist& L)//销毁链表
{
	LNode* p = L;
	while (p->next != NULL) {
		LNode* s = p;
		p = p->next;
		delete s;
	}
	delete p;
}

void Fbi()//斐波那契查询
{
	int n;
	Linklist L = initList();
	insert_back(L, 1);
	insert_back(L, 1);
	cout << "请输入要查询的位数，输入0结束：" << endl;
	while (cin >> n && n) {
		LNode* p = L;
		if (n <= L->data) {
			for (int i = 1; i <= n; i++) {
				p = p->next;
			}
			cout << p->data << endl;
		}
		else {
			while (p->next != NULL) {
				p = p->next;
			}
			while (L->data < n) {
				int a = p->data;
				int b = p->pre->data;
				//cout << a << ' ' << b << endl;
				LNode* s = new LNode;
				s->data = a + b;
				s->pre = p;
				s->next = NULL;
				p->next = s;
				p = p->next;
				L->data++;
			}
			cout << p->data << endl;
		}
		//cout << L->data << endl;
		cout << "请输入要查询的位数，输入0结束：" << endl;
	}
	distorylist(L);
}

class Fun{
	private:
		double a,b;
	public:
		double f(double x)
		{
			//cout<<" ** "<<a<<" "<<b<<" "<<x<<" "<<a * x + b<<endl;
			return (a * x + b);
		}
		void slove()
		{
			double l = -100000.000,r = 100000.00;
			cout<<"请输入方程ax + b = 0的参数a、b"<<endl;
			cin>>a>>b;
			if(f(l) == 0){
				cout<<"方程的解为："<<l<<endl; 
			}
			else if(f(r) == 0){
				cout<<"方程的解为："<<r<<endl; 
			}
			else if(f(l) * f(r) > 0){
				cout<<"方程在+-100000.00内没有实数解"<<endl;
			}
			else{
				bool flag = 0;
				while(r - l > eps){
					double mid = (l + r) / 2.0;
					double fm = f(mid);
					double fl = f(l);
					double fr = f(r);
					//cout<<" mid "<<mid<<" f(mid) "<<fm<<endl<<" l "<<l<<" f(l) "<<fl<<endl<<" r "<<r<<" f(r) "<<fr<<endl<<endl;
					if(fm == 0){
						cout<<"方程的解为："<<mid<<endl; 
						flag = 1;
						break ;
					}
					else if(fm * fl < 0){
						r = mid;
					}
					else{
						l = mid;
					}
				}
				if(!flag){
					//cout<<"方程的解介于："<<l<<" 和 "<<r<<" 之间"<<endl; 
					cout<<"方程的解约为："<<l<<endl; 
				}
			} 
		}		
};

class Game{
	public:
		void guess(){
			cout<<"你想一个介于+-1000的整数，我来猜"<<endl;
			cout<<"(当我的答案大于你的答案时，输入‘>’，小于‘<’，正确‘=’)"<<endl;
			cout<<"开始咯！"<<endl;
			int l = -1001,r = 1001;
			char ch;
			int cnt = 1;
			int mid = 0;
			cout<<"这个数是0吗？"<<endl; 
			while(cin >> ch && ch != '='){
				if(ch == '>'){
					r = mid - 1;
				} 
				else{
					l = mid;
				}
				mid = (r + l) / 2;
				//cout<<" mid "<<mid<<endl<<" l "<<l<<endl<<" r "<<r<<endl;
				cout<<"那…是"<<mid<<"吗？"<<endl;
				cnt++; 
			}
			cout<<"哈哈！经过"<<cnt<<"次猜测，果然答案就是"<<mid<<"!"<<endl; 
		} 
};

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{	
	string op;
    cout << "请输入要进行的操作：" << endl;
    cout << "输入'fibonacci'以计算斐波那契数列 " << endl;
    cout << "输入'functoin'以求解方程 " << endl;
    cout << "输入'game'开始猜数游戏 " << endl;
    cout << "输入'end'以结束 " << endl;
    while (cin >> op) {
        if (op == "end") {
            break;
        }
        else if (op == "fibonacci") {
            Fbi(); 
        }
        else if (op == "function") {
            Fun fun;
            fun.slove();
        }
        else if (op == "game") {
            Game game;
            game.guess();
        }
        else {
            cout << "指令错误！" << endl;
        }
        cout << "请输入要进行的操作：" << endl;
    }
	system("pause");
	return 0;
}
