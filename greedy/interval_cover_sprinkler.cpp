#include<bits/stdc++.h>
using namespace std;
int n,l,w;
struct wow{
	double l,rgt;
	int r,pos;
}a[15005];
double getlft(int x){double xx=((double)((double)w/2))*((double)((double)w/2));double yy=((double)(a[x].r))*((double)(a[x].r));return (double)((double)a[x].pos-(double)sqrt(yy-xx));}
double getrgt(int x){double xx=((double)((double)w/2))*((double)((double)w/2));double yy=((double)(a[x].r))*((double)(a[x].r));return (double)((double)a[x].pos+(double)sqrt(yy-xx));}
bool cmp(wow x,wow y){
	return x.l<y.l;
}
int ans;
int main(){
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>l>>w;
		for(int i=1;i<=n;i++){
			cin>>a[i].pos>>a[i].r;
			if(double(a[i].r)<=double(w/2)){
				i--;
				n--;
				continue;
			}
			a[i].l=getlft(i);
			a[i].rgt=getrgt(i);
		}
		sort(a+1,a+n+1,cmp);
		if(a[1].l>0){
			cout<<-1<<endl;
			continue;
		}
		double tmp=0;
		while(tmp<l){
			double now=0;
			for(int i=1;i<=n&&a[i].l<=tmp;i++){
				if(a[i].rgt-tmp>now)now=a[i].rgt-tmp;
			}
			if(now!=0){
				ans++;
				tmp+=now;
			}else{
				break;
			}
		}
		if(tmp<w){
			cout<<-1<<endl;
			continue;
		}else{
			cout<<ans<<endl;
		}
	}
	return 0;
}
