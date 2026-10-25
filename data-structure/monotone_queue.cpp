#include<bits/stdc++.h>
using namespace std;
int a[1000005],q[1000005];
int n,k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int head=1,tail=0;
	for(int i=1;i<=n;i++){
		if(head<=tail&&q[head]<i-k+1)head++;
		while(head<=tail&&a[q[tail]]>a[i])tail--;
		q[++tail]=i;
		if(i>=k)cout<<a[q[head]]<<' ';
	}
	cout<<endl;
	head=1,tail=0;
	for(int i=1;i<=n;i++){
		if(head<=tail&&q[head]<i-k+1)head++;
		while(head<=tail&&a[q[tail]]<a[i])tail--;
		q[++tail]=i;
		if(i>=k)cout<<a[q[head]]<<' ';
	}
	cout<<endl;
	return 0;
}
