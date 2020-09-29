/*************************************************
** ���� : OOPʵ��һ��ѧ���ɼ���ѯϵͳ
** ���� : 2019Jibinquan
** ���� : 2020-9-22 / 19:16
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
	cout << "������Ϣ��" << endl;
	cout << "ƽ���ɼ���" << ave << endl;
	cout << "���" << var << endl;
	cout << "˳������ѧ����Ϣ��" << endl;
	for (int i = 1; i <= len; i++) {
		cout << "������" << lis[i].ranks << " ѧ�ţ�" << lis[i].Snum << " ������" << lis[i].Sname << " ƽʱ�ɼ���" << lis[i].peace << " ʵ��ɼ���" << lis[i].experiment << " ��ĩ�ɼ���" << lis[i].eot << " �ܳɼ���" << lis[i].sum << endl;
	}
}

void query()
{
	string nm;
	cout << "������Ҫ��ѯͬѧ��ѧ��" << endl;
	cin >> nm;
	if (mp.count(nm)) {
		cout << "ѧ�������� " << mp[nm].Sname << endl;
		cout << "ƽʱ�ɼ��� " << mp[nm].peace << endl;
		cout << "ʵ��ɼ��� " << mp[nm].experiment << endl;
		cout << "��ĩ�ɼ��� " << mp[nm].eot << endl;
		cout << "�ܳɼ��� " << mp[nm].sum << endl;
		cout << "������ " << mp[nm].ranks << endl;
	}
	else {
		cout << "ѧ�������ڣ�" << endl;
	}
}

/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{

	cout<<"******************************\n";
	cout<<"       ѧ���ɼ��������ϵͳ        \n";
	cout<<"         Binquan Ji            \n";
	cout<<"******************************\n\n";
	readDataFromFile();
	
	cout << "����\"print\"���ȫ��ѧ����Ϣ" << endl;
	cout << "����\"query\"�Բ�ѯ����ѧ����ϸ��Ϣ" << endl;
	cout << "����\"end\"�Խ���" << endl;
	cout << endl;
	cout << "�����������Ҫ���еĲ�����" << endl;
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
			cout << "ָ�����" << endl;
		}
	}
	system("pause");
	return 0;
}

