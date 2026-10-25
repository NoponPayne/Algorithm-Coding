#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p[1000005],dep[1000005];
int cnt[1000005];
vector<int>e[1000005];
void pdfs(int x){
	dep[x]=dep[p[x]]+1;
	if(!cnt[x])m++;
	for(auto i:e[x]){
		pdfs(i);
	}
}
int rdfs(int x){
	if(cnt[x]){
		return dep[x] + 1;
	}
	if(x==0){
		return 0;
	}
	cnt[p[x]]--;
	return rdfs(p[x]);
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		cnt[p[i]]++;
		e[p[i]].push_back(i);
	}
	p[0]=0;
	dep[0]=-1;
	pdfs(0);
	for(int i=1;i<=m;i++){
		int now;
		cin>>now;
		cout<<rdfs(now)<<endl;
	}
	return 0;
}
