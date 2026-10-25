#include<bits/stdc++.h>
using namespace std;
int n;
const double eps=1e-9;
double l,r,a[114514],b[114514],c[114514];
double lmid,rmid;
double f(double x){
	double maxn=INT_MIN;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]*x*x+b[i]*x+c[i]);
	}
	return maxn;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		l=0;r=1000;
		while(r-l>eps){
			lmid=(2*l+r)/3;
			rmid=(l+2*r)/3;
			if(f(lmid)<f(rmid)){
				r=rmid;
			}else{
				l=lmid;
			}
		}
		cout<<fixed<<setprecision(4)<<f(l)<<endl;
	}
	return 0;
}

