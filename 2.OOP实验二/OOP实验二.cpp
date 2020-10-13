/*************************************************
** ���� : OOPʵ��� 
** ���� : 2019Jibinquan
** ���� : 2020-10-6 / 19:13
** ��Ȩ : 431263064@qq.com
/**************************************************/

#include <iostream>
#include<fstream>
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
const int maxn = 10007;//1e4+7
const ll mod = 1000000007;//1e9+7

/*----------------------------------*
         Class Definition
*-----------------------------------*/



void Slove_fun()
{
    ll a, b, c;
    cout << "��������Ҫ����һԪ���η���ax^2+bx+c=0������ϵ��a��b��c��" << endl;
    cin >> a >> b >> c;
    cout << a << ' ' << b << ' ' << c << endl;
    if (a) {
        double det = ((1.0 * b * b) - (4.0 * a * c));
        cout << det << endl;
        if (det < 0) {
            cout << "�÷�����ʵ����" << endl;
        }
        else if (det == 0) {
            cout << "x1 = x2 = " << ((-1.0 * b + sqrt(det)) / (2.0 * a)) << endl;
        }
        else {
            double ans1 = (-1.0 * b + sqrt(det)) / (2.0 * a);
            double ans2 = (-1.0 * b - sqrt(det)) / (2.0 * a);
            cout << "x1 = " << ans1 << ' ' << "x2 = " << ans2 << endl;
        }
    }
    else {
        cout << "x = " << ((-1.0 * c) / (b * 1.0)) << endl;
    }
}


void swap2(int& a, int& b)
{
    b ^= a;
    a ^= b;
    b ^= a;
}

void sort3(int& a, int& b, int& c)
{
    if (a > b) {
        swap2(a, b);
    }
    if (b > c) {
        swap2(b, c);
    }
    if (a > b) {
        swap2(a, b);
    }
}

void Area()
{
    int a, b, c;
    cout << "�����������ε����߳��ȣ�" << endl;
    cin >> a >> b >> c;
    sort3(a, b, c);
    if (a + b <= c) {
        cout << "����������޷����������Σ�" << endl;
        return;
    }
    double p = (a + b + c) * 1.0 / 2;
    double ar = sqrt(p * (p - a) * (p - b) * (p - c));
    const double* poi = &ar;
    cout << "��ǰ���������Ϊ��" << *poi << endl;
}

int mon[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

void getday()
{
    int yy, mm, dd;
    cout << "�������ꡢ�¡��գ���ʽ�磺2019-9-17" << endl;
    scanf("%d-%d-%d", &yy, &mm, &dd);
    if ((yy % 400 == 0) || (yy % 4 == 0 && yy % 100 != 0)) {
        mon[2] = 29;
    }
    else {
        mon[2] = 28;
    }
    int nwd = 0;
    for (int i = 1; i < mm; i++) {
        nwd += mon[i];
    }
    nwd += dd;
    int nww = nwd / 7 + (nwd % 7 ? 1 : 0);
    cout << "�����ǵ�" << nwd << "�죬��" << nww << "�ܡ�" << endl;
}


/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
    string op;
    cout << "������Ҫ���еĲ�����" << endl;
    cout << "����'area'�Լ������������ " << endl;
    cout << "����'fun'����ⷽ�� " << endl;
    cout << "����'time'�����ʱ������ " << endl;
    cout << "����'end'�Խ��� " << endl;
    while (cin >> op) {
        if (op == "end") {
            break;
        }
        else if (op == "area") {
            Area();
        }
        else if (op == "fun") {
            Slove_fun();
        }
        else if (op == "time") {
            getday();
        }
        else {
            cout << "ָ�����" << endl;
        }
        cout << "������Ҫ���еĲ�����" << endl;
    }

    system("pause");
    return 0;
}

