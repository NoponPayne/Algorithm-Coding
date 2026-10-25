#include<bits/stdc++.h>
using namespace std;
#define int long long
long long a[100005];
int id[100005];
int st[1005],ed[1005];
long long t[1005],sum[1005];
int n,num;
int block_size;
void modify(int l,int r,int x){
	int ld=id[l],rd=id[r];
	if(ld==rd){
		for(int i=l;i<=r;i++){
			a[i]+=x;
			sum[ld]+=x;
		}
		return;
	}
	for(int i=l;i<=ed[ld];i++){a[i]+=x;sum[ld]+=x;}
	for(int i=st[rd];i<=r;i++){a[i]+=x;sum[rd]+=x;}
	for(int i=ld+1;i<rd;i++){
		t[i]+=x;
		sum[i]+=x*(ed[i]-st[i]+1);
	}
	return;
}
long long answer(int l,int r){
	long long ans=0;
	int ld=id[l],rd=id[r];
	if(ld==rd){
		for(int i=l;i<=r;i++){
			ans+=a[i]+t[ld];
		}
		return ans;
	}
	for(int i=l;i<=ed[ld];i++){
		ans+=a[i]+t[ld];
	}
	for(int i=st[rd];i<=r;i++){
		ans+=a[i]+t[rd];
	}
	for(int i=ld+1;i<rd;i++)ans+=sum[i];
	return ans;
}
int m;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	block_size=sqrt(n);
	num=(n+block_size-1)/block_size;
	for(int i=1;i<=num;i++){
		st[i]=(i-1)*block_size+1;
		ed[i]=min(i*block_size,n);
		for(int j=st[i];j<=ed[i];j++){
			id[j]=i;
			sum[i]+=a[j];
//			cout<<j<<' '<<i<<endl;
		}
	}
	int opt,l,r;
	long long c;
	for(int i=1;i<=m;i++){
		cin>>opt;
		if(opt==1){
			cin>>l>>r>>c;
			modify(l,r,c);
		}else{
			cin>>l>>r;
			cout<<answer(l,r)<<endl;
		}	
	}
	return 0;
}
