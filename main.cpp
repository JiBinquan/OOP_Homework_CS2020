/*************************************************
** ���� : OOPʵ���
** ���� : 2019Jibinquan
** ���� :
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
/*
void Slove_fun()
{
    cout<<"��������Ҫ���Ķ��η��̣�"<<endl;
    scanf("")
}
*/

void sort3(int &a,int &b,int &c)
{
    if(a>b){
        swap(a,b);
    }
    if(b>c){
        swap(b,c);
    }
    if(a>b){
        swap(a,b);
    }
}

void Area()
{
    int a,b,c;
    cout<<"�����������ε����߳��ȣ�"<<endl;
    cin>>a>>b>>c;
    sort3(a,b,c);
    if(a+b <= c){
        cout<<"����������޷����������Σ�"<<endl;
        return ;
    }
    double p = (a+b+c) * 1.0 / 2;
    double ar = sqrt(p * (p - a) * (p - b) * (p - c));
    cout<<"��ǰ���������Ϊ��"<<ar<<endl;
}

void getday()
{
    int yy,mm,dd;
    cout<<"�������ꡢ�¡��գ���ʽ�磺2019-9-17"<<endl;
    scanf
}


/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{


	system("pause");
	return 0;
}
