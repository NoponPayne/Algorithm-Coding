#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;
int t,c,n,m,fa[N],siz[N],mp[N];
int find(int x) {
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void Union(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fy]=fx,siz[fx]+=siz[fy];
}
bool dfs(int x,int root,int flag) {
	if(mp[x]/2==root) return flag^(mp[x]&1);
	return dfs(mp[x]/2,root,flag^(mp[x]&1));
}
int opp(int x){
	if(x==-1) return -2;
	if(x==-2) return -1;
	if(x==-3) return -3;
	return x^1;
}
int main() {
	scanf("%d%d",&c,&t);
	while(t--) {
		int ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)mp[i]=i*2,fa[i]=i,siz[i]=1;
		for(int i=1;i<=m;i++){
			char opt;
			int x,y;
			scanf(" %c",&opt);
			if(opt=='+') {
				scanf("%d%d",&x,&y);
				mp[x]=mp[y];
			}
			else if(opt=='-') {
				scanf("%d%d",&x,&y);
				mp[x]=opp(mp[y]);
			}
			else if(opt=='T') scanf("%d",&x),mp[x]=-1;
			else if(opt=='F') scanf("%d",&x),mp[x]=-2;
			else scanf("%d",&x),mp[x]=-3;
		}
		for(int i=1;i<=n;i++)if(mp[i]>0) Union(mp[i]/2,i);
		for(int i=1;i<=n;i++){
			if(i==find(i)&&(mp[i]==-3||(mp[i]>0&&dfs(i,i,0)))){
				ans+=siz[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

