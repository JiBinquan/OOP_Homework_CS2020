/*************************************************
** ���� : ������ ��Ĺ���ͱ���ʵ��
** ���� : 2019Jibinquan
** ���� : 2020-11-17 / 19:28
** ��Ȩ : 431263064@qq.com
/**************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
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

class Graduate
{
private:
	string name;
	bool gender;
	int id;
	double score;
	string research;
	string tutor;
	static const string university;
	static double average;
	static int count;

public:
	Graduate() {
		cout << "������ѧ��������" << endl;
		cin >> name;
		cout << "������ѧ��ѧ�ţ�" << endl;
		cin >> id;
		cout << "������ѧ���Ա�0Ϊ�У�1ΪŮ" << endl;
		cin >> gender;
		cout << "������ѧ����ѧ�ɼ�" << endl;
		cin >> score;
		cout << "�������о�����" << endl;
		cin >> research;
		cout << "������ָ����ʦ" << endl;
		cin >> tutor;
		double sum = average * count + score;
		count++;
		average = sum / count;
	}
	Graduate(string na, bool sex, int ide, double sco, string resa, string tut) {
		name = na;
		gender = sex;
		id = ide;
		score = sco;
		research = resa;
		tutor = tut;
		double sum = average * count + score;
		count++;
		average = sum / count;
	}
	Graduate(const Graduate& G) {
		name = G.name;
		gender = G.gender;
		id = G.id;
		score = G.score;
		research = G.research;
		tutor = G.tutor;
		double sum = average * count + score;
		count++;
		average = sum / count;
	}
	~Graduate() {}


	void show() const {
		cout << "ѧ��������" << name << endl;
		cout << "ѧ��ѧ�ţ�" << id << endl;
		cout << "ѧ���Ա�: " << (gender ? "Ů" : "��") << endl;
		cout << "ѧ����ѧ�ɼ�: " << score << endl;
		cout << "�о�����: " << research << endl;
		cout << "ָ����ʦ: " << tutor << endl;
		cout << "�Ͷ�ѧУ��" << university << endl;
		cout << endl;
	}
	void show() {
		const Graduate G(*this);
		G.show();
	}
	string getName()const {
		return name;
	}
	static const double ShowAverage() {
		return average;
	}
	friend char level(const Graduate);
};

char level(const Graduate G) {
	if (G.score >= 90) {
		return 'A';
	}
	else if (G.score >= 80) {
		return 'B';
	}
	else if (G.score >= 70) {
		return 'C';
	}
	else if (G.score >= 60) {
		return 'D';
	}
	else {
		return 'E';
	}
}

int Graduate::count = 0;
double Graduate::average = 0;
const string Graduate::university = "ɽ��ʦ����ѧ";

/*----------------------------------*
		  Main Function
*-----------------------------------*/

Graduate Gs[2] = { {"Liu",0,1,96.00,"CS","Ma"} };

int main()
{
	Graduate Zhang("Zhang", 1, 2, 85.50, "Chemistry", "Zhao");
	const Graduate Wang("Wang", 0, 3, 68.00, "Politics", "Li");
	cout << endl;
	Gs[0].show();
	Gs[1].show();
	Zhang.show();
	Wang.show();
	cout << "ƽ���ɼ���" << Graduate::ShowAverage() << endl;
	cout << "��ѧ���ɼ��ȼ���" << endl;
	cout << " " << Gs[0].getName() << "��" << level(Gs[0]) << endl;
	cout << " " << Gs[1].getName() << "��" << level(Gs[1]) << endl;
	cout << " " << Zhang.getName() << "��" << level(Zhang) << endl;
	cout << " " << Wang.getName() << "��" << level(Wang) << endl;
	system("pause");

	return 0;
}
