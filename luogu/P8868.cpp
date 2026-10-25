#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	int l,id;
};
const int N=3005;
vector<Node>d[N];
ll a[N],b[N];
ll f[N],x[N],y[N];
ll ans[N];
int main(){
	int n,q;
	scanf("%*d%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);	
		d[r].push_back({l,i});
	}
	for(int r=1;r<=n;r++){
		for(int i=1;i<=r;i++){
			x[i]=max(x[i],a[r]);
			y[i]=max(y[i],b[r]);
			f[i]+=x[i]*y[i];
		}
		for(auto [l,id]:d[r]){
			for(int i=l;i<=r;i++){
				ans[id]+=f[i];
			}
		}
	}
	for(int i=1;i<=q;i++)printf("%ll\n", ans[i]);
	return 0;
}
