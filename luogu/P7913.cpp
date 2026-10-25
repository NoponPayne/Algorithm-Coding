#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct pl{
	int u,v;
}a[100005],b[100005];
int s1[100005],s2[100005];
bool cmp(pl x,pl y){
	return x.u<y.u;
}
struct cmp2{
	bool operator()(pl x,pl y){
		if(x.u==y.u)return x.v>y.v;
		else return x.u>y.u;
	}
};
void calc1(){
	priority_queue<pl,vector<pl>,cmp2>lk;
	priority_queue<int,vector<int>,greater<int> >kx;
	for(int i=1;i<=n;i++){
		kx.push(i);
	}
	for(int i=1;i<=m1;i++){
		while(!lk.empty()&&a[i].u>=lk.top().u){
			kx.push(lk.top().v);
			lk.pop();
		}
		if(kx.empty())continue;
		int res=kx.top();
		kx.pop();
		s1[res]++;
		lk.push({a[i].v,res});
	}
	for(int i=1;i<=n;i++){
		s1[i]+=s1[i-1];
	}
}
void calc2(){
	priority_queue<pl,vector<pl>,cmp2>lk;
	priority_queue<int,vector<int>,greater<int> >kx;
	for(int i=1;i<=n;i++){
		kx.push(i);
	}
	for(int i=1;i<=m2;i++){
		while(!lk.empty()&&b[i].u>=lk.top().u){
			kx.push(lk.top().v);
			lk.pop();
		}
		if(kx.empty())continue;
		int res=kx.top();
		kx.pop();
		s2[res]++;
		lk.push({b[i].v,res});
	}
	for(int i=1;i<=n;i++){
		s2[i]+=s2[i-1];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a[i].u>>a[i].v;
	}
	for(int i=1;i<=m2;i++){
		cin>>b[i].u>>b[i].v;
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	calc1();
	calc2();
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,s1[i]+s2[n-i]);
	}
	cout<<ans<<endl;
	return 0;
}
