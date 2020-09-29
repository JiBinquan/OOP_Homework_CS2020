/*************************************************
** 功能 : OOP实验一：学生成绩查询系统
** 作者 : 2019Jibinquan
** 创建 : 2020-9-22 / 19:16
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

struct stu {
	string Snum;
	string Sname;
	int peace;
	int experiment;
	int eot;
	int sum;
	int ranks;
};

int len,allsum,var,ave;
stu lis[maxn];
map<string, stu>mp;
string tpxh, tpxm;

bool cmp(stu a, stu b)
{
	return a.sum > b.sum;
}

void readDataFromFile()
{
	allsum = 0;
	ifstream in("data.txt");
	in >> len;
	//while (in >> tpxh >> tpxm >> c1 >> c2 >> c3) {
	for (int i = 1,c1,c2,c3; i <= len; i++) {
		in >> tpxh >> tpxm >> c1 >> c2 >> c3;
		stu tmp;
		tmp.Snum = tpxh;
		tmp.Sname = tpxm;
		tmp.peace = c1;
		tmp.experiment = c2;
		tmp.eot = c3;
		tmp.sum = c1 + c2 + c3;
		lis[i] = tmp;
		allsum += lis[i].sum;
	}
	ave = allsum / len;
	for (int i = 1; i <= len; i++) {
		lis[i].ranks = i;
		mp[lis[i].Snum] = lis[i];
		var += (lis[i].sum - ave) * (lis[i].sum - ave);
	}
}

void sortScore()
{
	sort(lis + 1, lis + 1 + len, cmp);
}

void printOut()
{
	sortScore();
	cout << "总体信息：" << endl;
	cout << "平均成绩：" << ave << endl;
	cout << "方差：" << var << endl;
	cout << "顺序排序学生信息：" << endl;
	for (int i = 1; i <= len; i++) {
		cout << "排名：" << lis[i].ranks << " 学号：" << lis[i].Snum << " 姓名：" << lis[i].Sname << " 平时成绩：" << lis[i].peace << " 实验成绩：" << lis[i].experiment << " 期末成绩：" << lis[i].eot << " 总成绩：" << lis[i].sum << endl;
	}
}

void query()
{
	string nm;
	cout << "请输入要查询同学的学号" << endl;
	cin >> nm;
	if (mp.count(nm)) {
		cout << "学生姓名： " << mp[nm].Sname << endl;
		cout << "平时成绩： " << mp[nm].peace << endl;
		cout << "实验成绩： " << mp[nm].experiment << endl;
		cout << "期末成绩： " << mp[nm].eot << endl;
		cout << "总成绩： " << mp[nm].sum << endl;
		cout << "排名： " << mp[nm].ranks << endl;
	}
	else {
		cout << "学生不存在！" << endl;
	}
}

/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{

	cout<<"******************************\n";
	cout<<"       学生成绩管理分析系统        \n";
	cout<<"         Binquan Ji            \n";
	cout<<"******************************\n\n";
	readDataFromFile();
	
	cout << "输入\"print\"输出全部学生信息" << endl;
	cout << "输入\"query\"以查询单个学生详细信息" << endl;
	cout << "输入\"end\"以结束" << endl;
	cout << endl;
	cout << "请输入接下来要进行的操作：" << endl;
	string op;
	while (cin >> op) {
		if (op == "print") {
			printOut();
		}
		else if(op == "query"){
			query();
		}
		else if (op == "end") {
			break;
		}
		else {
			cout << "指令错误！" << endl;
		}
	}
	system("pause");
	return 0;
}

