#include<bits/stdc++.h>
using namespace std;
int n;
int p[500005];
vector<pair<int,int> >a[1000005];
int sum[500005];
int ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		sum[i]=(p[i]==i);
		sum[i]+=sum[i-1];
		a[i+p[i]].push_back({min(i,p[i]),max(i,p[i])});
	}
	for(int i=1;i<=(n<<1);i++){
		if(a[i].empty())continue;
		sort(a[i].begin(),a[i].end());
		reverse(a[i].begin(),a[i].end());
		int cnt=0;
		for(auto t:a[i]){
			cnt++;
			ans=max(ans,cnt-(sum[t.second]-sum[t.first-1]));
		}
	}
	cout<<ans<<endl;
	return 0;
}
