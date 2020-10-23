#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << " " << a << endl
using namespace std;
typedef long long ll;
const double pi=acos(-1);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int maxn = 100007;//1e5+7 
const ll mod = 1000000007;//1e9+7

double a[maxn];

double Area(double a,double b,double c)
{
    if (a >= b + c) {
        return 0;
    }
    double p = (a + b + c) * 1.0 / 2;
    double ar = sqrt(p * (p - a) * (p - b) * (p - c));
    return ar;
}


bool cmp(double a,double b)
{
	return a > b;
}

int main()
{	
	int m;
	scanf("m  = %d",&m);
	getchar();
	scanf("L  = ");
	for(int i = 1;i<=m;i++){
		cin>>a[i];
	}
/*	for(int i = 1;i<=m;i++){
		cout<<a[i]<<" \n"[i == m];
	}*/
	sort(a+1,a+m+1,cmp);
	int posc = -1,poss = -1;
	double mxs = 0,mxc = 0;
	for(int i = 1;i+2<=m;i++){
		if(a[i] < (a[i+1] + a[i+2])){
			posc = i;
			mxc = a[i] +a[i+1] + a[i+2];
			break;
		}
	} 
	if(posc != -1){
		for(int i = 2;i+1<=m;i++){
			double areaa = Area(a[i-1],a[i],a[i+1]);
			if(areaa > 0){
				if(areaa > mxs){
					mxs = areaa;
					poss = i;
				}
			}
		}		
		cout<<"最大周长："<< mxc<<" 选择（ "<<a[posc]<<" "<<a[posc+1]<<" "<<a[posc+2]<<" ）"<<endl; 
		cout<<"最大面积："<< mxs<<" 选择（ "<<a[poss-1]<<" "<<a[poss]<<" "<<a[poss+1]<<" ）"<<endl; 		
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
