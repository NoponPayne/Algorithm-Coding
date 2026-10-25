#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
unordered_map<long long,vector<long long> >mp;
int main(){
	ios::sync_with_stdio(0);
	int T,n,ans=0;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]+=a[i-1];
		}
		for(int i=1;i<=n;i++){
			mp[a[i]].push_back(i);	
		}
		for(auto i:mp){
			if(i.first!=0) ans=max(ans,int(i.second.size())-1);
			else ans=max(ans,int(i.second.size()));
		}
		cout<<ans<<endl;
		mp.clear();
		ans=0;
	}
	return 0;
}
