#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,ff;
char mp[1005][1005];
typedef long long ll;
int f[1005][1005];
const ll mod=998244353;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T,id;
	cin>>T>>id;
	while(T--){
		cin>>n>>m>>c>>ff;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}	
		}
		for(int i=1;i<=n;i++){
			for(int j=m-1;j>=1;j--){
				if(mp[i][j]=='1')f[i][j]=-1;
				else if(mp[i][j+1]=='0')f[i][j]=f[i][j+1]+1;
			}
		}
		ll ansc=0,ansf=0,tf,tl;
		for(int j=1;j<m;j++){
			tf=0;tl=0;
			for(int i=1;i<=n;i++){
				if(f[i][j]==-1){
					tf=0;tl=0;
					continue;
				}
				ansc+=f[i][j]*tl%mod;ansc%=mod;
				ansf+=tf%mod;ansf%=mod;
				tf+=f[i][j]*tl%mod;tf%=mod;
				tl+=max(0,f[i-1][j]);
			//	cout<<ansc<<' '<<ansf<<' '<<tf<<' '<<tl<<endl;
			}
		}
		cout<<ansc*c%mod<<' '<<ansf*ff%mod<<endl;
		ansc=0;ansf=0;
		memset(f,0,sizeof(f));
	}
	return 0;
}
