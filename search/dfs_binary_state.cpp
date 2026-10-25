#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
long long vis[2030];
void fun(int dep,int sum){
	if(dep>2026)return;
	if(vis[dep])return;
	vis[dep]=sum;
	if(sum%7==0)ans++;
	fun(dep*2,sum*3);
	fun(dep*2+1,sum*3+1);
	return;
}
int main(){
	//cin>>n;
	fun(1,1);
	cout<<ans<<endl;
	return 0;
}
