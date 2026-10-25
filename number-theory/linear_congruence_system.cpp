#include<bits/stdc++.h>
using namespace std;
struct pig{
	int a1,b1;
}a[15];
int gcd(int x,int y){
	if(x%y==0) return y;
	else return gcd(y,x%y);
}
int main(){
	long long n,ans,sum=1;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].a1>>a[i].b1;
	}
	ans=a[1].b1;
	for(int i=1;i<n;++i){
		sum=sum*a[i].a1/gcd(sum,a[i].a1);
		while(ans%a[i+1].a1!=a[i+1].b1){
			ans+=sum;
		}
	}
	cout<<ans<<endl;
	return 0;
}


