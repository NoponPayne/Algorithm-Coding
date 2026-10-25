#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,L,a[N],post[N],idx;
vector<int>f;
void dfs(int u){
	if(u>n)return;
	dfs(u<<1);
	dfs(u<<1|1);
	post[++idx]=a[u];
}
int main(){
	cin>>L;
	n=(1<<L)-1;
	for (int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	for(int i=1;i<=n;i++){
		auto it=upper_bound(f.begin(),f.end(),post[i]);
		if (it==f.end())f.push_back(post[i]);
		else *it=post[i];
	}
	cout<<n-f.size()<<endl;
	return 0;
}
