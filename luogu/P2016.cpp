#include<bits/stdc++.h>
using namespace std;
int to[3010],nex[3010],head[1505];
int cnt;
int n;
int f[1505][2];
void func(int u,int fa){
	f[u][1]=1;
	f[u][0]=0;
	for(int i=head[u];i;i=nex[i]){
		if(to[i]==fa)continue;
		func(to[i],u);
		f[u][0]+=f[to[i]][1];
		f[u][1]+=min(f[to[i]][1],f[to[i]][0]);
	}
	return;
}
int main(){
	cin>>n;
	int t,opt,x;
	for(int i=1;i<=n;i++){
		cin>>t>>opt;
		for(int j=1;j<=opt;j++){
			cin>>x;
			to[++cnt]=x;
			nex[cnt]=head[t];
			head[t]=cnt;
			to[++cnt]=t;
			nex[cnt]=head[x];
			head[x]=cnt;
		}
	}
	func(0,-1);
	cout<<min(f[0][0],f[0][1])<<endl;
	return 0;
}
