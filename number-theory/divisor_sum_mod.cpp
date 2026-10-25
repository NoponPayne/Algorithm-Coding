#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=9901;
int n,m=1; 
int a,b; 
int kuai(int a,int b){
	int ans=1; 
	while(b){
		if(b&1)ans=(ans*a)%mod; 
		a=(a*a)%mod; 
		b>>=1; 
	}
	return ans; 
}
int deng(int x,int n){
	return (kuai(x,n+1)-1)*kuai(x-1,mod-2)%mod; 
}
signed main(){
	cin>>a;
	cin>>b;
	int k;
	for(int i=2;i<=a;i++){
		if(a%i==0){
			k=0; 
			while(a%i==0){
				a/=i;
				k++;
			}
			m*=deng(i,k*b); 
			m%=mod; 
		}
	}
	printf("%lld",(m%mod+mod)%mod); 
	return 0;
}
