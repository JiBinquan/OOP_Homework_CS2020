/*************************************************
** 功能 : OOP实验二
** 作者 : 2019Jibinquan
** 创建 :
** 版权 : 431263064@qq.com
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
    cout<<"请输入需要求解的二次方程："<<endl;
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
    cout<<"请输入三角形的三边长度："<<endl;
    cin>>a>>b>>c;
    sort3(a,b,c);
    if(a+b <= c){
        cout<<"输入的三边无法构成三角形！"<<endl;
        return ;
    }
    double p = (a+b+c) * 1.0 / 2;
    double ar = sqrt(p * (p - a) * (p - b) * (p - c));
    cout<<"当前三角形面积为："<<ar<<endl;
}

void getday()
{
    int yy,mm,dd;
    cout<<"请输入年、月、日，格式如：2019-9-17"<<endl;
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
