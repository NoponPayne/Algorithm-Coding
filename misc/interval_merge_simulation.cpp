#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
//	freopen("stair.in","r",stdin);
//	freopen("stair.out","w",stdout);
	cin>>n;
	int u,v,last=0,maxx;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>u>>v;
		if(f){
			if(i!=1){
				if(u>last){
					maxx=last;
					f=0;
				}
			}
			if(u<=last)last+=v;
		}
		//cout<<i<<' '<<last<<endl;
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>u;
		if(u<=maxx){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
