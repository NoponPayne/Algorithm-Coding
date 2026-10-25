#include<bits/stdc++.h>
using namespace std;
const int CN = 1e5 + 5;
int ch[CN*30][2],d[CN*30],w[CN* 30],idx,rt,MAXH=30;
void maintain(int u){
	d[u]=0,w[u]=w[ch[u][0]] + w[ch[u][1]];
	if(ch[u][1])d[u]^=(d[ch[u][1]] << 1) | (w[ch[u][1]] & 1);
	if(ch[u][0])d[u]^=d[ch[u][0]] << 1;
	w[u]&=1;
}
void ins(int &u,int x,int dep){
	if(!u)u=++idx;
	if(dep == MAXH) return (void)(w[u] ^= 1);
	if(x & 1) ins(ch[u][1],x >> 1,dep + 1);
	else ins(ch[u][0],x >> 1,dep + 1);
	maintain(u);
}
void add(int u) {
	if(ch[u][1]) add(ch[u][1]); 
	swap(ch[u][0],ch[u][1]);
	maintain(u);
}
int n,a[CN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int i=n-1;i>=0;i--){
		int s=a[i+1];
		while(s--)add(rt);
		ins(rt,a[i+1],1);
		ans^=d[rt];
	}
	printf("%d",ans);
	return 0;
}
