#include<bits/stdc++.h>
using namespace std;
const int maxn=6e5+10;
int n;
int a[maxn],c[maxn];
vector<int>edge[maxn];
int cntleaf;bool isleaf[maxn];
void dfs(int u,int fa){
	bool f=0;
	for(int i:edge[u]){
		if(i==fa)continue;
		dfs(i,u);
		f=1;
	}
	if(!f){
		cntleaf++;
		isleaf[u]=1;
	}
	return;
}
stack<int>s;
int ans;
void solve(int u,int fa){
	for(int i=1;i<=c[u];i++)s.push(u);
	if(isleaf[u]){
		if(!s.empty()){
			s.pop();
			ans++;
			while(!s.empty()&&s.top()==u)s.pop();
		}
	}else{
		for(int i:edge[u]){
			if(i==fa)continue;
			solve(i,u);
		}
		while(!s.empty()&&s.top()==u)s.pop();
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=cntleaf;i++)c[a[i]]++;
	solve(1,0);
	cout<<ans<<endl;
	return 0;
}
