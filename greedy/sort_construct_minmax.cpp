#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long minx=a[1]*a[2]+1;
	for(int i=3;i<=n;i++){
		minx*=a[i];
		minx++;
	}
	long long maxx=a[n]*a[n-1]+1;
	for(int i=n-2;i>=1;i--){
		maxx*=a[i];
		maxx++;
	}
	cout<<minx-maxx<<endl;
	return 0;
}
