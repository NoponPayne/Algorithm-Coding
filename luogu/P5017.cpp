// Luogu P5017 Question Solvement
#include<bits/stdc++.h>
using namespace std;
int gap[505];
int a[505];
int dp[505][105][505];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		gap[i]=a[i+1]-a[i];
	}
	for(int j=0;j<=m;j++){
		for(int k=n;k>=1;k--){
			dp[n][j][k]=j*k;
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int k=i;k>=1;k--){
			for(int j=0;j<=m;j++){
				if(j>=gap[i])dp[i][j][k]=dp[i+1][j-gap[i]][k+1]+k*gap[i];
				else dp[i][j][k]=min(dp[i+1][0][k+1]+k*gap[i],dp[i+1][max(0,j+m-gap[i])][1]+k*j);
			}
		}
	}
	printf("%d\n",dp[1][0][1]);
	return 0;
}
