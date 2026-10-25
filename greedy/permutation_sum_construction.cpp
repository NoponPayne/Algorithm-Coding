#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int l,r;
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		l+=i;
		r+=max(n-i+1,i);
	}
	if(k<l){
		cout<<-1<<endl;
		return 0;
	}
	if(k>=r){
		cout<<r<<endl;
		for(int i=1;i<=n;i++){
			cout<<i<<' ';
		}
		cout<<endl;
		for(int i=n;i>=1;i--){
			cout<<i<<' ';
		}
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	for(int i=1;i<=n;i++){
		b[i]=n-i+1;	
	}
	int i=1,j=n,sum=l;
	for(int t=1;t<=n;t++){
		if(j>=a[t]&&sum+j-a[t]<=k){
			sum+=j-a[t];
			b[t]=j--;
		}else{
			b[t]=i++;
		}
	}
	cout<<k<<endl;
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	cout<<endl;
	return 0;
}
