#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum;
int a[10005],b[10005];
int main(){
	cin>>n>>m;
	n--;m--;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		sum+=b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum+=min(a[i],b[j]);
		}
	}
	cout<<sum<<endl;
	return 0;
}
