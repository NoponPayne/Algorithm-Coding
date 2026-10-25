#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1,tot=0;
	for(int i=1;i<=n;i++){
		tot+=a[i];
		if(tot>m){
			ans++;
			tot=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
