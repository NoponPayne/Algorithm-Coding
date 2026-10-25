#include<bits/stdc++.h>
using namespace std;
bool a[405][405];
int n,m;
int vis[405];
bool check(int u,int v){
	queue<int>q;
	q.push(u);
	memset(vis,0,sizeof(vis));
	int tmp;
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		vis[tmp]=1;
		if(tmp==v)return true;
		for(int i=1;i<=n;i++){
			if(a[tmp][i]&&(!vis[i])){
				q.push(i);
			}	
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	string s;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>s>>u>>v;
		if(s=="add"){
			a[u][v]=1;
			a[v][u]=1;
		}else if(s=="ask"){
			if(check(u,v))cout<<"1\n";
			else cout<<"0\n";
		}else{
			a[u][v]=0;
			a[v][u]=0;
		}
	}
	return 0;
}
