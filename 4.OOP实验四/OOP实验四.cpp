/*************************************************
** ���� : OOP�γ��ϻ�ʵ��Σ���4��ʵ��
** ���� : 2019Jibinquan
** ���� : 2020-10-20 / 19:01
** ��Ȩ : 431263064@qq.com
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

Linklist initList() //��ʼ������ 
{
	Linklist L = new LNode;
	L->data = 0;
	L->next = NULL;
	L->pre = NULL;
	return L;
}


void insert_back(Linklist& L, int e) //β�巨����Ԫ�� 
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

void distorylist(Linklist& L)//��������
{
	LNode* p = L;
	while (p->next != NULL) {
		LNode* s = p;
		p = p->next;
		delete s;
	}
	delete p;
}

void Fbi()//쳲�������ѯ
{
	int n;
	Linklist L = initList();
	insert_back(L, 1);
	insert_back(L, 1);
	cout << "������Ҫ��ѯ��λ��������0������" << endl;
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
		cout << "������Ҫ��ѯ��λ��������0������" << endl;
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
			cout<<"�����뷽��ax + b = 0�Ĳ���a��b"<<endl;
			cin>>a>>b;
			if(f(l) == 0){
				cout<<"���̵Ľ�Ϊ��"<<l<<endl; 
			}
			else if(f(r) == 0){
				cout<<"���̵Ľ�Ϊ��"<<r<<endl; 
			}
			else if(f(l) * f(r) > 0){
				cout<<"������+-100000.00��û��ʵ����"<<endl;
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
						cout<<"���̵Ľ�Ϊ��"<<mid<<endl; 
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
					//cout<<"���̵Ľ���ڣ�"<<l<<" �� "<<r<<" ֮��"<<endl; 
					cout<<"���̵Ľ�ԼΪ��"<<l<<endl; 
				}
			} 
		}		
};

class Game{
	public:
		void guess(){
			cout<<"����һ������+-1000��������������"<<endl;
			cout<<"(���ҵĴ𰸴�����Ĵ�ʱ�����롮>����С�ڡ�<������ȷ��=��)"<<endl;
			cout<<"��ʼ����"<<endl;
			int l = -1001,r = 1001;
			char ch;
			int cnt = 1;
			int mid = 0;
			cout<<"�������0��"<<endl; 
			while(cin >> ch && ch != '='){
				if(ch == '>'){
					r = mid - 1;
				} 
				else{
					l = mid;
				}
				mid = (r + l) / 2;
				//cout<<" mid "<<mid<<endl<<" l "<<l<<endl<<" r "<<r<<endl;
				cout<<"�ǡ���"<<mid<<"��"<<endl;
				cnt++; 
			}
			cout<<"����������"<<cnt<<"�β²⣬��Ȼ�𰸾���"<<mid<<"!"<<endl; 
		} 
};

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{	
	string op;
    cout << "������Ҫ���еĲ�����" << endl;
    cout << "����'fibonacci'�Լ���쳲��������� " << endl;
    cout << "����'functoin'����ⷽ�� " << endl;
    cout << "����'game'��ʼ������Ϸ " << endl;
    cout << "����'end'�Խ��� " << endl;
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
            cout << "ָ�����" << endl;
        }
        cout << "������Ҫ���еĲ�����" << endl;
    }
	system("pause");
	return 0;
}
