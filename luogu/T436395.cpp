#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main(){
//	freopen("mod4.in","r",stdin);
//	freopen("mod.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		/*int minx=INT_MAX,maxx=0;
		for(int i=1;i<=n;i++){
		minx=min(minx,a[i]);
		maxx=max(maxx,a[i]);
		}*/
		sort(a+1,a+n+1);
		//cout<<a[n]<<' '<<a[1]<<endl;
		ll minx;
		bool f=0;
		for(int i=n-1;i>=1;i--){
			if(a[i]!=a[n]){
				f=1;
				minx=a[i];
			}
		}
		if(f)cout<<max(a[n]-a[1],minx)<<endl;
		else cout<<"0\n";
		//cout<<endl;
	}
	return 0;
}
