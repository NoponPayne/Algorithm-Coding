// Luogu Question P2668 solvement
#include<bits/stdc++.h>
using namespace std;
int a[25];
int ans=0x7fffffff;
void solve(int dep){
	if(dep>=ans)return;
	//simplefive
	int k=0;
	for(int i=1;i<=12;i++){
		if(a[i]==0)k=0;
		else{
			k++;
			if(k>=5){
				for(int j=i;j>=i-k+1;j--)a[j]--;
				solve(dep+1);
				for(int j=i;j>=i-k+1;j--)a[j]++;
			}
		}
	}
	//double*3
	k=0;
	for(int i=1;i<=12;i++){
		if(a[i]<=1)k=0;
		else{
			k++;
			if(k>=3){
				for(int j=i;j>=i-k+1;j--)a[j]-=2;
				solve(dep+1);
				for(int j=i;j>=i-k+1;j--)a[j]+=2;
			}
		}
	}
	//thirdthird
	k=0;
	for(int i=1;i<=12;i++){
		if(a[i]<=2)k=0;
		else{
			k++;
			if(k>=2){
				for(int j=i;j>=i-k+1;j--)a[j]-=3;
				solve(dep+1);
				for(int j=i;j>=i-k+1;j--)a[j]+=3;
			}
		}
	}
	//four+two
	for(int i=1;i<=13;i++){
		if(a[i]<4)continue;
		a[i]-=4;
		//4 1 1
		for(int j=1;j<=14;j++){
			if(a[j]==0||j==i)continue;
			a[j]--;
			for(int t=j;t<=14;t++){
				if(a[t]==0||t==i)continue;
				a[t]--;
				solve(dep+1);
				a[t]++;
			}
			a[j]++;
		}
		//4 2 2
		for(int j=1;j<=13;j++){
			if(a[j]<2||j==i)continue;
			a[j]-=2;
			for(int t=j;t<=13;t++){
				if(a[t]<2||t==i)continue;
				a[t]-=2;
				solve(dep+1);
				a[t]+=2;
			}
			a[j]+=2;
		}
		a[i]+=4;
	}
	//three+two/one
	for(int i=1;i<=13;i++){
		if(a[i]<3)continue;
		for(int j=1;j<=14;j++){
			if(a[j]==0||j==i)continue;
			a[i]-=3;
			a[j]--;
			solve(dep+1);
			a[i]+=3;
			a[j]++;
			if(a[j]>=2&&j<=13){
				a[i]-=3;
				a[j]-=2;
				solve(dep+1);
				a[i]+=3;
				a[j]+=2;
			} 
		}
	}
	for(int i=1;i<=14;i++){
		if(a[i]!=0){
			dep++;
		}
	}
	ans=min(ans,dep);
	return;
}
int main(){
	int T,n,x,y;
	cin>>T>>n;
	while(T--){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>x>>y;
			if(x==0){
				a[14]++;
			}else{
				if(x>=3&&x<=13)a[x-2]++;
				else if(x==1)a[12]++;
				else a[13]++;
			}
		}
		solve(0);
		cout<<ans<<endl;
		ans=0x7fffffff;
	}
	return 0;
}
