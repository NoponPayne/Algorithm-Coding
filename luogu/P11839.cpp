#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005];
struct node{
	int x,y;	
}val[200005];
bool cmp(node &x,node &y){
	if(x.x!=y.x)return x.x>y.x;
	else return x.y<y.y;
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			val[i].x=a[i];
			val[i].y=i;
		}
		int ma=0,ma2=0,moved=0;
		sort(val+1,val+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(val[i].y>ma){
				ma2=ma;				
				ma=val[i].y;
				cout<<val[i].x<<' ';
			}else if(val[i].y>ma2&&!moved){
				ma=val[i].y;
				cout<<val[i].x<<' ';
				moved=1;
			}
		}
		cout<<endl;
	}
	return 0;
}


