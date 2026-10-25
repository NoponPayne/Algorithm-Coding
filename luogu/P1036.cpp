#include<bits/stdc++.h>
using namespace std;
//bool a[100000005];
int l[25];
int n,k,ans;
bool check(int x){
	if(x==1)return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
void func(int dep,int now,int cnt){
	if(cnt==k){
//		cout<<now<<endl;
		if(check(now))ans++;
		return;
	}
	for(int i=dep+1;i<=n;i++){
		func(i,now+l[i],cnt+1);
	}
	return;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	func(0,0,0);
	cout<<ans<<endl;
	return 0;
} 
